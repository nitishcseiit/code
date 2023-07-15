//#include<bits/stdc++.h>
#include<math.h>
//#include <z3++.h>


#include <iostream>
#include <z3++.h>
#include <fstream>
#include <typeinfo>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>

using namespace z3;

void f01_calculateReachabilityDiameter(context &myC, 	expr myTransitionRelation, expr_vector &myX, expr_vector &myY,
		int maxBitRequired, std::map<int, expr> myMappingFromIntToExprForVertices, std::vector<int> myVectorOfAllVertices,
		int myStateInitial, expr_vector &myStepwiseTransitionRelation, expr_vector &xES, expr_vector &yED, expr theTs);

void f01_controlFunctionForReachability(std::string theFileName, std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors, int *p3_theMaxBit,
		std::map<int, expr> &theVertexToItsBooleanExpression, expr_vector &xES, expr_vector &yED, context *c,
		expr &theT, expr &theIorF_I, expr &theIorF_F, int *pp_nov, int givenInitialState);
void f02_readTheInputFileAndGiveMeVectorOfVectors(std::string theFileName, std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors);
void f03_giveMeTheSortedvectorOfVertices(std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors, std::vector<int> *p2_theSortedVectorOfVertices);
void f04_findNumberOfMaxBitrequired(std::vector<int> theSortedVectorOfVertices, int *theMaxBitrequired);
void f05_integerToBinaryForAllVertices(std::vector<int> *p2_theSortedVectorOfVertices, std::map<int, std::vector<int> > *p4_integerToBinaryForAllVertices,
		int *p3_theMaxBit, context *c, std::map<int, expr> &theVertexToItsBooleanExpression);
void f06_decimalToBinary(int theDecimal, std::vector<int> *p1_theBinaryVector);
void f07_createEdgeToBooleanExpression2(std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors, std::map<int, std::vector<int> > integerToBinaryForAllVertices, std::map<int, expr> &theVertexToItsBooleanExpression, expr_vector &xES, expr_vector &yED, int *p3_theMaxBit, context *c, expr &theT, int givenInitialState);
void f07_createEdgeToBooleanExpression1(std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors, std::map<int, std::vector<int> > integerToBinaryForAllVertices, std::map<int, expr> &theVertexToItsBooleanExpression, expr_vector &xES, expr_vector &yED, int *p3_theMaxBit, context *c, expr &theT);

void f08_createVertexToBooleanExpression(std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors, std::map<int,
		std::vector<int> > integerToBinaryForAllVertices, expr_vector xES, int *p3_theMaxBit, context *c, expr &theIorF, int iORf);



using namespace z3;


