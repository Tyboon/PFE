/** -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

The above line is useful in Emacs-like editors
 */

/*
Template for simple mutation operators
======================================
*/

#ifndef eoJobShopSubblock_H
#define eoJobShopSubblock_H


#include <eoOp.h>

/**
 *  Always write a comment in this format before class definition
 *  if you want the class to be documented by Doxygen
 *
 * THere is NO ASSUMPTION on the class GenoypeT.
 * In particular, it does not need to derive from EO
 */
template<class eoJobShop>
class eoJobShopSubblock: public eoMonOp<eoJobShop>
{
public:
  /**
   * Ctor - no requirement
   */
// START eventually add or modify the anyVariable argument
  eoJobShopSubblock()
  //  eoJobShopSubblock( varType  _anyVariable) : anyVariable(_anyVariable)
// END eventually add or modify the anyVariable argument
  {
    // START Code of Ctor of an eoJobShopEvalFunc object
    // END   Code of Ctor of an eoJobShopEvalFunc object
  }

  /// The class name. Used to display statistics
  string className() const { return "eoJobShopSubblock"; }

  /**
   * modifies the parent
   * @param _genotype The parent genotype (will be modified)
   */
  bool operator()(eoJobShop & eo)
  {
	cout<<"enter mutation subblock"<<endl;
	eo.printJob();
	eo.printBlock();
	bool isModified(true);
	unsigned int N = eo.getSize();
	unsigned int p, t; //random int;
	
	eoUniformGenerator<int> rdm(0,N);
	p =  rdm(); // rng.random(N);
	  
	cout<<"point "<<p<<endl;
	int b = eo.getBlock(p);
	int ind_b =   eo.getIndBlock(b);
	  
	if (b >= eo.getBlockSize()-1) //TODO si dernier bloc ... 
	{
		isModified = false;
		return isModified;
	}
	else 
	{
		int nextJ = eo.getIndBlock(b+1); 
		if (p == ind_b) // si début de block
		{
			int max_t1 = eo.getJob(p)[1];
			int max_t2 = eo.getJob(nextJ)[1];
			t = max_t1+max_t2;
			eoUniformGenerator<int> rdm2(1, t+1); // rdm de t
			t = rdm2();
			if (t <= max_t1)
				push_left(eo, t, p, max_t1, b, nextJ, max_t2); //retry idle_time
			else 
				push_right(eo,t-max_t1, p, max_t1, b, nextJ, max_t2); // add idle_time
		}	
		else //les cas au centre juste décale droite
		{
			eoUniformGenerator<int> rdm2(1, eo.getJob(nextJ)[1]+1); // rdm de t
			t = rdm2();
			eo.modifyIdleT(p, t);
			int tmp = eo.getJob(nextJ)[1] - t;
			eo.modifyIdleT(nextJ, tmp);
			if (tmp ==0)
				eo.modifyBlock(b+1, p);
			else
				eo.addBlock(b+1, p);
		}
	}
	if  (! eo.isValidBlock() )
		cout << "ERROR block "<< endl;
	eo.printJob();
	eo.printBlock();
	cout<< "exit mutation subblock"<<endl;
	return isModified;
  }
  
  void push_left(eoJobShop & eo, int t, int p, int idle_p, int b, int nextJ, int idle_next)
  {
	if ( t == idle_p) //fusion avant
	{
		eo.modifyIdleT(p, 0);
		eo.deleteBlock(b);
		eo.modifyIdleT(nextJ, idle_next+t);
	}
	else //change idle time
	{
		eo.modifyIdleT(p, idle_p-t);
		eo.modifyIdleT(nextJ, idle_next+t);
	}
  }

   void push_right(eoJobShop & eo, int t, int p, int idle_p, int b, int nextJ, int idle_next)
  {
	if ( t == idle_next) //fusion arrière
	{
		eo.modifyIdleT(nextJ, 0);
		eo.deleteBlock(b+1);
		eo.modifyIdleT(p, idle_p+t);
	}
	else //change idle time
	{
		eo.modifyIdleT(p, idle_p+t);
		eo.modifyIdleT(nextJ, idle_next-t);
	}
  }
  
private:
};

#endif
