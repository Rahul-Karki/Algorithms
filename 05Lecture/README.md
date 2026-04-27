## Practical-1: Convex Hull (Graham Scan)
## Aim

To find the convex hull of a set of points using Graham Scan.

## Theory

The convex hull is the smallest convex polygon that contains all given points.

Graham Scan works as follows:

Find the point with lowest y-coordinate (and lowest x if tie).

Sort remaining points by polar angle with respect to this point.

Traverse the sorted points and keep removing the last point while a non-left turn is formed.

The remaining stack of points forms the convex hull.

## Time Complexity

O(n log n) (due to sorting)

## Space Complexity

O(n)

## What the Code Does

This program computes the convex hull for a fixed set of 2D points.

The orientation(p, q, r) function checks turn direction.

The compare(p1, p2) function sorts points by polar angle around starting point p0.

The convexHull(points) function builds the hull by removing points that do not maintain counter-clockwise direction.

The main function prints all points present on the hull.

![Convex Hull Graph](Images/convexHull.png)

## Practical-2: Fractional Knapsack (Greedy Comparison)
## Aim

To maximize total profit for a knapsack with limited capacity using greedy strategies.

## Theory

In Fractional Knapsack, an item can be taken fully or partially.

The optimal greedy strategy is to pick items in descending order of profit/weight ratio.

The code compares three orderings:

By minimum weight.

By maximum profit.

By maximum profit per unit weight.

This helps observe which strategy gives the best result.

## Time Complexity

O(n log n) (sorting based approaches)

## Space Complexity

O(n)

## What the Code Does

This program generates random profit and weight values for n items and computes total profit for different greedy choices.

It stores items in three forms and sorts them according to each strategy.

For each ordering, it fills the knapsack until capacity ends and adds a fractional value if needed.

Finally, it prints the profit obtained by each approach.

![Fractional Knapsack Graph](Images/knapsack.png)

## Practical-3: Maximum and Minimum Using Divide and Conquer
## Aim

To find both minimum and maximum elements in an array using divide and conquer recursion.

## Theory

Instead of scanning linearly with many comparisons, divide and conquer splits the array into halves.

Each half recursively returns its minimum and maximum.

The global minimum and maximum are obtained by combining left and right results.

## Time Complexity

O(n)

## Space Complexity

O(log n) (recursive stack)

## What the Code Does

This program recursively finds minimum and maximum in an integer array.

The maxmin(arr, s, e) function handles three cases:

Single element: both min and max are that element.

Two elements: compare once and assign min/max.

More than two elements: split at mid, solve both halves, then combine results.

The main function calls maxmin and prints the final minimum and maximum values.

![Max-Min Graph](Images/maxmin.png)
