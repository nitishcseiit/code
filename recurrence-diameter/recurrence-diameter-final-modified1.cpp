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
#include <math.h>


using namespace z3;


void f01_controlFunctionForReachability(std::string theFileName, std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors, int *p3_theMaxBit,
		std::map<int, expr> &theVertexToItsBooleanExpression, expr_vector &xES, expr_vector &yED, context *c, expr &theT, expr &theIorF_I, expr &theIorF_F, int *pp_nov, int givenInitialState, int givenFinalState);
void f02_readTheInputFileAndGiveMeVectorOfVectors(std::string theFileName, std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors);
void f03_giveMeTheSortedvectorOfVertices(std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors, std::vector<int> *p2_theSortedVectorOfVertices);
void f04_findNumberOfMaxBitrequired(std::vector<int> theSortedVectorOfVertices, int *theMaxBitrequired);
void f05_integerToBinaryForAllVertices(std::vector<int> *p2_theSortedVectorOfVertices, std::map<int, std::vector<int> > *p4_integerToBinaryForAllVertices, int *p3_theMaxBit);
void f06_decimalToBinary(int theDecimal, std::vector<int> *p1_theBinaryVector);
void f07_createEdgeToBooleanExpression2(std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors, std::map<int, std::vector<int> > integerToBinaryForAllVertices, std::map<int, expr> &theVertexToItsBooleanExpression, expr_vector &xES, expr_vector &yED, int *p3_theMaxBit, context *c, expr &theT);
void f07_createEdgeToBooleanExpression1(std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors, std::map<int, std::vector<int> > integerToBinaryForAllVertices, std::map<int, expr> &theVertexToItsBooleanExpression, expr_vector &xES, expr_vector &yED, int *p3_theMaxBit, context *c, expr &theT);

void f08_createVertexToBooleanExpression(std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors, std::map<int,
		std::vector<int> > integerToBinaryForAllVertices, expr_vector xES, int *p3_theMaxBit, context *c, expr &theIorF, int iORf);


