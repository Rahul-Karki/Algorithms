## Practical-1: Floyd-Warshall Algorithm
## Aim

To find shortest paths between all pairs of vertices in a weighted graph.

## Theory

Floyd-Warshall is a dynamic programming algorithm for the all-pairs shortest path problem.

It progressively improves shortest path estimates by allowing each vertex as an intermediate node.

For each intermediate node `k`, every pair `(i, j)` is updated as:

`dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`

This works for directed and undirected weighted graphs and handles unreachable edges using sentinel values.

## Time Complexity

O(V^3)

## Space Complexity

O(V^2)

## What the Code Does

This program stores a graph as an adjacency matrix where `-1` means no direct edge.

The `shortestPath(graph)` function runs three nested loops over intermediate, source, and destination vertices.

It updates path cost whenever a shorter valid route is found through the current intermediate vertex.

Finally, the updated matrix of shortest distances is printed.

![Floyd-Warshall Graph](Images/floydWarshall.png)

## Practical-2: Longest Common Subsequence (LCS)
## Aim

To find the length of the longest common subsequence between two strings.

## Theory

The Longest Common Subsequence problem finds the longest sequence of characters that appears in the same relative order in both strings.

Dynamic programming is used to build a table where each cell stores the best LCS length for string prefixes.

If current characters match, add 1 to the diagonal value; otherwise take the maximum of top or left cell.

## Time Complexity

O(n * m)

## Space Complexity

O(n * m)

## What the Code Does

This program takes two strings and builds a DP table for all prefix combinations.

It fills the table using character match and mismatch transitions.

Finally, it prints the LCS length from the last cell of the table.