int main(int argc, char **argv){
	context c;
	
	///////////////// rajdeep start
	
	
	std::vector<std::vector<int> > theInputFile_vectorOfVectors;
	std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors;
	int theMaxBitrequired, *p3_theMaxBit;
	std::map<int, expr> theVertexToItsBooleanExpression;
	//context c;
	expr_vector xES(c), yED(c);
	expr theT(c);
	expr theIorF_I(c);
	expr theIorF_F(c);
	expr tempT(c);
	expr_vector allTs(c);
	expr theFullBooleanFormula(c);

	check_result theResult1;
	solver theSolver1(c);
	model theModel1(c);
	expr theFtemp(c);
	int givenInitialState;

	int numberOfvertices, *pp_nov;

	pp_nov = &numberOfvertices;



	p1_theInputFile_vectorOfVectors = &theInputFile_vectorOfVectors;


	p3_theMaxBit = &theMaxBitrequired;



	   std::stringstream ss, ss2;
	   ss << argv[2];
	   ss >> givenInitialState;



	//givenInitialState = stoi(argv[2]);
	//givenFinalState = argv[3];


	f01_controlFunctionForReachability(argv[1], p1_theInputFile_vectorOfVectors, p3_theMaxBit,
			theVertexToItsBooleanExpression, xES, yED, &c, theT, theIorF_I, theIorF_F, pp_nov, givenInitialState);


/*
	for(expr_vector::iterator i1 = xES.begin(); i1 != xES.end(); i1++) {
		std::cout << "\nIn main:: " << *i1;
	}
*/

/*
	for(expr_vector::iterator i1 = yED.begin(); i1 != yED.end(); i1++) {
		std::cout << "\nIn main:: " << *i1;
	}
*/
/*
	std::cout << "\nPre-processing done. Z3 library starts now";

	std::cout << "\nCheck theT: " << theT;
	std::cout << "\nCheck theIorF_I: " << theIorF_I;
	std::cout << "\nCheck theIorF_F: " << theIorF_F;






		std::cout << "\nIn above. theMaxBitrequired: " << theMaxBitrequired;


*/
	/*
	 *
	 *
	 *
	 *
	 * */

/*		std::cout << "\n\n\nHy111111111111111";




	//context myCGLASS;
	expr myTransitionRelationmyCGLASS(c);
	expr_vector myXGLASS(c), myYGLASS(c), myStepwiseTransitionRelationGLASS(c);
	std::cout << "\n\n\nHy22222222222222222";
	int maxBitRequiredGLASS = theMaxBitrequired;
	std::cout << "\n\n\nHy33333333333333333";
	int j1GLASS;
	std::map<int, expr> myMappingFromIntToExprForVerticesGLASS;
	std::vector<int> myVectorOfAllVerticesGLASS;
	int myStateInitialGLASS;
	int theRecurrenceDiameterGLASS;
	std::cout << "\nHy4444444444444";



	std::cout << "\n\n\nCCCCCCCCCCCCCCCCCCCCalculate the receurrence diameter of a Kripke structure.";
	for(j1GLASS = 0; j1GLASS < maxBitRequiredGLASS; j1GLASS++) {
		std::stringstream myStreamX, myStreamY;
		myStreamX << "x_" << j1GLASS;
		myStreamY << "y_" << j1GLASS;
		myXGLASS.push_back(c.bool_const(myStreamX.str().c_str()));
		myYGLASS.push_back(c.bool_const(myStreamY.str().c_str()));
	}

	std::cout << "\n5555555555555555555555555";

	std::cout << "\n::: " << theVertexToItsBooleanExpression.size();
*/
	//The graph
	/*myTransitionRelationmyCGLASS = (not(myXGLASS[0]) && not(myXGLASS[1]) && not(myXGLASS[2]) && not(myYGLASS[0]) && not(myYGLASS[1]) && myYGLASS[2]) ||
			(not(myXGLASS[0]) && not(myXGLASS[1]) && not(myXGLASS[2]) && not(myYGLASS[0]) && (myYGLASS[1]) && myYGLASS[2]) ||
			(not(myXGLASS[0]) && not(myXGLASS[1]) && (myXGLASS[2]) && not(myYGLASS[0]) && (myYGLASS[1]) && not(myYGLASS[2])) ||
			(not(myXGLASS[0]) && (myXGLASS[1]) && not(myXGLASS[2]) && not(myYGLASS[0]) && (myYGLASS[1]) && myYGLASS[2]);
	*/
	//myTransitionRelationmyCGLASS = theT;
	//myMappingFromIntToExprForVerticesGLASS = theVertexToItsBooleanExpression;

	//myMappingFromIntToExprForVerticesGLASS.insert(std::pair<int, expr>(0, not(myXGLASS[0]) && not(myXGLASS[1]) && not(myXGLASS[2])));
	//myMappingFromIntToExprForVerticesGLASS.insert(std::pair<int, expr>(1, not(myXGLASS[0]) && not(myXGLASS[1]) && (myXGLASS[2])));
	/*myMappingFromIntToExprForVerticesGLASS.insert(std::pair<int, expr>(2, not(myXGLASS[0]) && (myXGLASS[1]) && not(myXGLASS[2])));
	myMappingFromIntToExprForVerticesGLASS.insert(std::pair<int, expr>(3, not(myXGLASS[0]) && (myXGLASS[1]) && (myXGLASS[2])));
	myMappingFromIntToExprForVerticesGLASS.insert(std::pair<int, expr>(4, (myXGLASS[0]) && not(myXGLASS[1]) && not(myXGLASS[2])));
	myMappingFromIntToExprForVerticesGLASS.insert(std::pair<int, expr>(5, (myXGLASS[0]) && not(myXGLASS[1]) && (myXGLASS[2])));
	myMappingFromIntToExprForVerticesGLASS.insert(std::pair<int, expr>(6, (myXGLASS[0]) && (myXGLASS[1]) && not(myXGLASS[2])));
	myMappingFromIntToExprForVerticesGLASS.insert(std::pair<int, expr>(7, (myXGLASS[0]) && (myXGLASS[1]) && (myXGLASS[2])));
	*/

/*	myStateInitialGLASS = givenInitialState;

	for(j1GLASS = 0; j1GLASS < *pp_nov; j1GLASS++) {
		std::cout << "\nThis is a vertex: " << j1GLASS << ". pushed";
		myVectorOfAllVerticesGLASS.push_back(j1GLASS);
	}

*/
	///////////////////////////////////////////////////////////////////////////////////////////////////////
/*	f01_calculateReachabilityDiameter(c, myTransitionRelationmyCGLASS, myXGLASS, myYGLASS, maxBitRequiredGLASS, myMappingFromIntToExprForVerticesGLASS,
			myVectorOfAllVerticesGLASS, myStateInitialGLASS,myStepwiseTransitionRelationGLASS, xES, yED, theT);
*/
	////////////////// rajdeeep end
	
	/*
	expr_vector	x(c), y(c);

    	int N;

	expr path(c); 
	expr loop(c);
	 
	solver	s(c);

	//std::cout << "\n\nEnter the no. of variables:->";
	//std::cin >> N;
	
	N = *p3_theMaxBit;
	std::cout << "\n\nN: " << N;            



	for(unsigned i=0; i<N; ++i){
		std::stringstream xName;
		xName << "x" << i;
		x.push_back(c.bool_const(xName.str().c_str()));
	}
	
	std::cout << "\n111111111111111111111\n";

	for(unsigned i=0; i<N; ++i){
		std::stringstream yName;
		yName << "y" << i;
		y.push_back(c.bool_const(yName.str().c_str()));
	}
	
	std::cout << "\nThis is x: " << x << "\n\n";
	std::cout << y << "\n\n";
	//getchar();

path=(!x[0]||x[0]); */

/*
      
        expr compeq=( (x[2]==y[2]) && (x[1]==y[1]) && (x[0]==y[0]));  
 
 	//
	//std::cout << "initial path is :" << path << "\n\n";
        loop=(!x[0] && x[0]); 
	//std::cout << "initial loop is :" << loop << "\n\n";

 */
 
 
   /*     expr compeq=c.bool_val(true);//=( (x[2]==y[2]) && (x[1]==y[1]) && (x[0]==y[0]));  




std::cout << "\n\n\n\n\n\nI need theT\n\n\n";

expr T(c);
T = theT;




 	std::cout << "\nGot theT: " << theT;
 	
 	*/
 
	//expr I=(!x[2] && !x[1] && !x[0]); // initial state formula - 000
	//expr I=(x[2] && !x[1] && !x[0]); // initial state formula - 100
	//expr I=(!x[1] && x[0]); // initial state formula - 0
 	
 	
 	/*expr I(c);//=(x[2] && !x[1] && !x[0]); // initial state formula - 100
 
	std::cout << "\nThe I: \n";
	std::cout << theIorF_I;

I = theIorF_I;


	std::cout << "\nThe IIIIIIIIIIII: \n";
	
	std::cout << I;

*/
	//std::cout << "I is :" << I << "\n\n";
	//std::cout << "T is :" << T << "\n\n";
        //return 0;
	//getchar();
/*
 	expr_vector	z(c);
	for(unsigned i=0; i<N; ++i){
		std::stringstream zName;
		zName << "x_0_" << i;
		z.push_back(c.bool_const(zName.str().c_str()));
	}
    	*/
  path=(!x[0] || x[0]); 

//	std::cout << "initiated path is :" << path << "\n\n";
 
	//return 0;  
 
 
 
 
 
 	N = *p3_theMaxBit;
 
int k=1; 
int max_nodes=pow(2,N);


for (k=1;k <= max_nodes;k++){

//creating path_d
// loop for creating variables [x_k-1_0, x_k-1_1, x_k-1_2]  = s_{k-1}             
        expr_vector	z0(c);
	for(unsigned i=0; i<N; ++i){
		std::stringstream z0Name;
		z0Name << "x_" << k-1 << "_" << i;
		z0.push_back(c.bool_const(z0Name.str().c_str()));
	}
// loop for creating variables [x_k_0, x_k_1, x_k_2] = s_k
        expr_vector	z1(c);
        
        

	for(unsigned i=0; i<N; ++i){
		std::stringstream z1Name;
		z1Name << "x_" << k << "_" << i;
		z1.push_back(c.bool_const(z1Name.str().c_str()));
	}
          std::cout<< z1<<"\n\n"; 
//          return 0; 
      
//subT is T(x,y) with x=(x0,x1,x2) replaced current state z0 and y=(y0,y1,y2) replaced by next state z1.
   
 
            
                expr subT(c);
                subT=T.substitute(y,z1);
                subT=subT.substitute(x,z0);
		std::cout << "At k="<<k<<" subT : " << subT << "\n\n"; 

                path=path && subT;
		std::cout << "At k="<<k<<"path is: " << path << "\n\n"; 
                
 
 
 
 
// Todo: debug from below
// implement equality checking 
//



        loop=(!x[0] && !x[0]);  //reset loop condition
	for(unsigned j=0;j <= (k-1);j++){ //create loop_d  for d >= 1
        	expr_vector zd(c); // loop for creating variables [x_d_0, x_d_1,x_d_2]= s_d
		for(unsigned i=0; i<N; ++i){
			std::stringstream zdName;
			zdName << "x_" << k << "_" << i;
			zd.push_back(c.bool_const(zdName.str().c_str()));
		}
 
        	expr subL(c);
 	        subL=compeq.substitute(x,zd);
	
       		expr_vector zj(c); // loop for creating variables [x_j_0, x_j_1,x_j_2]= s_j
		for(unsigned i=0; i<N; ++i){
			std::stringstream zjName;
			zjName << "x_" << j << "_" << i;
			zj.push_back(c.bool_const(zjName.str().c_str()));
		}
 
//// next  line: generate subL. 
 
       		subL=subL.substitute(y,zj);
		std::cout <<"at k="<<k<<"subL is: "<<subL<<"\n\n";
		//getchar(); 
		loop = loop || subL; 
	}// end of for index j  
 
		std::cout <<"at k="<<k<<"loop is: "<<loop<<"\n\n";
		


		
		
               // getchar(); 
 
 
//// meta logic below seems okay.  
 


	s.add(path && (!loop));
        if(s.check()==unsat){
		int rd=k;
		std::cout<<"\n\n rd="<< rd <<"\n\n"; 
             //   getchar();
		exit(0);
        } // found rd exit
	else{
		std::cout<<"Satisfiable. Printing the model"<<"\n\n";
		model m=s.get_model();
	        for (unsigned i = 0; i < m.size(); i++) {
            		func_decl v = m[i];
	    		std:: cout << v.name() << " = " << m.get_const_interp(v) << "\t";
        	}
		std::cout << "\n\n";
		s.reset();
        }
        
        
        
 
 
} //end of outer for loop with index k 
			std::cout<<"\n\n Reached  max limit\n\n";

	        return 0; 
} //end of main 




