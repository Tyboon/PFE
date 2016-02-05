/** -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*- **/


#ifndef _eoJobShopOpR_h
#define _eoJobShopOpR_h

// include whatever general include you need
#include <stdexcept>
#include <fstream>

#include "eoJobShopObjectiveVector.h"
#include "eoJobShop.h"
#include "Data.h"

class eoJobShopOpR 
{
public:

  eoJobShopOpR () {}

  void setData(Data _data)
	{
		data = _data;
	}


  /// The class name. Used to display statistics
  string className() const { return "eoJobShopOpR"; }

  /**
   * modifies the parent
   * @param _genotype The parent genotype (will be modified)
   */
  bool operator()(eoJobShop & eo)
  {
	cout<<"enter opR"<<endl;
	bool isModified(true);
	int comp = 0;
	int diff = 0;
	int size = eo.getSize();
	  cout<< "Tou"<<endl;
	for (int i = 0; i < size; i++)
	{
		vector<int> job = eo.getJob(i);
		diff = data.getJob(i).getR() - (comp + job[1] );
		cout<<i<<" "<<diff<<endl;
		if (diff > 0)
		{
			if (job[1] > 0) 
			{
				job[1] += diff;
				cout<< "if1"<<endl;
			}
			else
			{
				job[1] += diff;
				cout<< "if2"<<endl;
				eo.addBlock(eo.getBlock(i)+1, i);
				cout<< "if2"<<endl;
			}	
			eo.putJob(i, job);
		}
		comp += job[1] + data.getJob(i).getP();
	}
	cout<<"toutou"<<endl;
	cout<<"exit opR"<<endl;
	return isModified;
  }

private:
	Data data;
	
};
#endif