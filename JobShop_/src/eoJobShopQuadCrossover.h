/** -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

The above line is usefulin Emacs-like editors
 */

/*
Template for simple quadratic crossover operators
=================================================

Quadratic crossover operators modify the both genotypes
*/

#ifndef eoJobShopQuadCrossover_H
#define eoJobShopQuadCrossover_H

#include <eoOp.h>

/**
 *  Always write a comment in this format before class definition
 *  if you want the class to be documented by Doxygen
 *
 * THere is NO ASSUMPTION on the class GenoypeT.
 * In particular, it does not need to derive from EO
 */
template<class EOT>
class eoJobShopQuadCrossover: public eoQuadOp<EOT>
{
public:
  /**
   * Ctor - no requirement
   */
// START eventually add or modify the anyVariable argument
  eoJobShopQuadCrossover()
  //  eoJobShopQuadCrossover( varType  _anyVariable) : anyVariable(_anyVariable)
// END eventually add or modify the anyVariable argument
  {
    // START Code of Ctor of an eoJobShopEvalFunc object
    // END   Code of Ctor of an eoJobShopEvalFunc object
  }

  /// The class name. Used to display statistics
  string className() const { return "eoJobShopQuadCrossover"; }

  /**
   * eoQuad crossover - _genotype1 and _genotype2 are the (future)
   *       offspring, i.e. _copies_ of the parents, to be modified
   * @param eo1 The first parent
   * @param eo2 The second parent
   */
  bool operator()(EOT & eo1, EOT& eo2)
  { //2points
	cout<<"enter crossover"<<endl;
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
	
	if (p1 !=p2)
	{
		vector< EOT > offspring;
		offspring.push_back(generateOffspring(eo1, eo2, p1, p2));
		offspring.push_back(generateOffspring(eo2, eo1, p1, p2));
		eo1 = offspring[0];
		eo2 = offspring[1];
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
	cout<<"exit crossover"<<endl;
    return oneAtLeastIsModified;
  }
	
  EOT generateOffspring( EOT& parent1, EOT & parent2, unsigned int p1, unsigned int p2)
{
	EOT result = eoJobShop();
	vector<int> b = parent1.getBlocks();
	result.putBlock(b);
	
	std::vector<bool> taken_values(parent1.getSize(), false);
	vector<int> var;
	
	parent1.printJob();
	parent1.printBlock();
	parent2.printJob();
	parent2.printBlock();
	
	for (unsigned int i =0; i < parent1.getSize(); i++)
	{
		if (i>p1 && i<p2)
		{
			vector<int> v(2,0);
			result.addJob(v);
		} 
		else
		{
			var = parent1.getJob(i);
			taken_values[var[0]] = true; 
			result.addJob(var);
		}
	}

	unsigned int i = p1 + 1;
	unsigned j = 0;
	while (i < p2 && j < parent2.getSize())
	{
		if (!taken_values[parent2.getJob(j)[0]])
		{
			result.putJob(i, parent2.getJob(j));
			i++;
		}
		j++;
	}
	
	
	
	// maj blocs
	int b1 = result.getBlock(p1);
	int b2 = result.getBlock(p2);
	int t;
	if ((result.getJob(p2)[1] == 0) && (b2 != 0) && (b1 != b2)) // pas le bloc 0 ou le même bloc que 1
		result.deleteBlock(b2);
	for (int b= b2-1; b>b1;b--)
	{
		result.deleteBlock(b);
	}
	for (int i = p1+1; i < p2; i++)
	{
		t = result.getJob(i)[1];
		if (t>0)  
		{
			b1++;
			result.addBlock(b1, i);
		}
	}

	result.printJob();
	result.printBlock();
	return result;	
}
  
private:
// START Private data of an eoJobShopQuadCrossover object
  //  varType anyVariable;		   // for example ...
// END   Private data of an eoJobShopQuadCrossover object
};

#endif
