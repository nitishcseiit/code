#include<bits/stdc++.h>
#include<math.h>
#include <z3++.h>

using namespace z3;


int main(){
	context		ctx;
	expr_vector	x(ctx), y(ctx);

    	int N;

	expr path(ctx); 
	expr loop(ctx);
	 
	solver	s(ctx);

	std::cout << "\n\nEnter the no. of variables:->";
	std::cin >> N;
	std::cout << "\n\n";            

	for(unsigned i=0; i<N; ++i){
		std::stringstream xName;
		xName << "x" << i;
		x.push_back(ctx.bool_const(xName.str().c_str()));
	}

	for(unsigned i=0; i<N; ++i){
		std::stringstream yName;
		yName << "y" << i;
		y.push_back(ctx.bool_const(yName.str().c_str()));
	}
	
	std::cout << x << "\n\n";
	std::cout << y << "\n\n";
	getchar();

 
 	//path=(!x[0]||x[0]); 
	//std::cout << "initial path is :" << path << "\n\n";
        loop=(!x[0] && x[0]); 
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
 
 
/* 
	expr 	I=(!x[2] && !x[1] && !x[0]); // initial state formula - 100
	expr 	T=( ((!x[2] && !x[1] && !x[0]) && (!y[2] && !y[1] && y[0])) || ((!x[2] && !x[1] && !x[0]) && (!y[2] && y[1] && y[0]))  || ((!x[2] && !x[1] && x[0]) && (!y[2] && y[1] && !y[0]))  || ((!x[2] && x[1] && x[0]) && (!y[2] && y[1] && !y[0])) || ((x[2] && x[1] && x[0]) && (!y[2] && !y[1] && y[0])) ) ; // transition formula
*/

	std::cout << "I is :" << I << "\n\n";
	std::cout << "T is :" << T << "\n\n";
        //return 0;
	getchar();

 	expr_vector	z(ctx);
	for(unsigned i=0; i<N; ++i){
		std::stringstream zName;
		zName << "x_0_" << i;
		z.push_back(ctx.bool_const(zName.str().c_str()));
	}
    	
	path = I.substitute(x,z);//Initialize the path to the (formula representing) initial states. 
	std::cout << "initiated path is :" << path << "\n\n";
 
	//return 0;  
 
 
 
int k=1; 
int max_nodes=pow(2,N);
for (k=1;k <= max_nodes;k++){
 
//creating path_d
// loop for creating variables [x_k-1_0, x_k-1_1, x_k-1_2]  = s_{k-1}             
        expr_vector	z0(ctx);
	for(unsigned i=0; i<N; ++i){
		std::stringstream z0Name;
		z0Name << "x_" << k-1 << "_" << i;
		z0.push_back(ctx.bool_const(z0Name.str().c_str()));
	}
// loop for creating variables [x_k_0, x_k_1, x_k_2] = s_k
        expr_vector	z1(ctx);
	for(unsigned i=0; i<N; ++i){
		std::stringstream z1Name;
		z1Name << "x_" << k << "_" << i;
		z1.push_back(ctx.bool_const(z1Name.str().c_str()));
	}
      
//subT is T(x,y) with x=(x0,x1,x2) replaced current state z0 and y=(y0,y1,y2) replaced by next state z1.
                expr subT(ctx);
                subT=T.substitute(y,z1);
                subT=subT.substitute(x,z0);
		std::cout << "At k="<<k<<" subT : " << subT << "\n\n"; 
                getchar();
//update the path expression by adding subT
                path=path && subT;
		std::cout << "At k="<<k<<"path is: " << path << "\n\n"; 
                //return 0;
// Todo: debug from below
//
//
//
        loop=(!x[0] && x[0]);  //reset loop condition
	for(unsigned j=0;j <= (k-1);j++){ //create loop_d  for d >= 1
        	expr_vector zd(ctx); // loop for creating variables [x_d_0, x_d_1,x_d_2]= s_d
		for(unsigned i=0; i<N; ++i){
			std::stringstream zdName;
			zdName << "x_" << k << "_" << i;
			zd.push_back(ctx.bool_const(zdName.str().c_str()));
		}
 
        	expr subL(ctx);
 	        subL=T.substitute(x,zd);
	
       		expr_vector zj(ctx); // loop for creating variables [x_j_0, x_j_1,x_j_2]= s_j
		for(unsigned i=0; i<N; ++i){
			std::stringstream zjName;
			zjName << "x_" << j << "_" << i;
			zj.push_back(ctx.bool_const(zjName.str().c_str()));
		}
       		subL=subL.substitute(y,zj);
		std::cout <<"at k="<<k<<"subL is: "<<subL<<"\n\n";
		getchar(); 
		loop = loop || subL; 
	}// end of for index j  
		std::cout <<"at k="<<k<<"loop is: "<<loop<<"\n\n";
                getchar(); 

	s.add(path && (!loop));
        if(s.check()==unsat){
		int rd=k-1;
		std::cout<<"hey there\n\n"; 
		std::cout<<"\n\n rd="<< rd <<"\n\n"; 
		std::cout<<"hey hi\n\n"; 
                getchar();
		exit(0);
        } // found rd exit
	else{
		s.reset();
		k++;
        }
 
} //end of outer for loop with index k 
			std::cout<<"\n\n Reached  max limit\n\n";
        	        return 0; 
} //end of main 


