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
	bool isModified(true);
	int comp = 0;
	int diff = 0;
	int size = eo.getSize();
	  
	for (int i = 0; i < size; i++)
	{
		vector<int> job = eo.getJob(i);
		diff = data.getJob(0).getR() - (comp + job[1] );
		if (diff > 0)
		{
			if (job[1] > 0)
				job[1] = job[1] + diff;
			else
			{
				job[1] = job[1] + diff;
				eo.addBlock(job[2], i);
			}			
		}
	}
	return isModified;
  }

private:
	Data data;
	
};
#endif