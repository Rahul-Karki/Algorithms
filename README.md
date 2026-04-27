# Algorithms

This repository contains lecture-wise algorithm practicals from Semester 4.

## Lecture 01

### Practical 1: Power of a Number
Aim: To implement and compare recursive methods to calculate a number raised to power n.

Theory: Divide and conquer recursion computes the answer using half exponent and combines results.

Time Complexity: O(log n)

Space Complexity: O(log n)

Algorithm:
1. If n is 0, return 1.
2. Compute half = power(x, n/2).
3. If n is even, return half * half.
4. If n is odd, return half * half * x.

### Practical 2: Permutations of a String
Aim: To generate all possible permutations of a given string.

Theory: Fix one index at a time, swap with all available characters, and backtrack.

Time Complexity: O(n * n!)

Space Complexity: O(n)

Algorithm:
1. Start from index 0.
2. Swap current index with each index from current to end.
3. Recurse for next index.
4. Swap back after recursion.
5. Print when index reaches end.

### Practical 3: Tower of Hanoi
Aim: To solve Tower of Hanoi recursively and print valid moves.

Theory: Move n-1 disks to helper, move largest disk, then move n-1 disks to destination.

Time Complexity: O(2^n)

Space Complexity: O(n)

Algorithm:
1. If n is 1, move source to destination.
2. Move n-1 disks from source to helper.
3. Move nth disk from source to destination.
4. Move n-1 disks from helper to destination.

![Tower of Hanio Graph](01Lecture/Images/TOH.png)

### Practical 4: Generate Binary Strings (Truth Table)
Aim: To generate all binary strings of length n.

Theory: At each step append 0 and 1 recursively until string length becomes n.

Time Complexity: O(2^n)

Space Complexity: O(n)

Algorithm:
1. If current string length is n, print it.
2. Append '0' and recurse.
3. Backtrack and append '1' and recurse.

### Practical 5: Ball Jump Problem
Aim: To count jumps until bounce height becomes less than 1.

Theory: Recursively reduce height by fixed percentage and count recursive steps.

Time Complexity: O(log n)

Space Complexity: O(log n)

Algorithm:
1. If current height is below 1, return count.
2. Reduce height by bounce factor.
3. Increment jump count and recurse.

### Practical 6: Recursive Selection Sort and Time Analysis
Aim: To sort an array using recursive selection sort.

Theory: In each step, place minimum element of unsorted part at current position.

Time Complexity: O(n^2)

Space Complexity: O(n)

Algorithm:
1. Find index of minimum element from i to n-1.
2. Swap it with element at i.
3. Recurse for i + 1.

![Selection Sort Graph](01Lecture/Images/selectionSort.png)

### Practical 7: Recursive Bubble Sort and Time Analysis
Aim: To sort an array using recursive bubble sort.

Theory: One pass moves largest element to end, then solve for reduced array.

Time Complexity: Best O(n), Average O(n^2), Worst O(n^2)

Space Complexity: O(n)

Algorithm:
1. Perform one full adjacent swap pass for current n.
2. Largest element gets fixed at end.
3. Recurse for n - 1.

![Bubble Sort Graph](01Lecture/Images/bbSort.png)

### Practical 8: Recursive Linear Search and Time Analysis
Aim: To search a target recursively in an array.

Theory: Compare one element at a time and recurse to next index.

Time Complexity: Best O(1), Average O(n), Worst O(n)

Space Complexity: O(n)

Algorithm:
1. If index reaches n, return false.
2. If current element equals target, return true.
3. Recurse with next index.

![Linear Search Graph](01Lecture/Images/linearSearch.png)

### Practical 9: Polynomial Evaluation Using Horner's Rule
Aim: To evaluate polynomial efficiently using Horner's rule.

Theory: Rewrite polynomial in nested form and evaluate recursively.

Time Complexity: O(n)

Space Complexity: O(n)

Algorithm:
1. If only one coefficient remains, return it.
2. Return coeff[0] * x + horner(remaining coeffs).

### Practical 10: Find Duplicate Number
Aim: To find duplicate number in array.

Theory: Implemented using brute-force comparison and index mismatch logic in separate files.

Time Complexity: O(n^2) for nested comparison approach, O(n) for index mismatch scan.

Space Complexity: O(1)

Algorithm:
1. Compare each element with all later elements and return first duplicate.
2. In index mismatch scan, iterate and detect mismatch condition to identify candidate duplicate.

## Lecture 02

### Practical 1: Binary Search (Recursive) and Time Analysis
Aim: To search target in sorted array using recursive binary search.

Theory: Repeatedly split search interval into two halves.

Time Complexity: Best O(1), Average O(log n), Worst O(log n)

Space Complexity: O(log n)

