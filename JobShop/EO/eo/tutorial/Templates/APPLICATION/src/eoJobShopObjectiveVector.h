/** -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

The above line is useful in Emacs-like editors
 */

/*
Template for simple mutation operators
======================================
*/

#ifndef eoJobShopObjectiveVector_H
#define eoJobShopObjectiveVector_H


#include <eoOp.h>  //voir la lib to import

class eoJobShopObjectiveVector: public moeoObjectiveVector {
public: 
	typedef moeoRealObjectiveVector<FlowShopObjectiveVectorTraits> FlowShopObjectiveVector;
}