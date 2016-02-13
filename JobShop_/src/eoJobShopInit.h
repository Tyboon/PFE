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
#include "eoJobShop.h"
#include "Parser.h"
#include "Timing.h"
#include "Data.h"

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
  eoJobShopInit(Data data_)
  //  eoJobShopInit( varType  _anyVariable) : anyVariable(_anyVariable)
// END eventually add or modify the anyVariable argument
  {
	data = data_;
	N = data.getN();
  }


  /** initialize a genotype
   *
   * @param _genotype  generally a genotype that has been default-constructed
   *                   whatever it contains will be lost
   */
  void operator()(eoJobShop & eo)
  {
	Timing<eoJobShop> timer(data);
	vector<int> time;
	  
	vector<int> order ;
	for (int i = 0; i < N; i++)
	{
		order.push_back(i);
	}
	
	random_shuffle ( order.begin(), order.end() );
	for (int i = 0; i < N; i++)
	{
		order.push_back(i);
	}
	timer.timing(order, time);
	
	for (int i = 0; i < N; i++)
	{
		order.push_back(i);
	}
	cout<<endl;
	
	int i =0;
	vector<int> blocs;
	int bloc = 0;
	blocs.push_back(bloc);
	vector<int> j(2,0);
	j[0] = order[i];
	j[1] = (time[i] - data.getJob(order[i]).getP()) ;
	  
	for (i = 0; i < N; i++)
	{
		if (time[i] - data.getJob(order[i]).getP() < data.getJob(order[i]).getR())
			cout<<"probleme "<< data.getJob(order[i]).getR()<<" "<< time[i] <<" "<< data.getJob(order[i]).getP() ;
	}
	  
	eo.addJob(j);
	for (i =1; i < N; i++)
	{
		vector<int> j(2,0);
		j[0] = order[i];
		j[1] = (time[i] - time[i-1] - data.getJob(order[i]).getP()) ;
		if (j[1] > 0)
		{
			bloc++;
			blocs.push_back(i);
		}
		eo.addJob(j);
	}
	eo.putBlock(blocs);
	
	eo.printJob();
	eo.printBlock();
	
	if  (! eo.isValidBlock() )
		cout << "ERROR init block "<< endl;
	eo.invalidate();	   // IMPORTANT in case the _genotype is old
  }

private:
	Data data ;
	int N;
};

#endif