int main(int argc, char **argv) {
	context		c;
	expr_vector	x(c), y(c);


	//std::cout << "initial loop is :" << loop << "\n\n";
/*	
	s.add(path);
        if(s.check()==sat){
		std::cout<<"initial value of path is true"<<"\n\n";
                s.reset(); 
        }
        else{
		std::cout<<"initial value of path is false"<<"\n\n";
		return 0; 

        }
         
 
 	s.add(loop);
        if(s.check()==unsat){
		std::cout<<"initial value of loop is false"<<"\n\n";
                s.reset(); 
        }
        else{
		std::cout<<"initial value of path is true"<<"\n\n";
		return 0; 

        }
         
*/ 
 
 
 
/* 
// a complete graph with one nodes
// s0->s0; 
	expr T=(((!x[2] && !x[1] && !x[0]) && (!y[2] && !y[1] && !y[0])) 
               ); 
 
*/
 
 
/* 
// a line graph with two nodes
// s0->s1; 
	expr T=(((!x[2] && !x[1] && !x[0]) && (!y[2] && !y[1] && y[0]))
               ); 
*/

/*
// s0->s1; s1->s0; 
	expr T=(((!x[2] && !x[1] && !x[0]) && (!y[2] && !y[1] && y[0])) ||  
		 ((!x[2] && !x[1] && x[0]) && (!y[2] && !y[1] && !y[0]))
               ); 
 
	expr I=(!x[2] && !x[1] && !x[0]); // initial state formula - 000
*/

/* 
// a complete graph with three nodes. 
// s0->s1; s1->s0; s1->s2;s2->s1; s2->s0;s0->s2
	expr T=(((!x[2] && !x[1] && !x[0]) && (!y[2] && !y[1] && y[0])) ||  
		 ((!x[2] && !x[1] && x[0]) && (!y[2] && !y[1] && !y[0])) ||
		 ((!x[2] && !x[1] && x[0]) && (!y[2] && y[1] && !y[0])) ||
		 ((!x[2] && x[1] && !x[0]) && (!y[2] && !y[1] && y[0])) ||
		 ((!x[2] && x[1] && !x[0]) && (!y[2] && !y[1] && !y[0])) ||
		 ((!x[2] && !x[1] && !x[0]) && (!y[2] && y[1] && !y[0]))
               ); 
 
	expr I=(!x[2] && !x[1] && !x[0]); // initial state formula - 000

*/ 
 
//cycle of four nodes
//s0->s1;s1->s2;s2->s3;s3->s0

/*  
 	expr T=(((!x[2] && !x[1] && !x[0]) && (!y[2] && !y[1] && y[0])) ||  
		 ((!x[2] && !x[1] && x[0]) && (!y[2] && y[1] && !y[0])) ||
		 ((!x[2] && x[1] && !x[0]) && (!y[2] && y[1] && y[0])) ||
		 ((!x[2] && x[1] && x[0]) && (!y[2] && !y[1] && !y[0]))
               ); 
 
	expr I=(!x[2] && !x[1] && !x[0]); // initial state formula - 000

*/ 

/* 
 //reverse cycles for all four nodes
//s0->s1;s1->s2;s2->s3;s3->s0
//s1->s0;s2->s1;s3->s2;s0->s3

 	expr T=(((!x[2] && !x[1] && !x[0]) && (!y[2] && !y[1] && y[0])) ||  
		 ((!x[2] && !x[1] && x[0]) && (!y[2] && y[1] && !y[0])) ||
		 ((!x[2] && x[1] && !x[0]) && (!y[2] && y[1] && y[0])) ||
		 ((!x[2] && x[1] && x[0]) && (!y[2] && !y[1] && !y[0]))||
 		 ((!x[2] && !x[1] && x[0]) && (!y[2] && !y[1] && !y[0])) ||  
		 ((!x[2] && x[1] && !x[0]) && (!y[2] && !y[1] && y[0])) ||
		 ((!x[2] && x[1] && x[0]) && (!y[2] && y[1] && !y[0])) ||
		 ((!x[2] && !x[1] && !x[0]) && (!y[2] && y[1] && y[0]))
		); 
 
	expr I=(!x[2] && !x[1] && !x[0]); // initial state formula - 000

*/ 
 
// example from the thesis
//s0->s1;s1->s2;s2->s3;s3->s0
//s4->s0;s4->s5;s5->s6;s6->s3


std::cout << "\ninput-commandline ";

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
	int givenInitialState, givenFinalState;

	int numberOfvertices, *pp_nov;

	pp_nov = &numberOfvertices;


	std::cout << "\nMain starts. This is the code for reachability analysis";

	p1_theInputFile_vectorOfVectors = &theInputFile_vectorOfVectors;
	p3_theMaxBit = &theMaxBitrequired;

	   std::stringstream ss, ss2;
	   ss << argv[2];
	   ss >> givenInitialState;

	   //ss2 << argv[3];
	   //ss2 >> givenFinalState;

	//givenInitialState = stoi(argv[2]);
	givenFinalState = 0;


	f01_controlFunctionForReachability(argv[1], p1_theInputFile_vectorOfVectors, p3_theMaxBit, theVertexToItsBooleanExpression, xES, yED, &c, theT, theIorF_I, theIorF_F, pp_nov, givenInitialState, givenFinalState);


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

	std::cout << "\nPre-processing done. Z3 library starts now";

	std::cout << "\nCheck theT: " << theT;
	std::cout << "\nCheck theIorF_I: " << theIorF_I;
	std::cout << "\nCheck theIorF_F: " << theIorF_F;


	std::cout << "\n\n";

std::cout << "\n end";

//////////////////////////////////////

    	int N=*p3_theMaxBit;
std::cout << "\nhello N: " << N;
	expr path(c); 
	expr loop(c);
	 
	solver	s(c);

	std::cout << "\n\nEnter the no. of variables:";
	//std::cin >> N;
	std::cout << "\n\n";            

	for(unsigned i=0; i<N; ++i){
		std::stringstream xName;
		xName << "x" << i;
		x.push_back(c.bool_const(xName.str().c_str()));
	}

	for(unsigned i=0; i<N; ++i){
		std::stringstream yName;
		yName << "y" << i;
		y.push_back(c.bool_const(yName.str().c_str()));
	}
	
	std::cout << x << "\n\n";
	std::cout << y << "\n\n";
	//getchar();

        //expr compeq=c.bool_val(true);
        expr compeq=(x[0]==y[0]);
        for(int i=1; i<N; i++)
        {
        compeq=(compeq&&(x[i]==y[i]));
        }
       //expr compeq=( (x[4]==y[4])&&(x[3]==y[3])&&(x[2]==y[2]) && (x[1]==y[1]) && (x[0]==y[0]));  
 
 	//path=(!x[0]||x[0]); 
	//std::cout << "initial path is :" << path << "\n\n";
        loop=(!x[0] && x[0]); 
///////////////////////////////////////

 /*	expr T=(((!x[2] && !x[1] && !x[0]) && (!y[2] && !y[1] && y[0])) ||  
		 ((!x[2] && !x[1] && x[0]) && (!y[2] && y[1] && !y[0])) ||
		 ((!x[2] && x[1] && !x[0]) && (!y[2] && y[1] && y[0])) ||
		 ((!x[2] && x[1] && x[0]) && (!y[2] && !y[1] && !y[0]))||
	 	((x[2] && !x[1] && !x[0]) && (!y[2] && !y[1] && !y[0])) ||  
	 	((x[2] && !x[1] && !x[0]) && (y[2] && !y[1] && y[0])) ||
	 	((x[2] && !x[1] && x[0]) && (y[2] && y[1] && !y[0])) ||
	 	((x[2] && x[1] && !x[0]) && (!y[2] && y[1] && y[0]))
	 	); 
 
 */

expr T = theT; 
 
	//expr I=(!x[2] && !x[1] && !x[0]); // initial state formula - 000
//	expr I=(x[2] && !x[1] && !x[0]); // initial state formula - 100
	
	expr I = theIorF_I;

 std::cout << "\nTest T: " << T;
 
  std::cout << "\nTest I: " << I;
 
/* 
	expr 	I=(!x[2] && !x[1] && !x[0]); // initial state formula - 100
	expr 	T=( ((!x[2] && !x[1] && !x[0]) && (!y[2] && !y[1] && y[0])) || ((!x[2] && !x[1] && !x[0]) && (!y[2] && y[1] && y[0]))  || ((!x[2] && !x[1] && x[0]) && (!y[2] && y[1] && !y[0]))  || ((!x[2] && x[1] && x[0]) && (!y[2] && y[1] && !y[0])) || ((x[2] && x[1] && x[0]) && (!y[2] && !y[1] && y[0])) ) ; // transition formula
*/

	std::cout << "\nI is :" << I << "\n\n";
	std::cout << "\nT is :" << T << "\n\n";
        //return 0;
//	getchar();

 	expr_vector	z(c);
	for(unsigned i=0; i<N; ++i){
		std::stringstream zName;
		zName << "x_0_" << i;
		z.push_back(c.bool_const(zName.str().c_str()));
	}
    	
        path=(!x[0] || x[0]); 
	//path = I.substitute(x,z);//Initialize the path to the (formula representing) initial states. 
	std::cout << "initiated path is :" << path << "\n\n";
 
	//return 0;  
 
 
 
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
                //getchar();
//update the path expression by adding subT
                path=path && subT;
		std::cout << "At k="<<k<<"path is: " << path << "\n\n"; 
                //return 0;
 
 
 
 
// Todo: debug from below
// implement equality checking 
//
        loop=(!x[0] && x[0]);  //reset loop condition
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
                //
		//getchar(); 
 
 
  
 

	s.add(path && (!loop));
        if(s.check()==unsat){
		int rd=k-1;
		std::cout<<"\n\n rd="<< rd <<"\n\n"; 
                //
		//getchar();
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
		//s.reset();
        }
 
} //end of outer for loop with index k 
			std::cout<<"\n\n Reached  max limit\n\n";
        	        return 0; 
} //end of main 


