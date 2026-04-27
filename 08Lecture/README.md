## Practical-1: Multi-Stage Graph (Forward Approach)
## Aim

To find the minimum cost path from source to destination in a multi-stage graph using forward dynamic programming.

## Theory

In a multi-stage graph, vertices are processed in stage order.

In the forward approach:

Start from the source node with distance 0.

Relax valid forward edges and update minimum distance for reachable nodes.

Store parent information to reconstruct the final minimum-cost path.

This works efficiently when edges move from lower index stages to higher index stages.

## Time Complexity

O(n^2)

## Space Complexity

O(n^2) for cost matrix and O(n) for distance/parent arrays

## What the Code Does

This program reads number of nodes and a cost matrix from input.

The dist array stores the minimum cost from source node 1 to every node.

The parent array stores predecessor of each node for path reconstruction.

Nested loops relax edges only in forward direction (i to j where j > i).

Finally, it prints minimum cost to the last node and prints the full path by tracing parent links.

![Forward Approach Graph](Images/forward.png)

## Practical-2: Multi-Stage Graph (Backward Approach)
## Aim

To find the minimum cost path in a multi-stage graph using backward dynamic programming.

## Theory

In the backward approach, computation starts from destination and moves toward source.

For each node i, compute:

Minimum of cost(i, j) + minCost(j) over all valid outgoing edges from i.

Store the best next decision to reconstruct the path.

This approach is suitable for directed acyclic multi-stage graphs.

## Time Complexity

O(n^2)

## Space Complexity

O(n)

## What the Code Does

This program uses a fixed 8-node directed graph represented as a cost matrix.

The minCost array stores minimum cost from each node to the destination.

The decision array stores the next node on the optimal path.

The algorithm computes minCost values from node n-2 down to node 0.

At the end, it prints the minimum cost and the optimal path from source to destination.

![Backward Approach Graph](Images/backward.png)

## Practical-3: Matrix Chain Multiplication (Dynamic Programming)
## Aim

To find the minimum number of scalar multiplications needed for multiplying a chain of matrices.

## Theory

Matrix Chain Multiplication does not change matrix order, but changes parenthesization to reduce computation.

Dynamic programming is used to avoid recomputing overlapping subproblems.

Let m[i][j] represent minimum cost of multiplying matrices from i to j.

For every possible split k between i and j:

cost = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]

Choose the minimum among all k.

## Time Complexity

O(n^3)

## Space Complexity

O(n^2)

## What the Code Does

This program computes DP tables for matrix chain multiplication.

The m table stores minimum multiplication cost for every sub-chain.

The s table stores split index k that gave the optimal cost.

The program fills these tables diagonally by increasing chain length.

Finally, it prints both M matrix (cost table) and S matrix (optimal split table).

![Matrix Chain Multiplication Graph](Images/mcm.png)
