# What does it contain?

This repostory contains the code for computing Reachability diameter, Diameter, and Recurrence diameter of a given Kripke Structure. 
The code uses Z3 SAT/SMT solver with the C++ interface. 

## Input format for the Kripke structure

We consider the Kripke structure as a directed graph G. 
The input for G is as below:

```sh
u  v, where u is the source node and v is the destination node, and there exists an edge from u to v. An example of such graph is

0 1
1 2
2 3

This indicate 0 -> 1 -> 2 -> 3
```


## Reachbility diameter
### How to run it?

#### To compile 

g++ Reachability_diameter.cpp -lz3

#### To execute
```SH 
./a.out <graph name> <initial-state>
```
For example:
````SH
./a.out graph1.txt 0
````


## Diameter
### To execute 
```SH 
bash diameter.sh <graph name>
```


## Recurrence diameter
###  How to run it?

#### To compile 


g++ recurrence-diameter.cpp -lz3
#### To execute
```SH 
./a.out <graph name> <initial-state>
```