void f01_calculateReachabilityDiameter(context &myC, 	expr myTransitionRelation, expr_vector &myX, expr_vector &myY,
		int maxBitRequired, std::map<int, expr> myMappingFromIntToExprForVertices, std::vector<int> myVectorOfAllVertices,
		int myStateInitialInt, expr_vector &myStepwiseTransitionRelation, expr_vector &xES, expr_vector &yED, expr theT) {

	int j1, j2, totalNumberOfStates, j3;
	unsigned int j4;
	int j5;
	expr myStateInitialExpr(myC), myStateFinalExpr(myC), myStateFinalExprBelow(myC);
	std::map<int, expr>::iterator i1_myMappingFromIntToExprForVertices;
	expr_vector myINIT(myC), myFINA(myC);
	expr myTransitionRelationCOPY1(myC);
	expr tranTranTran(myC), theExpression(myC);
	check_result myResult;
	solver mySolver(myC);
	model myModel(myC);
	std::vector<int> allShortestPathLength;
	std::vector<int>::iterator theRecurrenceDia;



	totalNumberOfStates = myVectorOfAllVertices.size();

	i1_myMappingFromIntToExprForVertices = myMappingFromIntToExprForVertices.find(myStateInitialInt);
	myStateInitialExpr = i1_myMappingFromIntToExprForVertices->second;
	std::cout << "\n::myStateInitialExpr before substitute: " << myStateInitialExpr;
	std::cout << "\n::Check size of the adjacency list of inputtttttttt: " ;



	while(myINIT.size() > 0)
		myINIT.pop_back();
	for(j1 = 0; j1 < maxBitRequired; j1++) {
		std::stringstream myZ_forInitialState;
		myZ_forInitialState << "s_" << j1 << "_0";
		myINIT.push_back(myC.bool_const(myZ_forInitialState.str().c_str()));
	}

	myStateInitialExpr = myStateInitialExpr.substitute(myX, myINIT);
	std::cout << "\n::myStateInitialExpr after substitute: " << myStateInitialExpr;

	std::cout << "\nHy gogo";
	std::cout << "\nmyStepwiseTransitionRelation size: " << myStepwiseTransitionRelation.size();


	std::cout << "\nmaxBitRequired: " << maxBitRequired;
	std::cout << "\nmyTransitionRelation: " << myTransitionRelation;
	std::cout << "\nmyVectorOfAllVertices.size(): " << myVectorOfAllVertices.size();
	std::cout << "\nxES.size(): " << xES.size();


	for(j4 = 0; j4 < myVectorOfAllVertices.size() - 1; j4++) {
		std::cout << "\n\nj4Combo: " << j4 << " : " << j4 + 1;
		std::cout << "\nmaxBitRequired: " << maxBitRequired;


		while(myINIT.size() > 0)
			myINIT.pop_back();
		for(j5 = 0; j5 < maxBitRequired; j5++) {
			std::stringstream j5Source;
			j5Source << "s_" << j5 << "_" << j4;
			myINIT.push_back(myC.bool_const(j5Source.str().c_str()));
		}
		std::cout << "\nmyINIT[0: " << myINIT[0];

		while(myFINA.size() > 0)
			myFINA.pop_back();
		for(j5 = 0; j5 < maxBitRequired; j5++) {
			std::stringstream j5Source;
			j5Source << "s_" << j5 << "_" << j4 + 1;
			myFINA.push_back(myC.bool_const(j5Source.str().c_str()));
		}
		std::cout << "\nmyFINA[0]: " << myFINA[0];
		std::cout << "\nyED[0]: " << yED[0];

		//myTransitionRelationCOPY1 = myTransitionRelation.substitute(myY, myFINA);
		myTransitionRelationCOPY1 = myTransitionRelation.substitute(yED, myFINA);
		//std::cout << "\nSubstituted yed: " << myTransitionRelationCOPY1;
		//myTransitionRelationCOPY1 = myTransitionRelationCOPY1.substitute(myX, myINIT);
		myTransitionRelationCOPY1 = myTransitionRelationCOPY1.substitute(xES, myINIT);
		std::cout << "\nSubstituted both xes: " << myTransitionRelationCOPY1;
		myStepwiseTransitionRelation.push_back(myTransitionRelationCOPY1);
	}

	std::cout << "\nCheck. myStepwiseTransitionRelation. size: " << myStepwiseTransitionRelation.size();

	for(expr_vector::iterator i2_myStepwiseTransitionRelation = myStepwiseTransitionRelation.begin(); i2_myStepwiseTransitionRelation != myStepwiseTransitionRelation.end(); i2_myStepwiseTransitionRelation++) {
		std::cout << "\n##: " << *i2_myStepwiseTransitionRelation;
	}







	std::cout << "\ntotalNumberOfStates " << totalNumberOfStates;

	for(j1 = 0; j1 < totalNumberOfStates; j1++) {
//	for(j1 = totalNumberOfStates - 1; j1 > 0; j1--) {
		std::cout << "\n\n************************************************";
		std::cout << "\nIn j1. Searching for state " << j1;


		i1_myMappingFromIntToExprForVertices = myMappingFromIntToExprForVertices.find(j1);
		myStateFinalExpr = i1_myMappingFromIntToExprForVertices->second;
		std::cout << "\nmyStateFinalExpr: " << myStateFinalExpr;










		for(j2 = 0; j2 < totalNumberOfStates; j2++) {
		//for(j2 =  totalNumberOfStates - 1; j2 > 0; j2++) {

			std::cout << "\n\nIn j2. Searching at path length " << j2;
			if(j2 == 0) {
				std::cout << "\nSearching for path length = 0";
				if(j1 == myStateInitialInt) {
					std::cout << "\nGot state initial state at path length 0. State: " << j1;
					break;
				}
			}
			else {
				std::cout << "\nSearching for path length > 0";
				std::cout << "\n==. Check. myStateInitialExpr: " << myStateInitialExpr;
				//std::cout << "\n==. Check. j2: " << j2;


				while(myFINA.size() > 0)
					myFINA.pop_back();
				for(j3 = 0; j3 < maxBitRequired; j3++) {//myStateFinalExprBelow
					std::stringstream myZ_forFinalState;
					myZ_forFinalState << "s_" << j3 << "_" << j2;
					myFINA.push_back(myC.bool_const(myZ_forFinalState.str().c_str()));
				}
				myStateFinalExprBelow = myStateFinalExpr.substitute(myX, myFINA);
				std::cout << "\n==. Check. myStateFinalExprBelow: " << myStateFinalExprBelow;

				std::cout << "\n==. Check. T: ";

				tranTranTran = myC.bool_val(true);
				for(int rr = 0; rr < j2; rr++) {


					std::cout << "\ntrr: " << rr << " IS " << myStepwiseTransitionRelation[rr];
					tranTranTran = tranTranTran && myStepwiseTransitionRelation[rr];
				}
				std::cout << "\ntranTranTran: " << tranTranTran;

				theExpression = myStateInitialExpr && myStateFinalExprBelow && tranTranTran;

				myResult = mySolver.check(1, &theExpression);
				std::cout << "\nSAT OR UNSAT: " << myResult;

				if(myResult == unsat) {
					std::cout << "\nShortest path does not exist for length " << j2;
				}
				else if(myResult == sat) {
					std::cout << "\nShortest path exists for length " << j2;
					allShortestPathLength.push_back(j2);
					break;
				}
				else {
					std::cout << "\nImpossible -1";
				}
			}
		}
	}


	for(std::vector<int>::iterator tw = allShortestPathLength.begin(); tw != allShortestPathLength.end(); tw++) {
		std::cout << "\n" << *tw;
	}
	std::cout << "\n\n\nWhat is this: ";
	std::max_element(allShortestPathLength.begin(), allShortestPathLength.end());

	std::cout << "\n\n";

	std::sort(allShortestPathLength.begin(), allShortestPathLength.end());

	for(std::vector<int>::iterator tw = allShortestPathLength.begin(); tw != allShortestPathLength.end(); tw++) {
		std::cout << "\n" << *tw;
	}




	std::cout << "\ntheRechabilityeDiameter: " << *(std::max_element(allShortestPathLength.begin(), allShortestPathLength.end()));
	std::cout << "This is the line we need: " << theT;

	return ;//*(std::max_element(allShortestPathLength.begin(), allShortestPathLength.end()));
	
	
}



