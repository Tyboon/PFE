/** -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

The above line is usefulin Emacs-like editors
 */

/*
Template for evaluator in EO, a functor that computes the fitness of an EO
==========================================================================
*/

#ifndef _eoJobShopEvalFunc_h
#define _eoJobShopEvalFunc_h

// include whatever general include you need
#include <stdexcept>
#include <fstream>

// include the base definition of eoEvalFunc
#include "eoEvalFunc.h"
#include "Data.h"
#include "eoJobShopOpR.h"
#include "eoJobShopObjectiveVector.h"
/**
  Always write a comment in this format before class definition
  if you want the class to be documented by Doxygen
*/
template <class EOT>
class eoJobShopEvalFunc : public eoEvalFunc<EOT>
{
public:

  eoJobShopEvalFunc(Data d)
  {
	data = d;
	evalR.setData(data);
  }
  
  vector<int> tard_early (EOT _eo) 
  {
	  int t = 0;
	  int comp = 0;
	  vector< vector<int> > results;
	  vector<int> res(2, 0);
	  for (int i = 0; i < data.getN(); i++) 
	  {
		vector<int> j = _eo.getJob(i);
		Jobs job = data.getJob(j[0]);
		vector<int> r(2,0);
		r[0] = max(0, job.getAlpha() * (job.getD() - (comp + job.getP() + j[1]))) ; // tardiness
		r[1] = max(0, job.getBeta() * (comp + j[1] - (job.getD() - job.getP()))) ; //earliness
		results.push_back(r);
		comp += j[1] + job.getP();
		res[0] += results[i][0];
		res[1] += results[i][1];
	  }
	  return res;
  }

  /** Actually compute the fitness
   *
   * @param EOT & _eo the EO object to evaluate
   *                  it should stay templatized to be usable
   *                  with any fitness type
   */
  void operator()(EOT & _eo)
  {
	cout<< "enter eval function" <<endl;
    // test for invalid to avoid recomputing fitness of unmodified individuals
    if (_eo.invalid())
      {
	evalR(_eo);
	      	cout<<"before"<<endl;

	eoJobShopObjectiveVector objVec;
	vector<int> res = tard_early(_eo);
	cout<<"afeter"<<endl;
	objVec[0] = res[0];
	objVec[1] = res[1];
	_eo.objectiveVector(objVec);
      }
      cout<<"exit eval counter"<<endl;
  }

private:
	Data data ;
	eoJobShopOpR evalR;
};


#endif
