Lab 2 

Practical-1: Binary Search (Recursive) and Time Analysis
Aim

To implement Binary Search using recursion and analyze its execution time for different input sizes.

Theory

Binary Search is an efficient searching algorithm that works on a sorted array.
It follows the divide and conquer technique by repeatedly dividing the search interval into two halves.

The steps are:

Compare the target element with the middle element.

If equal, the element is found.

If the target is smaller, search the left sub-array.

If the target is larger, search the right sub-array.

Continue until the element is found or the search space becomes empty.

Binary Search is much faster than Linear Search for large datasets.

Time Complexity

Best Case: O(1)

Average Case: O(log n)

Worst Case: O(log n)

Space Complexity

O(log n) (recursive stack)

What the Code Does

This program searches for an element in a sorted array using recursive Binary Search.

The binarySearch(arr, low, high, target) function works as follows:
If low > high, the element is not present.
It calculates the middle index of the array.
If the middle element matches the target, it returns true.
If the target is smaller, it recursively searches the left half.
If the target is larger, it recursively searches the right half.

The getAverageTime(n) function:

Generates sorted arrays of size n

Searches for a random target element

Measures execution time using high resolution clock

Repeats the experiment 100 times

Calculates the average execution time

Graph

Practical-2: Insertion Sort and Time Analysis (Recursive)
Aim

To implement Insertion Sort using recursion and analyze its average execution time for different input sizes.

Theory

Insertion Sort is a comparison-based sorting algorithm.
It works by building a sorted portion of the array one element at a time.

At each step:

One element is taken from the unsorted portion.

It is inserted into its correct position in the sorted portion by shifting larger elements.

Recursive Insertion Sort sorts the first n − 1 elements and then inserts the nth element into the correct position.

Time Complexity

Best Case: O(n)

Average Case: O(n²)

Worst Case: O(n²)

Space Complexity

O(n) (recursive stack)

What the Code Does

This program sorts an array using recursive Insertion Sort and measures its execution time.

The insertionSortRecursive(arr, n) function:

Recursively sorts the first n − 1 elements.

Inserts the nth element into its correct position.

The getAverageTime(n) function:

Generates random arrays of size n

Sorts them using recursive Insertion Sort

Measures execution time using high resolution clock

Repeats the process 100 times

Calculates the average execution time

Graph

If you want, I can:

Match exact practical numbering used by your university

Add input/output examples

Add comparison tables (Binary vs Linear, Insertion vs Selection)

Help you generate actual graphs code (C++ / Python) for these images

Just say the word 🚀

not like this in the format i gave using **

Ahh got it now 👍
You want EXACTLY the same markdown style you used earlier, with ##, ###, and bold text using **, not a redesigned structure.
Below is a fresh README section you can paste directly into GitHub — same formatting, same tone, just Binary Search and Insertion Sort, and space left for graphs.

Algorithms
Practical-1: Binary Search
Aim

To search an element in a sorted array using Binary Search and analyze its time complexity.

Theory

Binary Search is a searching algorithm that works only on a sorted array.
It follows the divide and conquer approach by repeatedly dividing the search space into two halves.

At each step:

The middle element of the array is checked.

If the element matches the target, the search ends.

If the target is smaller, the left half is searched.

If the target is greater, the right half is searched.

This process continues until the element is found or the search space becomes empty.

Time Complexity

Best Case: O(1)

Average Case: O(log n)

Worst Case: O(log n)

Space Complexity

Recursive method: O(log n)

What the Code Does

This program searches for a target element using recursive Binary Search.

The binarySearch(arr, low, high, key) function works as follows:
If low > high, the element is not present.
It calculates the middle index of the array.
If the middle element is equal to the key, it returns success.
If the key is smaller, the function recursively searches the left half.
If the key is greater, the function recursively searches the right half.

Practical-2: Insertion Sort
Aim

To sort an array using Insertion Sort and analyze its time complexity.

Theory

Insertion Sort is a simple comparison-based sorting algorithm.
It works by dividing the array into a sorted and an unsorted part.

At each iteration:

One element from the unsorted part is selected.

The element is placed at the correct position in the sorted part by shifting larger elements.

This process is repeated until the entire array is sorted.

Time Complexity

Best Case: O(n)

Average Case: O(n²)

Worst Case: O(n²)

Space Complexity

Recursive method: O(n)

What the Code Does

This program sorts an array using recursive Insertion Sort.

The insertionSort(arr, n) function works as follows:
It recursively sorts the first n − 1 elements of the array.
The nth element is then inserted into its correct position by shifting elements.
This process continues until the array becomes fully sorted.