void f01_controlFunctionForReachability(std::string myFileName, std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors,
		int *p3_theMaxBit, std::map<int, expr> &theVertexToItsBooleanExpression, expr_vector &xES, expr_vector &yED,
		context *c, expr &theT, expr &theIorF_I, expr &theIorF_F, int *pp_nov, int givenInitialState) {
	std::vector<int> theSortedVectorOfVertices;
	std::vector<int> *p2_theSortedVectorOfVertices;
	int existInitialState, existFinalState;


	std::map<int, std::vector<int> > integerToBinaryForAllVertices;
	std::map<int, std::vector<int> > *p4_integerToBinaryForAllVertices;

	p2_theSortedVectorOfVertices = &theSortedVectorOfVertices;
	p4_integerToBinaryForAllVertices = &integerToBinaryForAllVertices;
	existInitialState = 0;
	existFinalState = 0;


	f02_readTheInputFileAndGiveMeVectorOfVectors(myFileName, p1_theInputFile_vectorOfVectors);
/*
	std::cout << "\n\nCheck f02";
	for(std::vector<std::vector<int> >::iterator i1_ = (*p1_theInputFile_vectorOfVectors).begin(); i1_ != (*p1_theInputFile_vectorOfVectors).end(); i1_++) {
		std::cout << "\n" << (*i1_)[0] << " " << (*i1_)[1];
	}
*/

	f03_giveMeTheSortedvectorOfVertices(p1_theInputFile_vectorOfVectors, p2_theSortedVectorOfVertices);
//	std::cout << "\n\nCheck f03: ";
	for(std::vector<int>::iterator i2_ = theSortedVectorOfVertices.begin(); i2_ != theSortedVectorOfVertices.end(); i2_++) {
		//std::cout << *i2_ << " ";
		if(*i2_ == givenInitialState)
			existInitialState = 1;
	}



	if(existInitialState == 1 ) {
		*pp_nov = theSortedVectorOfVertices.size();
		f04_findNumberOfMaxBitrequired(theSortedVectorOfVertices, p3_theMaxBit);
		f05_integerToBinaryForAllVertices(p2_theSortedVectorOfVertices, p4_integerToBinaryForAllVertices, p3_theMaxBit, c, theVertexToItsBooleanExpression);

//std::cout << "\n\nCheck f05";
/*
		for(std::map<int, std::vector<int> >::iterator i3_ = integerToBinaryForAllVertices.begin(); i3_ != integerToBinaryForAllVertices.end(); i3_++) {
			std::cout << "\n" << i3_->first << " : ";
			std::vector<int> temp1 = i3_->second;
			for(std::vector<int>::iterator i4_ = temp1.begin(); i4_ != temp1.end(); i4_++) {
				std::cout << *i4_ << " ";
			}
		}

*/


		expr dharwad(*c);
		expr_vector XES(*c);
		/*
		for(int ej1 = 0
		
		
		
		
		
		
		
		
		
		; ej1 < *p3_theMaxBit; ej1++) {
			std::stringstream x, y;

			x << "x_" << ej1;

			XES.push_back((*c).bool_const(x.str().c_str()));
			//yED.push_back((*c).bool_const(y.str().c_str()));
		}
*/












		f07_createEdgeToBooleanExpression2(p1_theInputFile_vectorOfVectors, integerToBinaryForAllVertices, theVertexToItsBooleanExpression, xES, yED, p3_theMaxBit, c, theT, givenInitialState);
/*
		std::cout << "\n\nCheck f07 in f01";

		std::cout << "\nHa ha. xES[0]: " << xES[0];
		std::cout << "\nHa ha. xES[1]: " << xES[1];
		std::cout << "\nHa ha. xES[2]: " << xES[2];
		std::cout << "\nHa ha. yED[0]: " << yED[0];
		std::cout << "\nHa ha. yED[1]: " << yED[1];
		std::cout << "\nHa ha. yED[2]: " << yED[2];

		std::cout << "\nIn f01. theT: " << theT;
*/

		f08_createVertexToBooleanExpression(p1_theInputFile_vectorOfVectors, integerToBinaryForAllVertices, xES, p3_theMaxBit, c, theIorF_I, givenInitialState);
		
		std::cout << "\n\nSTOP here";
		std::cout << "\ntheT test: " << theT;
		std::cout << "\nNeed I\n" << theIorF_I;
	}
	/*
	else {
		std::cout << "\nInput/output combination does not exist in the graph txt file";
		std::cout << "\ngivenInitialState: " << givenInitialState;
		std::cout << "\n\n";
		exit(0);
	}*/


	return;
}