Algorithm:
1. Compute middle index.
2. If middle element equals target, return found.
3. If target is smaller, recurse on left half.
4. Otherwise recurse on right half.

![Binary Search Graph](02Lecture/Images/binarySearch.png)

### Practical 2: Insertion Sort
Aim: To sort array using recursive insertion sort.

Theory: Sort first n-1 elements, then insert nth element in its position.

Time Complexity: Best O(n), Average O(n^2), Worst O(n^2)

Space Complexity: O(n)

Algorithm:
1. Recursively sort first n-1 elements.
2. Store last element as key.
3. Shift larger elements right.
4. Insert key at correct position.

![Insertion Sort Graph](02Lecture/Images/insertionSort.png)

## Lecture 03

### Practical 1: Merge Sort
Aim: To sort array using merge sort and analyze runtime.

Theory: Divide into halves, sort recursively, merge sorted halves.

Time Complexity: O(n log n)

Space Complexity: O(n)

Algorithm:
1. Split array into two halves.
2. Recursively sort left and right halves.
3. Merge both sorted halves.

![Merge Sort Graph](03Lecture/Images/mergeSort.png)

### Practical 2: Quick Sort
Aim: To sort array using quick sort and analyze runtime.

Theory: Partition around pivot and sort partitions recursively.

Time Complexity: Best O(n log n), Average O(n log n), Worst O(n^2)

Space Complexity: O(log n)

Algorithm:
1. Choose pivot and partition array.
2. Place pivot at correct final position.
3. Recursively sort left partition.
4. Recursively sort right partition.

![Quick Sort Graph](03Lecture/Images/quickSort.png)

## Lecture 04

### Practical 1: Quick Select Using Partition
Aim: To find k-th smallest element using partition strategy.

Theory: Partition and recurse only in side containing k-th element.

Time Complexity: Best O(n), Average O(n), Worst O(n^2)

Space Complexity: O(log n)

Algorithm:
1. Partition array around pivot.
2. If pivot index equals k, return element.
3. If pivot index is smaller than k, recurse right.
4. Otherwise recurse left.

### Practical 2: Strassen Matrix Multiplication
Aim: To multiply square matrices using Strassen algorithm.

Theory: Reduce multiplications from 8 to 7 in recursive block multiplication.

Time Complexity: O(n^log2(7))

Space Complexity: O(n^2)

Algorithm:
1. Split A and B into 4 sub-matrices each.
2. Compute M1 to M7 recursively.
3. Build C11, C12, C21, C22 using M1 to M7.
4. Combine blocks into final matrix C.

## Lecture 05

### Practical 1: Convex Hull (Graham Scan)
Aim: To find convex hull of 2D points.

Theory: Sort points by angle and maintain counter-clockwise boundary.

Time Complexity: O(n log n)

Space Complexity: O(n)

Algorithm:
1. Find point with lowest y (and x tie-break).
2. Sort remaining points by polar angle.
3. Traverse points and remove non-left-turn points.
4. Remaining stack forms convex hull.

![Convex Hull Graph](05Lecture/Images/convexHull.png)

### Practical 2: Fractional Knapsack (Greedy Comparison)
Aim: To maximize profit for limited knapsack capacity.

Theory: Greedy strategy with best ratio gives optimal fractional solution.

Time Complexity: O(n log n)

Space Complexity: O(n)

Algorithm:
1. Compute value/weight ratio for each item.
2. Sort items by descending ratio.
3. Add full items while possible.
4. Add fraction of next item if capacity remains.

![Fractional Knapsack Graph](05Lecture/Images/knapsack.png)

### Practical 3: Maximum and Minimum Using Divide and Conquer
Aim: To find both minimum and maximum using recursion.

Theory: Split array and combine min-max results from subproblems.

Time Complexity: O(n)

Space Complexity: O(log n)

Algorithm:
1. Handle base case of one or two elements.
2. Divide array into two halves.
3. Recursively get min-max of both halves.
4. Combine to global min and max.

![Max-Min Graph](05Lecture/Images/maxmin.png)

## Lecture 06

### Practical 1: Activity Selection (Greedy)
Aim: To select maximum number of non-overlapping activities.

Theory: Sorting by finish time yields optimal greedy choice.

Time Complexity: O(n log n)

Space Complexity: O(1)

Algorithm:
1. Sort activities by finish time.
2. Select first activity.
3. Select next activity with start >= last selected finish.
4. Continue until all activities are checked.

![Activity Selection Graph](06Lecture/Images/activitySelection.png)

### Practical 2: Dijkstra's Shortest Path Algorithm
Aim: To find shortest distances from source to all vertices.

Theory: Repeatedly relax edges from current minimum-distance vertex.

Time Complexity: O((V + E) log V)

Space Complexity: O(V + E)