void f01_controlFunctionForReachability(std::string myFileName, std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors, int *p3_theMaxBit, std::map<int, expr> &theVertexToItsBooleanExpression, expr_vector &xES, expr_vector &yED, context *c, expr &theT, expr &theIorF_I, expr &theIorF_F, int *pp_nov, int givenInitialState, int givenFinalState) {
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
	for(std::vector<int>::iterator i2_ = theSortedVectorOfVertices.begin(); i2_ != theSortedVectorOfVertices.end(); i2_++) {
		//std::cout << *i2_ << " ";
		if(*i2_ == givenFinalState)
			existFinalState = 1;
	}

	if(existInitialState == 1 && existFinalState == 1) {
		*pp_nov = theSortedVectorOfVertices.size();
		f04_findNumberOfMaxBitrequired(theSortedVectorOfVertices, p3_theMaxBit);
		f05_integerToBinaryForAllVertices(p2_theSortedVectorOfVertices, p4_integerToBinaryForAllVertices, p3_theMaxBit);
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

		f07_createEdgeToBooleanExpression2(p1_theInputFile_vectorOfVectors, integerToBinaryForAllVertices, theVertexToItsBooleanExpression, xES, yED, p3_theMaxBit, c, theT);
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
		f08_createVertexToBooleanExpression(p1_theInputFile_vectorOfVectors, integerToBinaryForAllVertices, xES, p3_theMaxBit, c, theIorF_F, givenFinalState);
	}
	else {
		std::cout << "\nInput/output combination does not exist in the graph txt file";
		std::cout << "\ngivenInitialState: " << givenInitialState;
		std::cout << "\ngivenFinalState: " << givenFinalState;
		std::cout << "\n\n";
		exit(0);
	}


	return;
}
//read input file
void f02_readTheInputFileAndGiveMeVectorOfVectors(std::string myFileName, std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors) {
	std::ifstream myFileStream(myFileName);
	int j1, j2;
    std::vector<int> myOneEdge;

	while(myFileStream >> j1 >> j2) {
	    myOneEdge.push_back(j1);
	    myOneEdge.push_back(j2);
	    (*p1_theInputFile_vectorOfVectors).push_back(myOneEdge);
	    myOneEdge.clear();
	}


	return;
}
//find Vertices

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
//findNumberOfMaxBitrequired
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