void f02_readTheInputFileAndGiveMeVectorOfVectors(std::string myFileName, std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors) {
	std::ifstream myFileStream(myFileName);
	int j1, j2;
    std::vector<int> myOneEdge;
     std::ofstream fout("theInputGraph.gv");


fout << "digraph G1 {\n";

	while(myFileStream >> j1 >> j2) {
	    myOneEdge.push_back(j1);
	    myOneEdge.push_back(j2);
	    (*p1_theInputFile_vectorOfVectors).push_back(myOneEdge);
	    myOneEdge.clear();
	    
	    fout << j1 << " -> " << j2 << ";\n";   //write data to the file student

	    
	}
	fout << "}";
      fout.close();
myFileStream.close();

	return;
}


void f03_giveMeTheSortedvectorOfVertices(std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors, std::vector<int> *p2_theSortedVectorOfVertices) {
	std::set<int> theSetOfVertices;

	for(std::vector<std::vector<int> >::iterator i1 = (*p1_theInputFile_vectorOfVectors).begin(); i1 != (*p1_theInputFile_vectorOfVectors).end(); i1++) {
		theSetOfVertices.insert((*i1)[0]);
		theSetOfVertices.insert((*i1)[1]);
	}

	for(std::set<int>::iterator i2 = theSetOfVertices.begin(); i2 != theSetOfVertices.end(); i2++) {
		(*p2_theSortedVectorOfVertices).push_back(*i2);
	}

	std::sort((*p2_theSortedVectorOfVertices).begin(),(*p2_theSortedVectorOfVertices).end());

	return;
}

