/** -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

The above line is usefulin Emacs-like editors
 */

/*
Template for EO objects initialization in EO
============================================
*/

#ifndef _eoJobShopInit_h
#define _eoJobShopInit_h

// include the base definition of eoInit
#include <eoInit.h>
#include <Parser.h>
#include <Timing.h>
#include <Data.h>

/**
 *  Always write a comment in this format before class definition
 *  if you want the class to be documented by Doxygen
 *
 * There is NO ASSUMPTION on the class GenoypeT.
 * In particular, it does not need to derive from EO (e.g. to initialize
 *    atoms of an eoVector you will need an eoInit<AtomType>)
 */
template <class eoJobShop>
class eoJobShopInit: public eoInit<eoJobShop> {
public:
	/// Ctor - no requirement
// START eventually add or modify the anyVariable argument
  eoJobShopInit(std::string filename_)
  //  eoJobShopInit( varType  _anyVariable) : anyVariable(_anyVariable)
// END eventually add or modify the anyVariable argument
  {
	Parser parser = Parser(filename);
	data = parser.data();
	int N = data.getN();
	Timing timer = Timing(data);
	vector<int> order = irange(0,N); 
	timer.timing(& order, & time);
  }


  /** initialize a genotype
   *
   * @param _genotype  generally a genotype that has been default-constructed
   *                   whatever it contains will be lost
   */
  void operator()(eoJobShop & eo)
	Job job = data.getJob(i);
	vector<int> blocs;
	blocs.push_back(0);
	int bloc = 0;
	eoVector<eoVector<int>> j;
	j[i][0] = i;
	j[i][1] = time[i];
	j[i][2] = bloc; 
	eo.putJobShop(i, j)
	
	for (int i =0; i < data.getN(); i++)
	{
		Job job = data.getJob(i);
		eoVector<eoVector<int>> j;
		j[i][0] = i;
		j[i][1] = time[i];
		if (time[i] > 0)
		{
			bloc++;
			blocs.push_back(i)
		}
		j[i][2] = bloc; 
		eo.putJobShop(i, j)
	}
	eo.putBlocs(bloc);
	_genotype.invalidate();	   // IMPORTANT in case the _genotype is old
  }

private:
	Data data ;
	vector<int> time;
};

#endif
