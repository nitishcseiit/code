# code


# What does it contain?

Given a Kripke structure, this repostory contains the code for Reachability diameter , Diameter, and Recurrence diameter. We have used z3 SAT-solver using the C++ interface to implement it.

## input format for the Kripke structure

We consider the Kripkestructure as a directed graph G. The input for G is as below:

```sh
u  v, where u is the source node and v is the destination node, and there exists an edge from u to v. An example of such graph is

0 1
1 2
2 3

This indicate 0 -> 1 -> 2 -> 3
```


## Reachbility diameter
### How to you run it?

#### To compile 

g++ filename -lz3

#### To execute
```SH 
./a.out <graph name> <initial-state>
```

## Diameter
### To execute 
```SH 
bash Diameter.cpp <graph name>
```


## Recurrence diameter
###  How to you run it?

#### To compile 

g++ filename -lz3

#### To execute
```SH 
./a.out <graph name> <initial-state>
```



# An example