void f04_findNumberOfMaxBitrequired(std::vector<int> theSortedVectorOfVertices, int *theMaxBitrequired) {
	int theLargestNumber = theSortedVectorOfVertices[theSortedVectorOfVertices.size() - 1];
	int quo, counter = 0;

	while(theLargestNumber > 0) {
		quo = theLargestNumber / 2;
		//rem = theLargestNumber % 2;
		counter++;
		theLargestNumber = quo;
	}

	*theMaxBitrequired = counter;
	//std::cout << "\n*theMaxBitrequired: " << *theMaxBitrequired;

	return;
}


void f05_integerToBinaryForAllVertices(std::vector<int> *p2_theSortedVectorOfVertices, std::map<int, std::vector<int> > *p4_integerToBinaryForAllVertices, int *p3_theMaxBit, context *c, std::map<int, expr> &theVertexToItsBooleanExpression) {
	std::cout << "\nIn f05";

	std::vector<int> theBinary;
	std::vector<int> *p1_theBinary;
	expr theExp(*c);

	expr_vector XES(*c);

	p1_theBinary = &theBinary;


	for(int ej1 = 0; ej1 < *p3_theMaxBit; ej1++) {
		std::stringstream x, y;

		x << "x_" << ej1;

		XES.push_back((*c).bool_const(x.str().c_str()));
		//yED.push_back((*c).bool_const(y.str().c_str()));
	}



	for(std::vector<int>::iterator i1 = (*p2_theSortedVectorOfVertices).begin(); i1 != (*p2_theSortedVectorOfVertices).end(); i1++) {
		//std::cout << "\n" << *i1 << " Vs. ";
		(*p1_theBinary).clear();
		f06_decimalToBinary(*i1, p1_theBinary);

		for(int j1 = (*p1_theBinary).size(); j1 < *p3_theMaxBit; j1++)
			(*p1_theBinary).push_back(0);
		std::reverse((*p1_theBinary).begin(), (*p1_theBinary).end());

/*
		for(std::vector<int>::iterator i2 = theBinary.begin(); i2 != theBinary.end(); i2++) {
			std::cout << *i2 << " ";
		}
*/

		(*p4_integerToBinaryForAllVertices).insert(std::pair<int, std::vector<int> >(*i1, theBinary));

		//std::cout << "\nGoing for expression creation: ";
		if(theBinary[0] == 0)
			theExp = not(XES[0]);
		else
			theExp = (XES[0]);

		for(unsigned int re = 1; re < theBinary.size(); re++) {
			if(theBinary[re] == 0)
				theExp= theExp && not(XES[re]);
			else
				theExp= theExp && (XES[re]);
		}

		std::cout << "\nTesting. theExp: " << theExp;
		theVertexToItsBooleanExpression.insert(std::pair<int, expr>(*i1, theExp));
	}


	return;
}

void f06_decimalToBinary(int theDecimal, std::vector<int> *p1_theBinaryVector) {
	int theNumber = theDecimal;
	int rem;

	//std::cout << ". In f06. ";

	while(theNumber > 0) {
		rem = theNumber % 2;
		(*p1_theBinaryVector).push_back(rem);
		theNumber = theNumber / 2;
	}

	return;
}


