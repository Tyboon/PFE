/** -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

The above line is useful in Emacs-like editors
 */

/*
Template for simple mutation operators
======================================
*/

#ifndef eoJobShopMutation_H
#define eoJobShopMutation_H


#include <eoOp.h>

/**
 *  Always write a comment in this format before class definition
 *  if you want the class to be documented by Doxygen
 *
 * THere is NO ASSUMPTION on the class GenoypeT.
 * In particular, it does not need to derive from EO
 */
template<class eoJobShop>
class eoJobShopMutation: public eoMonOp<eoJobShop>
{
public:
  /**
   * Ctor - no requirement
   */
// START eventually add or modify the anyVariable argument
  eoJobShopMutation()
  //  eoJobShopMutation( varType  _anyVariable) : anyVariable(_anyVariable)
// END eventually add or modify the anyVariable argument
  {
    // START Code of Ctor of an eoJobShopEvalFunc object
    // END   Code of Ctor of an eoJobShopEvalFunc object
  }

  /// The class name. Used to display statistics
  string className() const { return "eoJobShopMutation"; }

  /**
   * modifies the parent
   * @param _genotype The parent genotype (will be modified)
   */
  bool operator()(eoJobShop & eo)
  {
	bool isModified(true);
	unsigned int N = eo.getSize();
	unsigned int p1, p2; //random int;
	eoUniformGenerator<int> rdm(0,N);
	vector<int> tmp;
	int bloc, beginB, endB;
	
	p1 =  rdm(); // rng.random(N);
	tmp = eo.getJob(p1);
	beginB = eo.getBlock(p1);
	int ind_begin = eo.getIndBlock(beginB);
	endB = beginB+1; 
	int ind_end = eo.getIndBlock(endB) ;
	eoUniformGenerator<int> rdm2(ind_begin, ind_end);
	p2 =  rdm2(); // rng.random(N);
	if (p1 != p2)
	{
		// vérifie et corrige point1 < point2
		if (p1 > p2)
			std::swap(p1, p2);
	
		// si idle time 
		if (tmp[1] > 0) 
		{
			eo.modifyBlock(bloc, p2);
		}
		eo.putJob(p1, eo.getJob(p2)); // vérifier si copie nécessaire
		eo.putJob(p2, tmp);
	}
	else
	{
		isModified = false;
	}
	return isModified;
  }

private:
};

#endif
