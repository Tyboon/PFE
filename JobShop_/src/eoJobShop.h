/** -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

The above line is usefulin Emacs-like editors
 */

/*
Template for creating a new representation in EO
================================================

Mandatory:
- a default constructor (constructor without any argument)
- the I/O functions (readFrom and printOn)

However, if you are using dynamic memory, there are 2 places
to allocate it: the default constructor (if possible?), or, more in
the EO spirit, the eoInit object, that you will need to write anyway
(template file init.tmpl).

But remember that a COPY CONSTRUCTOR will be used in many places in EO,
so make sure that the default copy constructor works, or, even better,
do write your own if in doubt.
And of course write the corresponding destructor!

*/

#ifndef _eoJobShop_h
#define _eoJobShop_h

#include "eoJobShopObjectiveVector.h"
#include "Data.h"

/**
 *  Always write a comment in this format before class definition
 *  if you want the class to be documented by Doxygen

 * Note that you MUST derive your structure from EO<fitT>
 * but you MAY use some other already prepared class in the hierarchy
 * like eoVector for instance, if you handle a vector of something....

 * If you create a structure from scratch,
 * the only thing you need to provide are
 *        a default constructor
 *        IO routines printOn and readFrom
 *
 * Note that operator<< and operator>> are defined at EO level
 * using these routines
 */

class eoJobShop: public moeoIntVector<eoJobShopObjectiveVector> {
public:
  /** Ctor: you MUST provide a default ctor.
   * though such individuals will generally be processed
   * by some eoInit object
   */
  eoJobShop()
  {
    // START Code of default Ctor of an eoJobShop object
    // END   Code of default Ctor of an eoJobShop object
  }

  /** Copy Ctor: you MUST provide a copy ctor if the default
   * one is not what you want
   * If this is the case, uncomment and fill the following
   */
  /*
  eoJobShop(const eoJobShop &)
  {
    // START Code of copy Ctor of an eoJobShop object
    // END   Code of copy Ctor of an eoJobShop object
  }
  */


  virtual ~eoJobShop()
  {
    // START Code of Destructor of an eoEASEAGenome object
    // END   Code of Destructor of an eoEASEAGenome object
  }

  virtual string className() const { return "eoJobShop"; }

  /** printing... */
    void printOn(ostream& os) const
    {
      // First write the fitness
      moeoIntVector<eoJobShopObjectiveVector>::printOn(os);
      os << ' ';
    // START Code of default output

	/** HINTS
	 * in EO we systematically write the sizes of things before the things
	 * so readFrom is easier to code (see below)
	 */

    // END   Code of default output
    }

  /** reading...
   * of course, your readFrom must be able to read what printOn writes!!!
   */
    void readFrom(istream& is)
      {
	// of course you should read the fitness first!
	moeoIntVector<eoJobShopObjectiveVector>::readFrom(is);
    // START Code of input

	/** HINTS
	 * remember the eoJobShop object will come from the default ctor
	 * this is why having the sizes written out is useful
	 */

    // END   Code of input
      }
      
	vector<int> getJob(int i) const
	{
			return jobs[i];
	}
	
	void modifyIdleT(int pos, int val)
	{
		jobs[pos][1] = val;
	}
	 int getSize()
	{
		return jobs.size();
	}
	
	void putBlock(vector<int> v)
	{
		blocks = v;
	}
	
	void putJobs(vector<vector<int> > & jobs_)
	{
		jobs = jobs_;
	}
	
	void putJob(int j, vector<int> job)
	{
		jobs[j] = job;
	}
	
	void insertJob(int pos, vector<int> val) //Si le job contient un idle time on l'enlève, Si ajout en début report de l'idle time 
	{
		int b = getBlock(pos);
		if (val[1] >0)
			val[1] =0;
		if (blocks[b] == pos)
		{
			val[1] = jobs[pos][1];
			jobs[pos][1] = 0;
		}
		jobs.insert(jobs.begin() + pos , val);
	}
	
	void deleteJob(int i) // Si début de bloc report de l'idle time au suivant
	{
		if (jobs[i][1] > 0)
		{
			jobs[i+1][1] = jobs[i][1];
		}
		jobs.erase(jobs.begin() + i);
	}
	
	void addJob(vector<int> job)
	{
		jobs.push_back(job);
	}
	
	// retourne l'indice dans jobs du 1er job du bloc 
	int getIndBlock(int i) 
	{
		return blocks[i];
	}
	
	// Retourne l'indice du Bloc contenant le ième job
	int getBlock(int j)
	{	
		int i = 0;
		while ( i< blocks.size() && blocks[i] <= j) 
		{
			i++;
		}
		if (i ==0) return 0;
		return i-1;
	}
	
	vector<int> getBlocks()
	{
		return blocks;
	}
	
	void addBlock(int i, int val)
	{
		blocks.insert(blocks.begin() + i , val);
	}
	
	void deleteBlock(int i)
	{
		blocks.erase(blocks.begin() + i);
	}
	
	void modifyBlock(int b, int new_pos)
	{
		blocks[b] = new_pos;
	}
	
	int getBlockSize()
	{
		return blocks.size();
	}
	
	bool isValidBlock() 
	{
		for (int i = 1; i < blocks.size(); i++)
		{
			if  (blocks[i-1] >= blocks[i])
				return false;
		}
		return true;
	}
	
		
	void printJob() 
	{
		int N = jobs.size();
		cout<<"JOB ";
		for (int i =0; i < N; i++)
		{
			if (jobs[i][1] > 0)
				cout<<jobs[i][0] <<"("<<jobs[i][1]<<")";
			else 
				cout<<jobs[i][0]<<"-";
		}
		cout<<endl;
	}
	
	void printBlock()
	{
		cout<<"BLOCK";
		for (int i = 0; i < blocks.size(); i++)
			cout<<blocks[i]<<" ";
		cout<<endl;
	}
	
	int getMaxD()
	{
		return max_d;
	}
	
	void putMaxD(int d)
	{
		max_d = d;
	}
	
	
	int getComp(int j)
	{	
		cout<<"Enter getComp "<<j<<endl;
		int comp = 0;
		int i = 0;
		vector<int> job(2,0);
		while  (i < j)
		{
			job = jobs[i];
			comp += (job[1] + data.getJob(job[0]).getP());
			i++;
		}
		comp += jobs[i][1];
		cout<<"Exit getComp "<<comp<<endl;
		return comp;
	}
	
	Data getData()
	{
		return data;
	}
	
	void putData(Data data_)
	{
		data= data_;
	}
	
private: // put all data here
	vector<vector<int> > jobs ; //num data, idle time
	vector<int> blocks; //locus
	int max_d;
	Data data;
};

#endif
