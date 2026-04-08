## Practical-1: Activity Selection (Greedy)
## Aim

To select the maximum number of non-overlapping activities using a greedy strategy.

## Theory

In the Activity Selection problem, each activity has a start and finish time.

The optimal greedy strategy is:

Sort activities by increasing finish time.

Always select the first compatible activity whose start time is greater than or equal to the finish time of last selected activity.

This gives the maximum number of activities that can be performed.

## Time Complexity

O(n log n) (due to sorting)

## Space Complexity

O(1) (excluding input storage)

## What the Code Does

This program stores activities as (start, finish) pairs and sorts them by finish time.

The printMaxActivities(arr, n) function selects activities one by one by checking compatibility with the previously selected activity.

The selected activity list is printed as output.

## Practical-2: Dijkstra's Shortest Path Algorithm
## Aim

To find the shortest distance from a source vertex to all other vertices in a weighted graph.

## Theory

Dijkstra's algorithm solves single-source shortest path for graphs with non-negative edge weights.

It repeatedly picks the vertex with minimum tentative distance and relaxes its adjacent edges.

Using a min-priority queue improves efficiency when selecting the next nearest vertex.

## Time Complexity

O((V + E) log V) with priority queue (typical)

## Space Complexity

O(V + E)

## What the Code Does

This program takes graph costs through an adjacency matrix and a source vertex from user input.

The dijkstra(source, visited, dist, cost, adj) function uses a min heap to process vertices in increasing path cost.

Whenever a shorter path is found, dist is updated and neighboring vertices are pushed again.

At the end, the program prints the shortest distance from source to every vertex.

## Practical-3: Kruskal's Minimum Spanning Tree
## Aim

To construct a Minimum Spanning Tree (MST) using Kruskal's algorithm.

## Theory

Kruskal's algorithm is a greedy method for MST.

Sort all edges in non-decreasing order of weight.

Pick the next smallest edge that does not create a cycle.

Use Disjoint Set Union (Union-Find) to efficiently detect and merge components.

Continue until n - 1 edges are selected.

## Time Complexity

O(E log E)

## Space Complexity

O(V)

## What the Code Does

This program defines edges with endpoints and weights, then sorts them by weight.

The find(x) and unionSet(x, y) functions implement Union-Find with path compression and union by size.

The kruskal(n, edges) function chooses valid edges, prints them, and returns MST cost.

If a full spanning tree is not possible, it prints No Spanning Tree.

## Practical-4: Prim's Minimum Spanning Tree
## Aim

To construct a Minimum Spanning Tree (MST) using Prim's algorithm.

## Theory

Prim's algorithm grows an MST from a starting vertex.

At each step, it selects the minimum weight edge that connects a visited vertex to an unvisited vertex.

This is repeated until all vertices are included in the MST.

## Time Complexity

O(V^2) for adjacency matrix implementation

## Space Complexity

O(V)

## What the Code Does

This program uses a fixed weighted adjacency matrix graph.

The minKey(key, mstSet) function selects the next vertex with minimum key value not yet in MST.

The primMST(graph) function updates parent and key arrays and prints all MST edges with weights.
