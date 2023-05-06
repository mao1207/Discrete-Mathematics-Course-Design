# Tongji University Discrete Mathematics Course Projects 2022

This document summarizes six projects designed for the Discrete Mathematics course at Tongji University in 2022. Each project focuses on a specific topic within the field of discrete mathematics and has practical applications.

## Project 1: Propositional Logic and Truth Tables
Simulate truth tables, master parsing paradigms, and master merging paradigms using computers

- Propositional Calculations：
Input the truth values of two propositional variables P and Q, and calculate their conjunction, disjunction, conditional, and biconditional truth values.

- Truth Tables：
Generate truth tables for any given propositional formula.

- Main Normal Forms：
Determine the main normal forms based on the truth tables obtained in part B.

## Project 2: Crime Solving with Propositional Logic

Use propositional logic to deduce the culprit of a crime based on the following premises:

- Clerk A or B stole the watch.
- If A committed the crime, it did not happen during business hours.
- If B's testimony is correct, the showcase was unlocked.
- If B's testimony is false, the crime occurred during business hours.
- The showcase was locked.

## Project 3: Closure Operations on Relations

The aim of this project is to compute the reflexive, symmetric, and transitive closures of a given relation on a finite set using relation matrices. The program should first validate the correctness of the relation matrix and then perform the closure operations based on the input operator.

## Project 4: Road Construction Cost Optimization

Develop a program that generates the optimal road connection strategy to minimize the total construction cost for a city with n districts. The user inputs the distances between different districts, and the system outputs the strategy corresponding to the lowest engineering cost. Implement Kruskal's and Prim's algorithms to construct the minimum spanning tree.

## Project 5: Optimal Binary Tree in Communication Encoding

In this problem, the cost of communication is proportional to the length of the prefix codes of communication symbols. When a particular communication symbol is used repeatedly, the cost incurred by its prefix code is calculated multiple times. To minimize the cost, we want the prefix codes of frequently used communication symbols to be as short as possible. One possible implementation is to use a priority queue to store all the values of the sequence. In each step, dequeue the two smallest elements from the queue, calculate their sum, and enqueue the result. Repeat this process until only one element remains in the queue, which represents the final solution.

Another approach is to represent prefix codes with a binary tree, where the cost of communication corresponds to the Weighted Path Length (WPL) of the binary tree. To achieve this, we can construct a Huffman tree. The sum of the weights of all non-leaf nodes in the Huffman tree is the minimum cost required for the problem, and the position of the leaf nodes represents the Huffman encoding.

## Project 6: Transitive Closure with Warshall's Algorithm

The goal of this project is to compute the transitive closure of a given relation on a finite set using Warshall's algorithm, which helps students familiarize themselves with closure operations on relations. The program should first verify the correctness of the input relation matrix. If any non-Boolean matrix elements are encountered, an error should be reported. Otherwise, the program will output the result of the transitive closure calculated using Warshall's algorithm.


## Summary
These six projects cover a wide range of topics in discrete mathematics and provide students with an opportunity to apply their knowledge to real-world problems.
