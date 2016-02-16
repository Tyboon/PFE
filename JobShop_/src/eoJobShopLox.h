/** -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

The above line is usefulin Emacs-like editors
 */

/*
Template for simple quadratic crossover operators
=================================================

Quadratic crossover operators modify the both genotypes
*/

#ifndef eoJobShopLox_H
#define eoJobShopLox_H

#include <eoOp.h>

/**
 *  Always write a comment in this format before class definition
 *  if you want the class to be documented by Doxygen
 *
 * THere is NO ASSUMPTION on the class GenoypeT.
 * In particular, it does not need to derive from EO
 */
template<class EOT>
class eoJobShopLox: public eoQuadOp<EOT>
{
public:
  /**
   * Ctor - no requirement
   */
// START eventually add or modify the anyVariable argument
  eoJobShopLox()
  //  eoJobShopLox( varType  _anyVariable) : anyVariable(_anyVariable)
// END eventually add or modify the anyVariable argument
  {
    // START Code of Ctor of an eoJobShopEvalFunc object
    // END   Code of Ctor of an eoJobShopEvalFunc object
  }

  /// The class name. Used to display statistics
  string className() const { return "eoJobShopLox"; }

  /**
   * eoQuad crossover - _genotype1 and _genotype2 are the (future)
   *       offspring, i.e. _copies_ of the parents, to be modified
   * @param eo1 The first parent
   * @param eo2 The second parent
   */
  bool operator()(EOT & eo1, EOT& eo2)
  { //2points
	cout<<"enter lox"<<endl;
        bool oneAtLeastIsModified(true);
	unsigned int N = eo1.getSize();
	unsigned int p1, p2; //random int;
	eoUniformGenerator<int> rdm(0,N);
	
	p1 =  rdm(); // rng.random(N);
	p2 =  rdm(); // rng.random(N);
	cout <<"p1, p2 " <<p1<<" "<<p2<<endl;
	// vérifie et corrige point1 < point2
	if (p1 > p2)
		std::swap(p1, p2);
	
	if (p1 !=p2 && not(p1 = 0 && p2==N-1))
	{
		vector< EOT > offspring;
		int max_d = eo1.getMaxD();
		Data data = eo1.getData();
		offspring.push_back(generateOffspring(eo1, eo2, p1, p2, max_d, data, N));
		offspring.push_back(generateOffspring(eo2, eo1, p1, p2, max_d, data, N));
		cout<<"give offspring"<<endl;
		eo1 = offspring[0];
		eo2 = offspring[1];
		eo1.printJob();
		eo1.printBlock();
		eo2.printJob();
		eo2.printBlock();
		oneAtLeastIsModified = true;
	}
	else
	{
		oneAtLeastIsModified = false;
	}
	if  (! eo1.isValidBlock() )
		cout << "ERROR block 1 "<< endl;
	if  (! eo2.isValidBlock() )
		cout << "ERROR block 2 "<< endl;
	cout<<"exit lox"<<endl;
    return oneAtLeastIsModified;
  }
	
  EOT generateOffspring( EOT& eo1, EOT & eo2, unsigned int p1, unsigned int p2, int max_d, Data data, int N)
{
	cout<<"enter generate offspring "<<endl;
	EOT result = eoJobShop();
	vector<int> b(N,0);
	b = eo1.getBlocks();
	result.putBlock(b);
	result.putMaxD(max_d);
	result.putData(data);
	result.putJobs(eo1.getJobs());
	
	eo1.printJob();
	eo1.printBlock();
	eo2.printJob();
	eo2.printBlock();
	
	int i = 0;
	int cpt = 0;
	int bloc = 0;
	
	while(i < N && cpt < (p2-p1))
	{
		
		vector<int> job1 = eo1.getJob(i);
		result.printJob();
		result.printBlock();
		if (job1[1] > 0)
				bloc++;
		for (int j = p1; j <= p2; j++)
		{
			vector<int> job2 = eo2.getJob(j);
			
			if (job1[0] == job2[0])
			{	
				vector<int> tmp = eo1.getJob(p1+cpt);
				
				if (tmp[1] > 0 && job1[1] == 0)
				{
					//cout<<"add block "<<bloc<<endl;
					result.addBlock( bloc,i);
				}
				else
				{
					if (tmp[1] == 0 && job1[1] > 0)
					{
						//cout<<"delete block "<<bloc-1<<endl;
						result.deleteBlock(bloc-1);
						bloc--;
					}
				}
				result.putJob(i, tmp);
				cpt++;
			}
		}
		i++;
	}
	
	for (int i = p1; i <= p2; i++)
	{
		vector<int> v = eo2.getJob(i);// controle bloc
		
		vector<int> tmp = eo1.getJob(i);
		bloc = result.getBlock(i);
		if (v[1] > 0 && tmp[1] == 0)
		{
			bloc = result.getBlock(i);
			result.addBlock(bloc+1,i);
		}
		else
		{
			if (tmp[1] == 0 && v[1] > 0)
			{
				result.deleteBlock(bloc);
			}
		}
		result.putJob(i, v);
	}

	result.printJob();
	result.printBlock();

	return result;	
}
  
private:
// START Private data of an eoJobShopLox object
  //  varType anyVariable;		   // for example ...
// END   Private data of an eoJobShopLox object
};

#endif
