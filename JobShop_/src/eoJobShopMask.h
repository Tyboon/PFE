/** -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

The above line is usefulin Emacs-like editors
 */

/*
Template for simple quadratic crossover operators
=================================================

Quadratic crossover operators modify the both genotypes
*/

#ifndef eoJobShopMask_H
#define eoJobShopMask_H

#include <eoOp.h>

/**
 *  Always write a comment in this format before class definition
 *  if you want the class to be documented by Doxygen
 *
 * THere is NO ASSUMPTION on the class GenoypeT.
 * In particular, it does not need to derive from EO
 */
template<class EOT>
class eoJobShopMask: public eoQuadOp<EOT>
{
public:
  /**
   * Ctor - no requirement
   */
// START eventually add or modify the anyVariable argument
  eoJobShopMask()
  //  eoJobShopMask( varType  _anyVariable) : anyVariable(_anyVariable)
// END eventually add or modify the anyVariable argument
  {
    // START Code of Ctor of an eoJobShopEvalFunc object
    // END   Code of Ctor of an eoJobShopEvalFunc object
  }

  /// The class name. Used to display statistics
  string className() const { return "eoJobShopMask"; }

  /**
   * eoQuad crossover - _genotype1 and _genotype2 are the (future)
   *       offspring, i.e. _copies_ of the parents, to be modified
   * @param eo1 The first parent
   * @param eo2 The second parent
   */
  bool operator()(EOT & eo1, EOT& eo2)
  { //2points
	cout<<"enter mask"<<endl;
	eo1.printJob();
	eo1.printBlock();
        bool oneAtLeastIsModified(true);
	unsigned int N = eo1.getSize();
	vector<vector<int> > mask = applyMask(eo1, eo2, N);
	
	EOT result = eoJobShop();
	vector<int> blocs;
	blocs.push_back(0);
	result.putMaxD(eo1.getMaxD());
	result.putData(eo1.getData());
	
	for (int i = 0; i < N; i++) 
	{
		vector<int> job = eo1.getJob(mask[i][0]);
		if (job[1] > 0 && i >0)
			blocs.push_back(i);
		result.addJob(job);
	}
	result.putBlock(blocs);
	eo1 = result;
	cout << "exit mask"<<endl;
	eo1.printJob();
	eo1.printBlock();
	return oneAtLeastIsModified;
  }
 /** 
   bool  sortByMask(const vector<int> & m1, const vector<int> & m2) 
  {
	return m1[1] > m2[1];  
  }**/
  
  vector<vector<int> >  applyMask(EOT & eo1, EOT & eo2, int N)
  {
	vector<int> mask1(N,0); // mask 1 et 3 donc grde aussi indice i
	vector<int > mask2(N,0);
	vector<vector<int> > mask3;
	eoUniformGenerator<int> rdm(0,1);
	  
	for (int i = 0; i < N; i++) //init mask1 et mask2
	{
		mask2[i] = rdm();
		mask1[i]= rdm();
		vector<int> tmp(2,0); 
		mask3.push_back(tmp);
	}
	for (int i = 0; i<N; i++)
	{
		int j1 = eo1.getJob(i)[0];
		int j2 = eo2.getJob(i)[0];
		mask3[j1][0] = i;
		mask3[j1][1] += mask1[i];
		mask3[j2][1] += mask2[i];
	}
	std::sort(mask3.begin(), mask3.end(),  sortByMask);  
	return mask3;
  }
  
  
private:
	    struct {
        bool operator()(vector<int> a, vector<int> b)
        {   
            return a[1] > b[1];
        }   
    } sortByMask;
// START Private data of an eoJobShopMask object
  //  varType anyVariable;		   // for example ...
// END   Private data of an eoJobShopMask object
};

#endif