Algorithm:
1. Initialize source distance 0 and others infinity.
2. Use min-heap to get node with smallest tentative distance.
3. Relax all outgoing edges.
4. Update distances and push improved states.

![Dijkstra Graph](06Lecture/Images/dijkstra.png)

### Practical 3: Kruskal's Minimum Spanning Tree
Aim: To construct MST using Kruskal's algorithm.

Theory: Add minimum-weight edges without forming cycles.

Time Complexity: O(E log E)

Space Complexity: O(V)

Algorithm:
1. Sort all edges by weight.
2. Initialize disjoint set.
3. For each edge, if endpoints are in different sets, include edge.
4. Union the sets.
5. Stop after selecting V-1 edges.

![Kruskal Graph](06Lecture/Images/kruskal.png)

### Practical 4: Prim's Minimum Spanning Tree
Aim: To construct MST using Prim's algorithm.

Theory: Grow MST by repeatedly selecting minimum edge crossing cut.

Time Complexity: O(V^2)

Space Complexity: O(V)

Algorithm:
1. Start with one vertex in MST.
2. Maintain minimum key for all vertices outside MST.
3. Pick vertex with minimum key and include it.
4. Update keys of adjacent vertices.

![Prim's Graph](06Lecture/Images/prims.png)

## Lecture 07

### Practical 1: Multi-Stage Graph Minimum Cost Path
Aim: To find minimum cost path from source to destination in multi-stage graph.

Theory: Build stages and evaluate minimum transition cost toward destination.

Time Complexity: O(V^2)

Space Complexity: O(V^2)

Algorithm:
1. Represent graph using adjacency matrix.
2. Build stage groups from source.
3. Process stages backward to compute minimum path cost.
4. Output final minimum cost.

![Multi-Stage Graph](07Lecture/Images/multiStage.png)

## Lecture 08

### Practical 1: Multi-Stage Graph (Forward Approach)
Aim: To find minimum cost path using forward dynamic programming.

Theory: Relax forward edges from source and keep best known cost.

Time Complexity: O(n^2)

Space Complexity: O(n^2)

Algorithm:
1. Initialize dist[source] = 0 and others infinity.
2. Traverse nodes in forward order.
3. Relax valid forward edges.
4. Track parent for path reconstruction.

![Forward Approach Graph](08Lecture/Images/forward.png)

### Practical 2: Multi-Stage Graph (Backward Approach)
Aim: To find minimum cost path using backward dynamic programming.

Theory: Compute minimum cost to destination for each node from back to front.

Time Complexity: O(n^2)

Space Complexity: O(n)

Algorithm:
1. Set destination cost to zero.
2. For each node from back to front, compute minimum outgoing cost.
3. Store best next node as decision.
4. Reconstruct path using decision array.

![Backward Approach Graph](08Lecture/Images/backward.png)

### Practical 3: Matrix Chain Multiplication (Dynamic Programming)
Aim: To find minimum scalar multiplications for matrix chain.

Theory: Try all split points and store minimum cost in DP table.

Time Complexity: O(n^3)

Space Complexity: O(n^2)

Algorithm:
1. Initialize DP diagonal as 0.
2. Increase chain length from 2 to n.
3. For each (i, j), test all split points k.
4. Store minimum cost and best split.

![Matrix Chain Multiplication Graph](08Lecture/Images/mcm.png)

## Lecture 09

### Practical 1: Floyd-Warshall Algorithm
Aim: To find shortest paths between all pairs of vertices.

Theory: Allow each vertex as intermediate and update all pair distances.

Time Complexity: O(V^3)

Space Complexity: O(V^2)

Algorithm:
1. Initialize distance matrix from graph.
2. For each intermediate k, process all i and j.
3. Update dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]).
4. Print final shortest path matrix.

![Floyd-Warshall Graph](09Lecture/Images/floydWarshall.png)

### Practical 2: Longest Common Subsequence (LCS)
Aim: To find length of longest common subsequence of two strings.

Theory: DP table stores best LCS length for all prefix pairs.

Time Complexity: O(n * m)

Space Complexity: O(n * m)

Algorithm:
1. Create DP table of size (n+1) x (m+1) with zeros.
2. If characters match, use diagonal + 1.
3. Else use max(top, left).
4. Final answer is dp[n][m].

## Lecture 10

### Practical 1: Traveling Salesman Problem
Aim: To find minimum tour cost visiting all cities and returning to start.

Theory: Use bitmask dynamic programming where state is (visited mask, last city).

Time Complexity: O(n^2 * 2^n)

Space Complexity: O(n * 2^n)

Algorithm:
1. Initialize dp[1][0] = 0 for starting city.
2. For each mask and last city u, try all unvisited cities v.
3. Update dp[mask | (1 << v)][v] with minimum cost.
4. From full mask, add return edge to source and take minimum.
