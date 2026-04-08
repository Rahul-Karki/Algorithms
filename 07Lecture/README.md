## Practical-1: Multi-Stage Graph Minimum Cost Path
## Aim

To find the minimum cost path in a multi-stage graph from source to destination.

## Theory

A multi-stage graph is a directed graph where vertices are grouped into stages and edges go from earlier stages to later stages.

A common approach is dynamic programming from destination backwards.

This implementation first groups vertices stage-wise using traversal and then tries to choose minimum-cost transitions while moving backward.

## Time Complexity

O(V^2) for matrix traversal and stage processing (approximate)

## Space Complexity

O(V^2) for adjacency matrix and O(V) to O(V^2) for stage storage

## What the Code Does

This program stores graph edge weights in an adjacency matrix where -1 denotes no edge.

The makeStages(a, V, s, stages) function performs level-order traversal from source and groups reachable vertices into stages.

The findMinCost(stages, a, sink, minCost, i) function recursively processes stages backward and accumulates path cost.

The main function reads source and destination nodes, builds stages, computes cost, and prints the final minimum cost.