void f05_integerToBinaryForAllVertices(std::vector<int> *p2_theSortedVectorOfVertices, std::map<int, std::vector<int> > *p4_integerToBinaryForAllVertices, int *p3_theMaxBit) {
	//std::cout << "\nIn f05";

	std::vector<int> theBinary;
	std::vector<int> *p1_theBinary;

	p1_theBinary = &theBinary;

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
	}


	return;
}

//decimalToBinary
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

//createEdgeToBooleanExpression
void f07_createEdgeToBooleanExpression2(std::vector<std::vector<int> > *p1_theInputFile_vectorOfVectors, std::map<int, std::vector<int> > integerToBinaryForAllVertices, std::map<int, expr> &theVertexToItsBooleanExpression, expr_vector &xES, expr_vector &yED, int *p3_theMaxBit, context *c, expr &theT) {
	//std::cout << "\nIn f07-2";
	int k1, k2;

	int edgeNumber = 0;
	int firstExp1, firstExp2;



    expr theX(*c), theY(*c);
    expr tx1(*c);
    expr tx2(*c);

    expr theTtemp(*c);


	std::map<int, expr> TEMP;

	//theT = (*c).bool_val(false);
	edgeNumber = 0;

	for(int j1 = 0; j1 < *p3_theMaxBit; j1++) {
		std::stringstream x, y;

		x << "x" << j1;
		y << "y" << j1;
		xES.push_back((*c).bool_const(x.str().c_str()));
		yED.push_back((*c).bool_const(y.str().c_str()));
	}




	//std::cout << "\nCheck parameters. p1_theInputFile_vectorOfVectors: ";
	for(std::vector<std::vector<int> >::iterator i3 = (*p1_theInputFile_vectorOfVectors).begin();
			i3 != (*p1_theInputFile_vectorOfVectors).end(); i3++, edgeNumber++) {
		std::vector<int> tempo = *i3;

		if(edgeNumber == 0) {
			//std::cout << "\n\nedgeNumber=0: " << edgeNumber;
			//std::cout << "\n===one Edge: " << tempo[0] << " to " << tempo[1];
			std::map<int, std::vector<int> >::iterator p1;

			p1 = integerToBinaryForAllVertices.find(tempo[0]);
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

				//std::cout << "\ntx1: " << tx1;

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
				//std::cout << "\ntx2: " << tx2;
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

				//std::cout << "\n\ntx1: " << tx1;

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
				//std::cout << "\ntx2: " << tx2;

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

	//std::cout << "\nOUTSIDE TheT: " << theT;

/*
	std::cout << "\nCheck parameters. integerToBinaryForAllVertices: ";
	for(std::map<int, std::vector<int> >::iterator i1 = integerToBinaryForAllVertices.begin(); i1 != integerToBinaryForAllVertices.end(); i1++) {
		int g1 = i1->first;
		std::vector<int> g2 = i1->second;

		std::cout << "\n" << g1 << " = ";
		for(std::vector<int>::iterator i2 = g2.begin(); i2 != g2.end(); i2++) {
			std::cout << *i2 << " ";
		}
	}
*/
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

		x << "x" << j1;
		y << "y" << j1;
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


//createVertexToBooleanExpression
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


