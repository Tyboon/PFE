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
	int max_t2, max_t1, comp, tmp, max;
	  
	eoUniformGenerator<int> rdm(0,N);
	p =  rdm(); // rng.random(N);
	  
	cout<<"point "<<p<<endl;
	int b = eo.getBlock(p);
	int ind_b =   eo.getIndBlock(b);
	cout<<" bloc "<<b<<" indice_B "<<ind_b<<endl;
	if (b >= eo.getBlockSize()-1) //Si dernier bloc ... 
	{
		cout<<"LAST BLOC"<<endl;
		comp = eo.getComp(p);
		cout<<"Comp "<<comp<<endl;
		max = eo.getMaxD();
		cout<<"Max d "<<max<<endl;
		max_t2 = max - comp;
		cout << "COMP "<<comp<<" ind_b "<< ind_b<<" max_t2 "<<max_t2<<" max_d "<<max<<endl;
		if (p == ind_b) // si début de block
		{
			cout<<"début bloc"<<endl;
			max_t1 = eo.getJob(p)[1];
			
			if (max_t2 <=0)
			{
				eoUniformGenerator<int> rdm2(1, max_t1);
				t = rdm2();
				push_left_last(eo, t, p, max_t1, b); //retry idle_time
				cout<<"push left last "<<max_t1<<endl;
			}
			else
			{
				tmp = max_t1+max_t2;
				eoUniformGenerator<int> rdm2(1, tmp+1); // rdm de t
				t = rdm2();
				if (t <= max_t1)
				{
					push_left_last(eo, t, p, max_t1, b); //retry idle_time
					cout<<"push left last t "<<t<<" max_t1 "<<max_t1<<endl;
				}
				else 
				{
					push_right_last(eo,t-max_t1, p, max_t1, b); // add idle_time
					cout<<"push right last t "<<t-max_t1<<" max_t1 "<<max_t1<<endl;
				}
			}
		}	
		else //les cas au centre juste décale droite
		{
			if (max_t2 > 0)
			{
				cout<<"B1111"<<endl;
				eoUniformGenerator<int> rdm2(1, max_t2); // rdm de t
				t = rdm2();
				eo.modifyIdleT(p, t);
				eo.addBlock(b+1, p);
			}
			else
			{
				cout<<"false"<<endl;
				isModified = false;
				return isModified;
			}
		}
		
		
	}
	else 
	{
		cout<<"B222"<<endl;
		int nextJ = eo.getIndBlock(b+1); 
		if (p == ind_b) // si début de block
		{
			max_t1 = eo.getJob(p)[1];
			max_t2 = eo.getJob(nextJ)[1];
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
  
   void push_left_last(eoJobShop & eo, int t, int p, int idle_p, int b)
  {
	if ( t == idle_p) //fusion avant
	{
		eo.modifyIdleT(p, 0);
		eo.deleteBlock(b);
	}
	else //change idle time
	{
		eo.modifyIdleT(p, idle_p-t);
	}
  }
  
  void push_right_last(eoJobShop & eo, int t, int p, int idle_p, int b)
  {
		eo.modifyIdleT(p, idle_p+t);
  }
  
private:
};

#endif
