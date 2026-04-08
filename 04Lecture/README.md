## Practical-1: Quick Select Using Partition
## Aim

To find the k-th smallest element in an array using a partition-based divide and conquer approach.

## Theory

Quick Select is based on the partition idea used in Quick Sort.

The algorithm works as follows:

Choose a pivot element.

Partition the array so that elements smaller than or equal to pivot are on one side and larger elements are on the other.

If pivot index matches k, the required element is found.

If pivot index is smaller than k, search in the right part.

If pivot index is larger than k, search in the left part.

This avoids sorting the full array and usually works faster for selection.

## Time Complexity

Best Case: O(n)
Average Case: O(n)
Worst Case: O(n^2)

## Space Complexity

O(log n) (recursive stack in average case)

## What the Code Does

This program finds the k-th smallest element from five input numbers.

The partiton(arr, low, high) function places the pivot in its correct position and returns its index.

The find(arr, low, high, k) function recursively checks:

If the pivot index equals k, it returns that element.

If pivot index is smaller than k, it searches the right sub-array.

If pivot index is larger than k, it searches the left sub-array.

The main function takes 5 values and k from the user, then prints the k-th smallest value.

## Practical-2: Strassen Matrix Multiplication
## Aim

To multiply two square matrices using Strassen's divide and conquer algorithm.

## Theory

Strassen's algorithm reduces the number of recursive multiplications needed for matrix multiplication.

For a 2 x 2 block matrix, normal multiplication uses 8 multiplications.

Strassen reduces this to 7 multiplications by computing seven intermediate matrices M1 to M7.

The final result blocks are then constructed from these intermediate values.

This improves asymptotic time complexity compared to classical matrix multiplication.

## Time Complexity

O(n^log2(7)) ~ O(n^2.81)

## Space Complexity

O(n^2)

## What the Code Does

This program multiplies two square matrices recursively using Strassen's method.

The add(A, B) and sub(A, B) functions perform matrix addition and subtraction.

The strassen(A, B) function:

Splits both matrices into four sub-matrices.

Computes M1 to M7 recursively.

Builds C11, C12, C21, and C22 from these values.

Combines all blocks into the final result matrix.

The main function multiplies two sample 2 x 2 matrices and prints the result.
