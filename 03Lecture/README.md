## Practical-1: Merge Sort
## Aim

To sort an array using Merge Sort and analyze its execution time for different input sizes.

## Theory

Merge Sort is an efficient, comparison-based sorting algorithm that follows the divide and conquer strategy.

The algorithm works as follows:

The array is divided into two equal halves.

Each half is recursively sorted.

The two sorted halves are merged to produce a single sorted array.

This division and merging process continues until the entire array is sorted.

Merge Sort guarantees consistent performance regardless of input order.

## Time Complexity

Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n log n)

## Space Complexity

O(n) (due to merging)

## What the Code Does

This program sorts an array using recursive Merge Sort.

The mergeSort(arr, left, right) function works as follows:

If left < right, the array is divided into two halves.

The left half is recursively sorted.

The right half is recursively sorted.

The merge(arr, left, mid, right) function merges the two sorted halves into a single sorted array.

This process continues until the full array is sorted.

The execution time is measured for different input sizes using a high-resolution clock, and the average time is calculated over multiple runs.

## Practical-2: Quick Sort
## Aim

To sort an array using Quick Sort and analyze its execution time for different input sizes.

## Theory

Quick Sort is a fast and widely used sorting algorithm based on the divide and conquer technique.

The algorithm works by selecting a pivot element and partitioning the array around the pivot.

The steps are:

Choose a pivot element from the array.

Rearrange the array so that elements smaller than the pivot are placed before it and larger elements after it.

Recursively apply the same process to the left and right sub-arrays.

Quick Sort performs very well in practice and is often faster than Merge Sort due to lower constant factors.

## Time Complexity

Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n²)

## Space Complexity

O(log n) (recursive stack)

## What the Code Does

This program sorts an array using recursive Quick Sort.

The quickSort(arr, low, high) function works as follows:

A pivot element is selected and the array is partitioned using the partition() function.

The pivot is placed in its correct position.

Elements to the left of the pivot are recursively sorted.

Elements to the right of the pivot are recursively sorted.

The process continues until the entire array becomes sorted.

The execution time is measured using a high-resolution clock and averaged over multiple runs for different input sizes