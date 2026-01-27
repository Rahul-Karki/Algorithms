Algorithms
Practical-1: Power of a Number Using Recursion
Aim

To implement and compare two recursive methods to calculate the value of a number raised to the power n.

Theory

The problem of calculating xⁿ can be solved using recursion in two ways:

Optimized Recursive Method (Divide and Conquer)
This method reduces the number of recursive calls by dividing the exponent into halves. It computes the power for n/2 and uses it to calculate the final result efficiently.

Simple Recursive Method
This method computes the result by multiplying the base x repeatedly until the exponent becomes zero. It is easy to understand but inefficient for large values of n.

Time Complexity

Optimized recursive method: O(log n)

Simple recursive method: O(n)

Space Complexity

Optimized recursive method: O(log n) (due to recursive stack calls)

Simple recursive method: O(n) (deep recursive stack)

What the Code Does

This program calculates the power of a number using two different recursive approaches.

The powerRec(x, n) function implements the optimized recursive method.

If the exponent n is zero, it returns 1.

If n is negative, it converts it into a positive exponent.

The function recursively calculates x^(n/2) and stores it in a variable named half.

If the exponent is even, the result is half × half.

If the exponent is odd, the result is half × half × x.

This method significantly reduces the number of recursive calls and works efficiently for large values of n.

The powerRec2(x, n) function implements the simple recursive approach.

If the exponent is zero, it returns 1.

Otherwise, it multiplies x with the result of powerRec2(x, n − 1).

This process continues until the exponent becomes zero.

Although simple, this method requires more recursive calls and is slower for large values of n.

In the main() function, both methods are called with the same input values, and their results are printed for comparison.

Conclusion

Both recursive methods correctly compute the power of a number.
The optimized recursive approach is more efficient due to its reduced time and space complexity, making it preferable for large exponents, while the simple recursive method is easier to understand but less efficient.


Practical-2: Permutations of a String Using Recursion
Aim

To generate and display all possible permutations of a given string using recursion and backtracking.

Theory

Permutation of a string refers to all possible arrangements of its characters.
For a string of length n, the total number of permutations is n!.

This problem is efficiently solved using recursion with backtracking.
The idea is to fix one character at a time and recursively generate permutations for the remaining characters. After each recursive call, the string is restored to its original state to explore other possibilities.

Time Complexity

O(n × n!)
There are n! permutations, and printing each permutation of length n takes O(n) time.

Space Complexity

O(n)
Due to the recursive call stack depth.

What the Code Does

This program generates all permutations of a string using recursion.

The permute(s, index) function works as follows:

If the current index reaches the length of the string, the function prints the string and returns.

Otherwise, it iterates from the current index to the end of the string.

In each iteration, it swaps the character at the current index with the character at position i.

It then recursively calls the function for the next index (index + 1).

After the recursive call, the characters are swapped back to restore the original string (backtracking).

This ensures that all possible permutations are generated without repetition.

In the main() function:

The user is prompted to enter a string.

The permutation function is called starting from index 0, which generates and prints all permutations of the string.

Conclusion

The program successfully generates all permutations of a given string using recursion and backtracking.
This approach efficiently explores all possible arrangements while ensuring correctness by restoring the string after each recursive call.


