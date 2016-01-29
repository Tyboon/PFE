/** -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

The above line is usefulin Emacs-like editors
 */

/*
Template for creating a new representation in EO
================================================

This is the template main file.
It includes all other files that have been generated by the script create.sh
so it is the only file to compile.

In case you want to build up a separate library for your new Evolving Object,
you'll need some work - follow what's done in the src/ga dir, used in the
main file BitEA in tutorial/Lesson4 dir.
Or you can wait until we do it :-)
*/

// Miscilaneous include and declaration
#include <iostream>
using namespace std;

// eo general include
#include <eo>
// the real bounds (not yet in general eo include)
#include "utils/eoRealVectorBounds.h"

// include here whatever specific files for your representation
// Basically, this should include at least the following

/** definition of representation:
 * class eoJobShop MUST derive from EO<FitT> for some fitness
 */
#include "eoJobShop.h"

/** definition of initilizqtion:
 * class eoJobShopInit MUST derive from eoInit<eoJobShop>
 */
#include "eoJobShopInit.h"

/** definition of evaluation:
 * class eoJobShopEvalFunc MUST derive from eoEvalFunc<eoJobShop>
 * and should test for validity before doing any computation
 * see tutorial/Templates/evalFunc.tmpl
 */
#include "eoJobShopEvalFunc.h"

/** definitions of operators: write as many classes as types of operators
 * and include them here. In this simple example,
 * one crossover (2->2) and one mutation (1->1) operators are used
 */
#include "eoJobShopQuadCrossover.h"
#include "eoJobShopMutation.h"

/* and (possibly) your personal statistics */
#include "eoJobShopStat.h"
#include "eoJobShopOpR.h"
// GENOTYPE   eoJobShop ***MUST*** be templatized over the fitness

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// START fitness type: double or eoMaximizingFitness if you are maximizing
//                     eoMinimizingFitness if you are minimizing
typedef eoMinimizingFitness MyFitT ;	// type of fitness
// END fitness type
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

// Then define your EO objects using that fitness type
typedef eoJobShop<MyFitT> Indi;      // ***MUST*** derive from EO


// Use existing modules to define representation independent routines

// how to initialize the population
// it IS representation independent if an eoInit is given
#include <make_pop.h>
eoPop<Indi >&  make_pop(eoParser& _parser, eoState& _state, eoInit<Indi> & _init)
{
  return do_make_pop(_parser, _state, _init);
}

// the stopping criterion
#include <make_continue.h>
eoContinue<Indi>& make_continue(eoParser& _parser, eoState& _state, eoEvalFuncCounter<Indi> & _eval)
{
  return do_make_continue(_parser, _state, _eval);
}

// outputs (stats, population dumps, ...)
#include <make_checkpoint.h>
eoCheckPoint<Indi>& make_checkpoint(eoParser& _parser, eoState& _state, eoEvalFuncCounter<Indi>& _eval, eoContinue<Indi>& _continue)
{
  return do_make_checkpoint(_parser, _state, _eval, _continue);
}

// evolution engine (selection and replacement)
#include <make_algo_scalar.h>
eoAlgo<Indi>&  make_algo_scalar(eoParser& _parser, eoState& _state, eoEvalFunc<Indi>& _eval, eoContinue<Indi>& _continue, eoGenOp<Indi>& _op, eoDistance<Indi> *_dist = NULL)
{
  return do_make_algo_scalar(_parser, _state, _eval, _continue, _op, _dist);
}

// simple call to the algo. stays there for consistency reasons
// no template for that one
#include <make_run.h>
// the instanciating fitnesses
#include <eoScalarFitness.h>
void run_ea(eoAlgo<Indi>& _ga, eoPop<Indi>& _pop)
{
  do_run(_ga, _pop);
}

// checks for help demand, and writes the status file
// and make_help; in libutils
void make_help(eoParser & _parser);

