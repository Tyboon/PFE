/** -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-


#ifndef _eoJobShopOpR_h
#define _eoJobShopOpR_h

// include whatever general include you need
#include <stdexcept>
#include <fstream>

#include "Data.h"

class eoJobShopOpR : public eoEvalFunc<EOT>
{
public:

  eoJobShopOpR(Data _data)
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
	  
	for (int i = 0; i < eo.getSize(); i++)
	{
		eoVector<eoVector<eoVector<int>>> & job = eo.getJobShop(i);
		diff = data.getR(job[0]) - (comp + job[1] )
		if (diff > 0)
		{
			if (j[1] > 0)
				j[1] = j[1] + diff;
			else
			{
				j[1] = j[1] + diff;
				eo.addBlock(job[2]+1, i);
			}			
		}
	}
	return isModified;
  }

private:
	Data data;
	
};
#endif