void f07_createEdgeToBooleanExpression2(std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors,
		std::map<int, std::vector<int> > integerToBinaryForAllVertices, std::map<int, expr> &theVertexToItsBooleanExpression,
		expr_vector &xES, expr_vector &yED, int *p3_theMaxBit, context *c, expr &theT, int givenInitialState) {
	std::cout << "\nIn f07-2";
	std::cout << "\nintegerToBinaryForAllVertices size: " << integerToBinaryForAllVertices.size();
	int k1, k2;

	int edgeNumber = 0;
	int firstExp1, firstExp2;
	int sizeOfTheAdjacencyListOfInitialState = -5;



    expr theX(*c), theY(*c);
    expr tx1(*c);
    expr tx2(*c);

    expr theTtemp(*c);


	std::map<int, expr> TEMP;

	//theT = (*c).bool_val(false);
	edgeNumber = 0;

	for(int j1 = 0; j1 < *p3_theMaxBit; j1++) {
		std::stringstream x, y;

		x << "x_" << j1;
		y << "y_" << j1;
		xES.push_back((*c).bool_const(x.str().c_str()));
		yED.push_back((*c).bool_const(y.str().c_str()));
	}



	std::cout << "\nBefore for loop. sizeOfTheAdjacencyListOfInitialState: " << sizeOfTheAdjacencyListOfInitialState;

	//std::cout << "\nCheck parameters. p1_theInputFile_vectorOfVectors: ";
	for(std::vector<std::vector<int> >::iterator i3 = (*p1_theInputFile_vectorOfVectors).begin(); i3 != (*p1_theInputFile_vectorOfVectors).end(); i3++, edgeNumber++) {
		std::vector<int> tempo = *i3;

		if(edgeNumber == 0) {
			//std::cout << "\n\nedgeNumber=0: " << edgeNumber;
			//std::cout << "\n===one Edge: " << tempo[0] << " to " << tempo[1];
			std::map<int, std::vector<int> >::iterator p1;

			p1 = integerToBinaryForAllVertices.find(tempo[0]);
			if(p1->first == givenInitialState)
				sizeOfTheAdjacencyListOfInitialState = 1;

			if(p1 != integerToBinaryForAllVertices.end()) {
				//std::cout << " EXIST_SOURCE: ";

				k1 = 0;
			    //theX = (*c).bool_val(true);


				std::vector<int> temp5 = p1->second;
				firstExp1 = 0;
				for(std::vector<int>::iterator i4 = temp5.begin(); i4 != temp5.end(); i4++, k1++, firstExp1++) {
					//std::cout << *i4 << " ";
					if(*i4 == 0) {
						theX = not(xES[k1]);
						//std::cout << "[" << theX << "]";
					}
					else if(*i4 == 1) {
						theX = xES[k1];
						//std::cout << "[" << theX << "]";
					}
					else {
						std::cout << "\nImpossible condition-1";
					}

					if(firstExp1 == 0) {
						tx1 = theX;
					}
					else {
						tx1 = tx1 && theX;
					}


				}

				std::cout << "\ntx1: " << tx1;

			}
			else {
				std::cout << " Wrong Logic-1";
			}


			std::map<int, std::vector<int> >::iterator p2;

			p2 = integerToBinaryForAllVertices.find(tempo[1]);
			if(p2 != integerToBinaryForAllVertices.end()) {
				//std::cout << " EXIST_DESTINATION: ";

				k2 = 0;

				std::vector<int> temp6 = p2->second;
				firstExp2 = 0;
				for(std::vector<int>::iterator i4 = temp6.begin(); i4 != temp6.end(); i4++, k2++, firstExp2++) {
					//std::cout << *i4 << " ";
				///
					if(*i4 == 0) {
						theY = not(yED[k2]);
						//std::cout << theY;
					}
					else if(*i4 == 1) {
						theY = yED[k2];
						//std::cout << theY;
					}
					else {
						std::cout << "\nImpossible condition-2";
					}
					if(firstExp2 == 0) {
						tx2 = theY;
					}
					else {
						tx2 = tx2 && theY;
					}
				////
				}
				std::cout << "\ntx2: " << tx2;
			}
			else {
				std::cout << " Wrong Logic-2";
			}

			//std::cout << "\ntheX: " << theX;
			//std::cout << "\ntheY: " << theY;

			theT = tx1 && tx2;
			//std::cout << "\ntheT: " << theT;

		}
		else {
			//std::cout << "\n\nedgeNumber > 0: " << edgeNumber;
			//std::cout << "\nedgeNumber=0: " << edgeNumber;
			//std::cout << "\n===one Edge: " << tempo[0] << " to " << tempo[1];
			std::map<int, std::vector<int> >::iterator p1;

			p1 = integerToBinaryForAllVertices.find(tempo[0]);

			if(p1->first == givenInitialState)
				sizeOfTheAdjacencyListOfInitialState = 2;


			if(p1 != integerToBinaryForAllVertices.end()) {
				//std::cout << " EXIST_SOURCE: ";

				k1 = 0;
			    //theX = (*c).bool_val(true);


				std::vector<int> temp5 = p1->second;
				firstExp1 = 0;
				for(std::vector<int>::iterator i4 = temp5.begin(); i4 != temp5.end(); i4++, k1++, firstExp1++) {
					//std::cout << *i4 << " ";
					if(*i4 == 0) {
						theX = not(xES[k1]);
						//std::cout << "[" << theX << "]";
					}
					else if(*i4 == 1) {
						theX = xES[k1];
						//std::cout << "[" << theX << "]";
					}
					else {
						std::cout << "\nImpossible condition-3";
					}

					if(firstExp1 == 0) {
						tx1 = theX;
					}
					else {
						tx1 = tx1 && theX;
					}


				}

				std::cout << "\n\ntx1: " << tx1;

			}
			else {
				std::cout << " Wrong Logic-3";
			}


			std::map<int, std::vector<int> >::iterator p2;

			p2 = integerToBinaryForAllVertices.find(tempo[1]);
			if(p2 != integerToBinaryForAllVertices.end()) {
				//std::cout << " EXIST_DESTINATION: ";

				k2 = 0;

				std::vector<int> temp6 = p2->second;
				firstExp2 = 0;
				for(std::vector<int>::iterator i4 = temp6.begin(); i4 != temp6.end(); i4++, k2++, firstExp2++) {
					//std::cout << *i4 << " ";
				///
					if(*i4 == 0) {
						theY = not(yED[k2]);
						//std::cout << theY;
					}
					else if(*i4 == 1) {
						theY = yED[k2];
						//std::cout << theY;
					}
					else {
						std::cout << "\nImpossible condition-4";
					}
					if(firstExp2 == 0) {
						tx2 = theY;
					}
					else {
						tx2 = tx2 && theY;
					}
				////
				}
				std::cout << "\ntx2: " << tx2;

			}
			else {
				std::cout << " Wrong Logic-4";
			}

			//std::cout << "\ntheX: " << theX;
			//std::cout << "\ntheY: " << theY;

			theTtemp = tx1 && tx2;

			theT = theT || theTtemp ;
			//std::cout << "\nTheT: " << theT;
		}
	}
	std::cout << "I need this";
	//std::cout << "\nAfter for loop. sizeOfTheAdjacencyListOfInitialState: " << sizeOfTheAdjacencyListOfInitialState;

	//std::cout << "\nOUTSIDE TheT: " << theT;

	if(sizeOfTheAdjacencyListOfInitialState == -5) {
		std::cout << "\nNo outgoing edge exists from the given initial state. So reachability diameter is 0 \n\n" << givenInitialState;

		exit(0);
	}



	return;
}



