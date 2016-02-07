#include <iostream>
using namespace std;
#include <stdio.h>
#include <moeo>
#include <eo>

#include "Data.h"
#include "eoJobShopInit.h"
#include "eoJobShopQuadCrossover.h"
#include "eoJobShopMutation.h"
#include "Parser.h"
#include "eoJobShopObjectiveVectorTraits.h"
#include "eoJobShopObjectiveVector.h"
#include "eoJobShop.h"
#include "eoJobShopEvalFunc.h"


typedef eoJobShop Indi;

#include <make_pop.h>
eoPop<Indi>&  make_pop(eoParser& _parser, eoState& _state, eoInit<Indi> & _init)
{
  return do_make_pop(_parser, _state, _init);
}

// checks for help demand, and writes the status file
// and make_help; in libutils
void make_help(eoParser & _parser);


// main
int main (int argc, char *argv[])
{
    eoParser parser(argc, argv);  // for user-parameter reading

    /** Lecture des informations d entree a partir du fichier mentionné dans le fichier "fichier.param" **/

    std::string inputFile = parser.createParam(std::string("../../DataOneMachine/bky20/bky20_1.txt"), "inputFile", "File which describes input information", 'I', "Param" ).value();
    
   
    
    Parser p(inputFile);
    Data data = p();

    eoState state;                // to keep all things allocated*/

    // parameters
    unsigned int MAX_GEN = parser.createParam((unsigned int)(100), "maxGen", "Maximum number of generations",'G',"Param").value();
 
   
    // objective functions evaluation
    //moeoUCPEval eval;
    eoJobShopEvalFunc< Indi > plainEval(data);

    // turn that object into an evaluation counter
    eoEvalFuncCounter<Indi> eval(plainEval);

    eoJobShopInit<Indi> init(data);

    // A (first) crossover (possibly use the parser in its Ctor)
    eoJobShopQuadCrossover<Indi> cross;
    eoJobShopMutation<Indi> mut;
    // eoUCPWindowMutation<Indi> w_mut;
    //eoUCPWindowCrossover<Indi> w_cross;
	  
    double pCross = parser.createParam(0.6, "pCross", "Probability of Crossover", 'C', "Variation Operators" ).value();
    //double pCross1 = parser.getORcreateParam(0.6, "pCross1", "Probability of Crossover", 'x', "Variation Operators" ).value();

    //double pWCross = parser.getORcreateParam(0.7, "pWCross", "Probability of Window-Crossover", 'W', "Variation Operators" ).value();
    // minimum check
    if ( (pCross < 0) || (pCross > 1) )
      throw runtime_error("Invalid pCross");

    //double pMut1 = parser.getORcreateParam(0.1, "pMut1", "Probability of Mutation", '1', "Variation Operators" ).value();

    //double pWMut = parser.getORcreateParam(0.3, "pWMut", "Probability of Window-Mutation", 'w', "Variation Operators" ).value();
    // minimum check 
    //if ( (pMut1 < 0) || (pMut1 > 1) )
      //throw runtime_error("Invalid pMut");

    //eoPropCombinedQuadOp<Indi> cross(cross1,pCross);
    //cross.add(w_cross,pWCross);

    //eoPropCombinedMonOp<Indi> mut(mut1, pMut1);
    //mut.add(w_mut,pWMut);

    double pMut = parser.createParam(0.1, "pMut", "Probability of Mutation", 'M', "Variation Operators" ).value();
    if ( (pMut < 0) || (pMut > 1) )
        throw runtime_error("Invalid pCross");
    // generate initial population
     eoSGAGenOp<Indi> op(cross, pCross, mut, pMut);
    
    // // initialize the population
     eoPop<Indi>& pop   = make_pop(parser, state, init);
    eoFileMonitor   *myFileMonitor;
 
    int algo = parser.createParam(0, "algo", "Choose algorithm 0 = NSGA-II, 1 = IBEA", 'A', "Algorithm").value();
    int maxtime=parser.createParam(100, "maxtime", "temps maximal", 't', "Algorithm").value();
    // printing of the initial population
    /*cout << "Initial Population\n";
    pop.sortedPrintOn(cout);
    cout << endl;*/
    
   
    eoTimeContinue< Indi >  continuator(maxtime);
    eoCheckPoint<Indi> checkpoint (continuator);
    moeoUnboundedArchive < Indi > arch1;
    moeoArchiveUpdater<Indi> updater(arch1, pop);
    //checkpoint.add(updater);
     //moeoSteadyHyperVolumeContinue<Indi> continuator( 0, 100, hyperVol);
     
    if ( algo == 0 ) {
   	 // build NSGA-II
        moeoNSGAII < Indi > nsgaII (MAX_GEN, eval, cross, pCross, mut, pMut);
        //moeoNSGAII < Indi > nsgaII (checkpoint, eval, op);
    	// run the algo
        
    	nsgaII (pop);
        cout << "test"<<endl;

    } else {
    	moeoAdditiveEpsilonBinaryMetric<eoJobShopObjectiveVector> indicator;
    	moeoIBEA<Indi> ibea (MAX_GEN, eval, cross, pCross, mut, pMut, indicator);
    	ibea (pop);
    }

    // help ?
    make_help(parser);

    // extract first front of the final population using an moeoArchive (this is the output of nsgaII)
    moeoUnboundedArchive < Indi > arch;
    arch(pop);
    

    // printing of the final population
    cout << "Final Population\n";
    pop.sortedPrintOn(cout);
    cout << endl;

    // printing of the final archive
    //std::cout << "Final Archive " << std::endl;
    //std::cout << "sans archive : ";
    arch.sortedPrintOn(std::cout);
    std::cout << std::endl;
    



    return EXIT_SUCCESS;
}
