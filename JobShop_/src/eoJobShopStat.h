/** -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

The above line is usefulin Emacs-like editors
 */

/*
Template for computing statistics on eoPop
============================================
*/

#ifndef _eoJobShopStat_h
#define _eoJobShopStat_h

// include the base definition of eoInit
#include <utils/eoStat.h>

/**
 *  Always write a comment in this format before class definition
 *  if you want the class to be documented by Doxygen
 *
 * ASSUMPTION on the class GenoypeT:
 *             it needs to derive from EO (i.e. has a Fitness).
 *
 * It is assumed that you want to compute a double.
 * In case you want something else, then your stat should derive from
 *                      eoStat<GenotypeT, T>
 *  where class T is the class of the computed statistics
 */
template <class EOT>
class eoJobShopStat : public eoStat<EOT, double>
{
public :
    typedef typename EOT::Fitness Fitness;

// START eventually add or modify the anyVariable argument
  /** Ctor - you change the default name of course.
   * @param
   *  _description : inherited from eoValueParam (eoStat is an  from eoVapueParam)
   */
  eoJobShopStat(std::string _description = "eoJobShopStat ") :
    eoStat<EOT, double>(0.0, _description)
// END eventually add or modify the anyVariable argument
  {
    // START Code of Ctor of an eoMonReelStat object
    // END   Code of Ctor of an eoMonReelStat object
  }

    void operator()(const eoPop<EOT>& _pop){
	double tmpStat(0.);
    // START Code for computing the statistics - in tmpStat
      // tmpStat = blablabla
    // END   Code for computing the statistics
      eoStat<EOT,double>::value() = tmpStat;      // store the stat in the eoParam value() field
    }

  virtual std::string className(void) const { return "eoJobShopStat"; }
private :
// START Private data of an eoJobShopStat object
  //  varType anyVariable;		   // for example ...
// END   Private data of an eoJobShopStat object
};

#endif
