# What does it contain?

This repostory contains the code for computing Reachability diameter, Diameter, and Recurrence diameter of a given Kripke Structure. 
The files for computing each parameter are given in different directories. 
The code uses Z3 SAT/SMT solver with the C++ interface. 

## Input format for the Kripke structure

We consider the Kripke structure as a directed graph G. 
The input for G is as below:

```sh
u  v, where u is the source node and v is the destination node, and there exists an edge from u to v.
Nodes u and v are separated by at least one space (not tab).

An example of such graph is

0 1
1 2
2 3

This indicates edges  0 -> 1 -> 2 -> 3
```


## Reachability diameter
### How to use this?

#### To compile 

g++ reachability_diameter.cpp -lz3

#### To execute
```SH 
./a.out <graph name> <initial-state>
```
For example:
````SH
./a.out graph1.txt 0
````


## Diameter
### To use this execute 
```SH 
bash diameter.sh <graph name>
```


## Recurrence diameter
###  How to use this?

#### To compile 
````SH
g++ recurrence-diameter.cpp -lz3
````

#### To execute
```SH 
./a.out <graph name> <initial-state>
```