void f07_createEdgeToBooleanExpression1(std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors, std::map<int, std::vector<int> > integerToBinaryForAllVertices, std::map<int, expr> &theVertexToItsBooleanExpression, expr_vector &xES, expr_vector &yED, int *p3_theMaxBit, context *c, expr &theT) {
	std::cout << "\nIn f07-1";
	int k1, k2;

	//int edgeNumber;



    expr theX(*c), theY(*c);


	std::map<int, expr> TEMP;

	theT = (*c).bool_val(false);
	//edgeNumber = 0;

	for(int j1 = 0; j1 < *p3_theMaxBit; j1++) {
		std::stringstream x, y;

		x << "x_" << j1;
		y << "yy_" << j1;
		xES.push_back((*c).bool_const(x.str().c_str()));
		yED.push_back((*c).bool_const(y.str().c_str()));
	}




	std::cout << "\nCheck parameters. p1_theInputFile_vectorOfVectors: ";
	for(std::vector<std::vector<int> >::iterator i3 = (*p1_theInputFile_vectorOfVectors).begin(); i3 != (*p1_theInputFile_vectorOfVectors).end(); i3++) {
		std::vector<int> tempo = *i3;
		std::cout << "\n\n===one Edge: " << tempo[0] << " to " << tempo[1];
		std::map<int, std::vector<int> >::iterator p1;

		p1 = integerToBinaryForAllVertices.find(tempo[0]);
		if(p1 != integerToBinaryForAllVertices.end()) {
			std::cout << " EXIST_SOURCE: ";

			k1 = 0;
		    theX = (*c).bool_val(true);

			std::vector<int> temp5 = p1->second;
			for(std::vector<int>::iterator i4 = temp5.begin(); i4 != temp5.end(); i4++, k1++) {
				std::cout << *i4 << " ";
				if(*i4 == 0) {
					theX = theX && not(xES[k1]);
					//std::cout << theX;
				}
				else if(*i4 == 1) {
					theX = theX && xES[k1];
					//std::cout << theX;
				}
				else {
					std::cout << "\nImpossible-1";
				}
			}

		}
		else {
			std::cout << " Wrong Logic";
		}


		std::map<int, std::vector<int> >::iterator p2;

		p2 = integerToBinaryForAllVertices.find(tempo[1]);
		if(p2 != integerToBinaryForAllVertices.end()) {
			std::cout << " EXIST_DESTINATION: ";

			k2 = 0;
		    theY = (*c).bool_val(true);

			std::vector<int> temp6 = p2->second;
			for(std::vector<int>::iterator i4 = temp6.begin(); i4 != temp6.end(); i4++, k2++) {
				std::cout << *i4 << " ";
			///
				if(*i4 == 0) {
					theY = theY && not(yED[k2]);
					//std::cout << theY;
				}
				else if(*i4 == 1) {
					theY = theY && yED[k2];
					//std::cout << theY;
				}
				else {
					std::cout << "\nImpossible-2";
				}
			////
			}

		}
		else {
			std::cout << " Wrong Logic";
		}

		std::cout << "\ntheX: " << theX;
		std::cout << "\ntheY: " << theY;

		theT = theT || (theX && theY);

	}

	std::cout << "\nTheT: " << theT;

	std::cout << "\nCheck parameters. integerToBinaryForAllVertices: ";
	for(std::map<int, std::vector<int> >::iterator i1 = integerToBinaryForAllVertices.begin(); i1 != integerToBinaryForAllVertices.end(); i1++) {
		int g1 = i1->first;
		std::vector<int> g2 = i1->second;

		std::cout << "\n" << g1 << " = ";
		for(std::vector<int>::iterator i2 = g2.begin(); i2 != g2.end(); i2++) {
			std::cout << *i2 << " ";
		}
	}








	return;
}



void f08_createVertexToBooleanExpression(std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors, std::map<int, std::vector<int> > integerToBinaryForAllVertices, expr_vector xES, int *p3_theMaxBit, context *c, expr &theIorF, int iORf) {
	//std::cout << "\nIn f08";
	int k1/*, k2*/;

	//int edgeNumber = 0;
	int firstExp1;



    expr theX(*c);
    expr tx1(*c);
    expr tx2(*c);

    expr theTtemp(*c);


	std::map<int, expr> TEMP;


/*

	for(int j1 = 0; j1 < *p3_theMaxBit; j1++) {
		std::stringstream x, y;

		x << "x_" << j1;
		y << "yy_" << j1;
		xES.push_back((*c).bool_const(x.str().c_str()));
	}
*/
	//std::cout << "\n===one VERTEX ONLY: " << iORf;
	std::map<int, std::vector<int> >::iterator p1;

	p1 = integerToBinaryForAllVertices.find(iORf);
	if(p1 != integerToBinaryForAllVertices.end()) {
		//std::cout << " IT EXIST_: ";

		k1 = 0;
		//theX = (*c).bool_val(true);


		std::vector<int> temp5 = p1->second;
		firstExp1 = 0;
		for(std::vector<int>::iterator i4 = temp5.begin(); i4 != temp5.end(); i4++, k1++, firstExp1++) {
			//std::cout << *i4 << " ";
			if(*i4 == 0) {
				theX = not(xES[k1]);
				//std::cout << "[" << theX << "]";
			}
			else if(*i4 == 1) {
				theX = xES[k1];
				//std::cout << "[" << theX << "]";
			}
			else {
				std::cout << "\nImpossible condition-5";
			}

			if(firstExp1 == 0) {
				tx1 = theX;
			}
			else {
				tx1 = tx1 && theX;
			}
		}

		//std::cout << "\ntx1: " << tx1;
	}
	else {
		std::cout << " Wrong Logic-5";
	}
	//std::cout << "\ntheX: " << theX;

	theIorF = tx1;
	//std::cout << "\ntheIorF: " << theIorF;
	return;
}