// now use all of the above, + representation dependent things
int main(int argc, char* argv[])
{
try
  {
    eoParser parser(argc, argv);  // for user-parameter reading

    eoState state;    // keeps all things allocated

    // The fitness
    //////////////
    eoJobShopEvalFunc<Indi> plainEval/* (varType  _anyVariable) */;
    // turn that object into an evaluation counter
    eoEvalFuncCounter<Indi> eval(plainEval);

    // a genotype initializer
    eoJobShopInit<Indi> init;
    // or, if you need some parameters, you might as well
    // - write a constructor of the eoJobShopInit that uses a parser
    // - call it from here:
    //        eoJobShopInit<Indi> init(parser);

    // if you want to do sharing, you'll need a distance.
    // see file utils/eoDistance.h
    //
    // IF you representation has an operator[]() double-castable,
    // then you can use for instance the quadratic distance (L2 norm)
    //    eoQuadDistance<Indi> dist;
    // or the Hamming distance (L1 norm)
    // eoHammingDistance<Indi> dist;


    // Build the variation operator (any seq/prop construct)
    // here, a simple example with only 1 crossover (2->2, a QuadOp) and
    // one mutation, is given.
    // Hints to have choice among multiple crossovers and mutations are given

    // A (first) crossover (possibly use the parser in its Ctor)
    eoJobShopQuadCrossover<Indi> cross /* (eoParser parser) */;

    // IF MORE THAN ONE:

    // read its relative rate in the combination
// double cross1Rate = parser.createParam(1.0, "cross1Rate", "Relative rate for crossover 1", '1', "Variation Operators").value();

    // create the combined operator with the first one (rename it cross1 !!!)
// eoPropCombinedQuadOp<Indi> cross(cross1, cross1Rate);

    // and as many as you want the following way:
    // 1- write the new class by mimicking eoJobShopQuadCrossover.h
    // 2- include that file here together with eoJobShopQuadCrossover above
    // 3- uncomment and duplicate the following lines:
    //
// eoJobShopSecondCrossover<Indi> cross2(eoParser parser);
// double cross2Rate = parser.createParam(1.0, "cross2Rate", "Relative rate for crossover 2", '2', "Variation Operators").value();
// cross.add(cross2, cross2Rate);

  // NOTE: if you want some gentle output, the last one shoudl be like
  //  cross.add(cross, crossXXXRate, true);

    /////////////// Same thing for MUTATION

  // a (first) mutation   (possibly use the parser in its Ctor)
  eoJobShopMutation<Indi> mut /* (parser) */;

    // IF MORE THAN ONE:

    // read its relative rate in the combination
// double mut1Rate = parser.createParam(1.0, "mut1Rate", "Relative rate for mutation 1", '1', "Variation Operators").value();

    // create the combined operator with the first one (rename it cross1 !!!)
// eoPropCombinedMonOp<Indi> mut(mut1, mut1Rate);

    // and as many as you want the following way:
    // 1- write the new class by mimicking eoJobShopMutation.h
    // 2- include that file here together with eoJobShopMutation above
    // 3- uncomment and duplicate the following lines:
    //
// eoJobShopSecondMutation<Indi> mut2(eoParser parser);
// double mut2Rate = parser.createParam(1.0, "mut2Rate", "Relative rate for mutation 2", '2', "Variation Operators").value();
// mut.add(mut2, mut2Rate);

  // NOTE: if you want some gentle output, the last one shoudl be like
  //  mut.add(mut, mutXXXRate, true);

  // now encapsulate your crossover(s) and mutation(s) into an eoGeneralOp
  // so you can fully benefit of the existing evolution engines

  // First read the individual level parameters
    double pCross = parser.createParam(0.6, "pCross", "Probability of Crossover", 'C', "Variation Operators" ).value();
    // minimum check
    if ( (pCross < 0) || (pCross > 1) )
      throw runtime_error("Invalid pCross");

    double pMut = parser.createParam(0.1, "pMut", "Probability of Mutation", 'M', "Variation Operators" ).value();
    // minimum check
    if ( (pMut < 0) || (pMut > 1) )
      throw runtime_error("Invalid pMut");

    // now create the generalOp
    eoSGAGenOp<Indi> op(cross, pCross, mut, pMut);


    //// Now some representation-independent things
    //
    // You do not need to modify anything beyond this point
    // unless you want to add specific statistics to the checkpoint
    // in which case you should uncomment the corresponding block
    // and possibly modify the parameters in the stat object creation
    //////////////////////////////////////////////

  // initialize the population
  // yes, this is representation indepedent once you have an eoInit
  eoPop<Indi>& pop   = make_pop(parser, state, init);

  // stopping criteria
  eoContinue<Indi> & term = make_continue(parser, state, eval);
  // output
  eoCheckPoint<Indi> & checkpoint = make_checkpoint(parser, state, eval, term);


  // UNCOMMENT the following commented block if you want to add you stats

  // if uncommented, it is assumed that you will want to print some stat.
  // if not, then the following objects will be created uselessly - but what the heck!

  eoJobShopStat<Indi>   myStat;       // or maybe myStat(parser);
  checkpoint.add(myStat);
  // This one is probably redundant with the one in make_checkpoint, but w.t.h.
  eoIncrementorParam<unsigned> generationCounter("Gen.");
  checkpoint.add(generationCounter);
  // need to get the name of the redDir param (if any)
  std::string dirName =  parser.getORcreateParam(std::string("Res"), "resDir", "Directory to store DISK outputs", '\0', "Output - Disk").value() + "/";


  // those need to be pointers because of the if's
  eoStdoutMonitor *myStdOutMonitor;
  eoFileMonitor   *myFileMonitor;
#ifdef HAVE_GNUPLOT
  eoGnuplot1DMonitor *myGnuMonitor;
#endif

  // now check how you want to output the stat:
  bool printJobShopStat = parser.createParam(false, "coutJobShopStat", "Prints my stat to screen, one line per generation", '\0', "My application").value();
  bool fileJobShopStat = parser.createParam(false, "fileJobShopStat", "Saves my stat to file (in resDir", '\0', "My application").value();
  bool plotJobShopStat = parser.createParam(false, "plotJobShopStat", "On-line plots my stat using gnuplot", '\0', "My application").value();

  // should we write it on StdOut ?
  if (printJobShopStat)
    {
      myStdOutMonitor = new eoStdoutMonitor(false);
      // don't forget to store the memory in the state
      state.storeFunctor(myStdOutMonitor);
      // and of course to add the monitor to the checkpoint
      checkpoint.add(*myStdOutMonitor);
      // and the different fields to the monitor
      myStdOutMonitor->add(generationCounter);
      myStdOutMonitor->add(eval);
      myStdOutMonitor->add(myStat);
    }

  // first check the directory (and creates it if not exists already):
  if (fileJobShopStat || plotJobShopStat)
      if (! testDirRes(dirName, true) )
	throw runtime_error("Problem with resDir");

  // should we write it to a file ?
  if (fileJobShopStat)
    {
      // the file name is hard-coded - of course you can read
      // a string parameter in the parser if you prefer
      myFileMonitor = new eoFileMonitor(dirName + "myStat.xg");
      // don't forget to store the memory in the state
      state.storeFunctor(myFileMonitor);
      // and of course to add the monitor to the checkpoint
      checkpoint.add(*myFileMonitor);
      // and the different fields to the monitor
      myFileMonitor->add(generationCounter);
      myFileMonitor->add(eval);
      myFileMonitor->add(myStat);
    }

#ifdef HAVE_GNUPLOT
  // should we PLOT it on StdOut ? (one dot per generation, incremental plot)
  if (plotJobShopStat)
    {
      myGnuMonitor = new eoGnuplot1DMonitor(dirName+"plot_myStat.xg",minimizing_fitness<Indi>());
      // NOTE: you cand send commands to gnuplot at any time with the method
      // myGnuMonitor->gnuplotCommand(string)
      // par exemple, gnuplotCommand("set logscale y")

      // don't forget to store the memory in the state
      state.storeFunctor(myGnuMonitor);
      // and of course to add the monitor to the checkpoint
      checkpoint.add(*myGnuMonitor);
      // and the different fields to the monitor (X = eval, Y = myStat)
      myGnuMonitor->add(eval);
      myGnuMonitor->add(myStat);
    }
#endif

  // algorithm (need the operator!)
  eoAlgo<Indi>& ga = make_algo_scalar(parser, state, eval, checkpoint, op);
  // and the distance if you want to do sharing
  // eoAlgo<Indi>& ga = make_algo_scalar(parser, state, eval, checkpoint, op, &dist);

  ///// End of construction of the algorithm

  /////////////////////////////////////////
  // to be called AFTER all parameters have been read!!!
  make_help(parser);

  //// GO
  ///////
  // evaluate intial population AFTER help and status in case it takes time
  apply<Indi>(eval, pop);
  // if you want to print it out
//   cout << "Initial Population\n";
//   pop.sortedPrintOn(cout);
//   cout << endl;

  run_ea(ga, pop); // run the ga

  cout << "Final Population\n";
  pop.sortedPrintOn(cout);
  cout << endl;

  }
  catch(exception& e)
  {
    cout << e.what() << endl;
  }
  return 0;
}
