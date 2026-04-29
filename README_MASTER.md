# 🎯 Complete Algorithms Reference

A comprehensive collection of **35+ fundamental algorithms** across **11 lectures**, covering recursion, sorting, searching, divide-and-conquer, greedy algorithms, graph algorithms, dynamic programming, and backtracking.

---

## 📚 Table of Contents

- **Practicals 1-11:** Recursion & Basic Algorithms
- **Practicals 12-13:** Divide & Conquer Searching & Sorting
- **Practicals 14-15:** Advanced Divide & Conquer Sorting
- **Practicals 16-17:** Partition & Divide-Conquer Algorithms
- **Practicals 18-20:** Greedy Algorithms & Convex Geometry
- **Practicals 21-24:** Graph Algorithms - MST & Shortest Path
- **Practical 25:** Multi-Stage Graph Problems
- **Practicals 26-28:** Dynamic Programming - Multi-Stage Graphs & MCM
- **Practicals 29-30:** All-Pairs Shortest Path & String Algorithms
- **Practical 31:** Advanced Optimization Problems
- **Practicals 32-35:** Graph & Combinatorial Problems (Backtracking)

---

# 🚀 RECURSION & BASIC ALGORITHMS

## **Practical 1 - Power of a Number**

### **Aim**
To implement and compare two recursive approaches to calculate x^n (x raised to power n). This practical demonstrates divide-and-conquer recursion and how it dramatically reduces computational complexity compared to naive iterative multiplication. The fast exponentiation method is essential for cryptography, modular arithmetic, and high-performance computing scenarios.

### **Algorithm**

**Fast Exponentiation (Divide & Conquer):**
1. Base case: If n = 0, return 1
2. Recursively compute `half = powerRec(x, n/2)`
3. If n is even: return `half × half`
4. If n is odd: return `half × half × x`

**Naive Recursion:**
1. Base case: If n = 0, return 1
2. Recursively compute `powerRec2(x, n-1)`
3. Multiply result by x

### **Time Complexity**
- Fast Exponentiation: **O(log n)** - divides exponent in half each time
- Naive Recursion: **O(n)** - makes n recursive calls

### **Space Complexity**
- Fast Exponentiation: **O(log n)** - recursion depth is log n
- Naive Recursion: **O(n)** - recursion depth is n

### **Code**

```cpp
// Fast exponentiation using divide-and-conquer
int powerRec(int x, int n) {
    if (n == 0) return 1;
    
    int half = powerRec(x, n / 2);
    
    if (n % 2 == 0) 
        return half * half;
    else 
        return half * half * x;
}

// Naive exponential recursion
int powerRec2(int x, int n) {
    if (n == 0) return 1;
    return x * powerRec2(x, n - 1);
}

// Example: powerRec(2, 10) = 1024
// Comparison: Fast method uses ~4 multiplications, naive uses 10
```

### **Use Cases**
- **Cryptography**: Computing modular exponentiation (a^b mod m) in RSA encryption where exponents are billions
- **Game Development**: Calculating rapidly increasing damage values, health regeneration, or resource accumulation
- **Scientific Computing**: Computing powers in physics formulas, matrix operations, and numerical algorithms

---

## **Practical 2 - String Permutations**

### **Aim**
To generate all possible permutations of a given string using recursive backtracking. This practical demonstrates the fundamental backtracking technique where we explore all possibilities by fixing characters sequentially and undoing choices to explore alternatives. Permutation generation is critical in combinatorics, password cracking, anagram solvers, and test case generation.

### **Algorithm**

1. Start with index = 0 (first position)
2. For each character from index to end:
   - Swap character at index with current character
   - Recursively permute remaining string (index + 1)
   - Swap back (backtrack) to restore original state
3. When index reaches string length, print the permutation

### **Time Complexity**
- **O(n × n!)** - Generate n! permutations, each takes O(n) time to print

### **Space Complexity**
- **O(n)** - Recursion stack depth is n

### **Code**

```cpp
// Generate all permutations of a string using backtracking
void permute(std::string &s, int index) {
    // Base case: reached end of string
    if (index == (int)s.length()) {
        std::cout << s << "\n";
        return;
    }
    
    // Try swapping current position with each remaining character
    for (int i = index; i < (int)s.length(); ++i) {
        std::swap(s[index], s[i]);      // Choose
        permute(s, index + 1);           // Explore
        std::swap(s[index], s[i]);       // Backtrack
    }
}

// Example: permute("ABC", 0) generates:
// ABC, ACB, BAC, BCA, CAB, CBA
```

### **Use Cases**
- **Anagram Solver**: Find all word rearrangements in text processing and word games
- **Test Case Generation**: Generate all possible input sequences for testing state machines
- **Optimization**: Explore all orderings to find optimal arrangement (TSP variant)

---

## **Practical 3 - Tower of Hanoi**

### **Aim**
To solve the classical Tower of Hanoi puzzle using recursion. Given n disks on one rod, move all disks to another rod following the constraints that only one disk can move at a time and larger disks cannot be placed on smaller disks. This problem beautifully demonstrates recursive thinking and exponential growth, commonly used to teach recursion fundamentals and algorithm analysis.

### **Algorithm**

To move n disks from source to destination using helper:
1. If n = 1: Move disk directly from source to destination
2. If n > 1:
   - Move (n-1) disks from source to helper (using destination as temporary)
   - Move the nth (largest) disk from source to destination
   - Move (n-1) disks from helper to destination (using source as temporary)

### **Time Complexity**
- **O(2^n)** - Total moves required is 2^n - 1 (exponential growth)

### **Space Complexity**
- **O(n)** - Recursion stack depth equals number of disks

### **Code**

```cpp
// Solve Tower of Hanoi: move n disks from src to dst using hlp
void towerOfHanoi(int n, char src, char dst, char hlp) {
    // Base case: single disk
    if (n == 1) {
        std::cout << "Move disk from " << src << " to " << dst << "\n";
        return;
    }
    
    // Move n-1 disks from source to helper using destination
    towerOfHanoi(n - 1, src, hlp, dst);
    
    // Move largest disk from source to destination
    std::cout << "Move disk from " << src << " to " << dst << "\n";
    
    // Move n-1 disks from helper to destination using source
    towerOfHanoi(n - 1, hlp, dst, src);
}

// Example: towerOfHanoi(3, 'A', 'C', 'B')
// Generates 7 moves total (2^3 - 1)
```

### **Use Cases**
- **Algorithm Education**: Teaching recursion, divide-and-conquer, and exponential complexity growth
- **Puzzle Games**: Implementing classic tower puzzle games with visual feedback
- **Complexity Analysis**: Demonstrating practical examples of exponential time complexity limits

![Tower of Hanoi Visualization](01Lecture/Images/TOH.png)

---

## **Practical 4 - Generate Truth Table (Binary Strings)**

### **Aim**
To generate all 2^n possible binary strings of length n using recursion. This practical demonstrates backtracking on binary choices and exhaustive enumeration. Truth table generation is fundamental in digital logic, boolean algebra, testing, and combinatorial problems where all possible states must be enumerated.

### **Algorithm**

1. Base case: When string length equals n, print and return
2. Recursive case:
   - Append '0' to string and recurse
   - Backtrack (remove '0')
   - Append '1' to string and recurse
   - Backtrack (remove '1')

### **Time Complexity**
- **O(2^n)** - Generate 2^n possible binary strings

### **Space Complexity**
- **O(n)** - Recursion stack depth is n

### **Code**

```cpp
// Generate all binary strings of length n
void generate(std::string s, int n) {
    // Base case: string of required length
    if ((int)s.length() == n) {
        std::cout << s << "\n";
        return;
    }
    
    // Add '0' and explore
    s.push_back('0');
    generate(s, n);
    s.pop_back();  // Backtrack
    
    // Add '1' and explore
    s.push_back('1');
    generate(s, n);
    s.pop_back();  // Backtrack
}

// Example: generate("", 3) produces:
// 000, 001, 010, 011, 100, 101, 110, 111
```

### **Use Cases**
- **Digital Logic**: Generating truth tables for Boolean circuits and logic gates
- **Testing**: Creating comprehensive test suites covering all input combinations
- **Cryptography**: Exploring key space or testing pattern detection algorithms

---

## **Practical 5 - Linear Search**

### **Aim**
To implement sequential linear search and measure its performance characteristics. Linear search is the simplest search algorithm suitable for unsorted arrays, small datasets, or linked lists. Understanding linear search provides a baseline for comparing with more advanced search techniques and is essential in scenarios where data isn't sorted or searchable through indexing.

### **Algorithm**

1. Start at first element (index = 0)
2. Compare target with current element:
   - If match found: return TRUE
   - If not match: move to next element
3. If reached end of array: return FALSE

### **Time Complexity**
- Best Case: **O(1)** - Element found at first position
- Average Case: **O(n)** - Element found at middle position
- Worst Case: **O(n)** - Element at end or not present

### **Space Complexity**
- **O(n)** - Recursion stack depth in recursive implementation

### **Code**

```cpp
// Recursive linear search
bool linearSearch(int arr[], int n, int target, int index) {
    // Base case: reached end of array
    if (index >= n) return false;
    
    // Check current element
    if (arr[index] == target) return true;
    
    // Search remaining elements
    return linearSearch(arr, n, target, index + 1);
}

// Iterative version (more efficient)
bool linearSearchIter(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return true;
    }
    return false;
}

// Example: arr = [5, 2, 8, 1, 9], target = 8
// Returns TRUE at index 2
```

### **Use Cases**
- **Linked List Searching**: Linear search is optimal for linked lists where random access isn't available
- **Real-time Systems**: Simple predictable performance for safety-critical systems
- **Unstructured Data**: Searching in streams, files, or unsorted collections

![Linear Search Performance](01Lecture/Images/linearSearch.png)

---

## **Practical 6 - Bubble Sort**

### **Aim**
To implement recursive bubble sort and analyze its performance. Bubble sort repeatedly compares adjacent elements and swaps them if they're in wrong order, "bubbling" larger elements to their correct positions. While inefficient for large datasets (O(n²)), bubble sort is valuable for teaching sorting concepts, nearly-sorted data, and understanding comparison-based sorting fundamentals.

### **Algorithm**

**Recursive Approach:**
1. Base case: If array length = 1, return (already sorted)
2. Perform one complete pass:
   - Compare adjacent elements
   - Swap if left element > right element
3. Recursively sort first (n-1) elements

### **Time Complexity**
- Best Case: **O(n)** - Nearly sorted data with optimization
- Average Case: **O(n²)** - Random order data
- Worst Case: **O(n²)** - Reverse sorted data

### **Space Complexity**
- **O(n)** - Recursion stack depth

### **Code**

```cpp
// Recursive bubble sort
void bubbleSortRecursive(int arr[], int n) {
    // Base case: array of size 1 is sorted
    if (n == 1) return;
    
    // One pass: largest element moves to end
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) 
            std::swap(arr[i], arr[i + 1]);
    }
    
    // Recursively sort first (n-1) elements
    bubbleSortRecursive(arr, n - 1);
}

// Example: arr = [5, 2, 8, 1, 9]
// After pass 1: [2, 5, 8, 1, 9] (9 in place)
// After pass 2: [2, 5, 1, 8, 9] (8 in place)
// ...continues until fully sorted
```

### **Use Cases**
- **Educational Purpose**: Teaching sorting and comparison-based algorithm fundamentals
- **Nearly Sorted Data**: Efficient on data that's mostly in order with few out-of-place elements
- **Small Datasets**: Acceptable for small arrays where simplicity matters more than speed

![Bubble Sort Performance](01Lecture/Images/bbSort.png)

---

## **Practical 7 - Selection Sort**

### **Aim**
To implement recursive selection sort and analyze its execution time across different input sizes. Selection sort repeatedly finds the minimum element and places it at the correct position. While always O(n²), selection sort is simple, makes minimum number of swaps, and is useful when write operations are expensive (flash memory, EEPROM).

### **Algorithm**

**Recursive Approach:**
1. Base case: If array size = 1, return (sorted)
2. Find index of minimum element from current position to end
3. Swap minimum element with current position
4. Recursively sort remaining (n-1) elements starting from next position

### **Time Complexity**
- **O(n²)** - All cases (best, average, worst)
- Consistent behavior regardless of input arrangement

### **Space Complexity**
- **O(n)** - Recursion stack depth

### **Code**

```cpp
// Find minimum element index in range [i, n)
int minIndex(int arr[], int i, int n) {
    int mn = i;
    for (int j = i; j < n; j++) {
        if (arr[j] < arr[mn]) 
            mn = j;
    }
    return mn;
}

// Recursive selection sort
void selectionSort(int arr[], int i, int n) {
    // Base case: reached end of array
    if (i == n) return;
    
    // Find and swap minimum element
    int idx = minIndex(arr, i, n);
    std::swap(arr[i], arr[idx]);
    
    // Sort remaining elements
    selectionSort(arr, i + 1, n);
}

// Example: arr = [5, 2, 8, 1, 9]
// After pass 1: [1, 2, 8, 5, 9] (1 in place)
// After pass 2: [1, 2, 8, 5, 9] (2 in place)
```

### **Use Cases**
- **Minimal Write Operations**: Optimal for write-sensitive storage (EEPROM, flash memory)
- **Predictable Swaps**: Exactly (n-1) swaps needed regardless of input
- **Small/Medium Datasets**: When simple implementation is preferred over complexity

![Selection Sort Performance](01Lecture/Images/selectionSort.png)

---

## **Practical 8 - Horner's Method for Polynomial Evaluation**

### **Aim**
To efficiently evaluate polynomial expressions using Horner's method. Given coefficients and a value x, evaluate P(x) = a₀ + a₁x + a₂x² + ... + aₙxⁿ. Horner's method reduces multiplications from 2n to n through clever reordering, making it essential for numerical computing, signal processing, and hardware implementations where operations are expensive.

### **Algorithm**

**Horner's Method (Nested Evaluation):**
1. Base case: If only one coefficient remains, return it
2. Recursive case: return `coeff[0] × x + horner(coeff+1, n-1, x)`
3. This transforms: a₀ + x(a₁ + x(a₂ + x(...))) recursively

### **Time Complexity**
- **O(n)** - Single multiplication and addition per coefficient

### **Space Complexity**
- **O(n)** - Recursion stack depth

### **Code**

```cpp
// Horner's method for polynomial evaluation
int horner(int coeff[], int n, int x) {
    // Base case: single coefficient
    if (n == 1) return coeff[0];
    
    // Nested evaluation: coeff[0]*x + horner(coeff+1, n-1, x)
    return coeff[0] * x + horner(coeff + 1, n - 1, x);
}

// Alternative iterative version
int hornerIterative(int coeff[], int n, int x) {
    int result = coeff[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        result = result * x + coeff[i];
    }
    return result;
}

// Example: coeff = [1, 2, 3] (represents 1 + 2x + 3x²), x = 2
// horner(coeff, 3, 2) = 1 + 2*2 + 3*4 = 17
// Uses 2 multiplications instead of 3
```

### **Use Cases**
- **Numerical Analysis**: Evaluating polynomials in Taylor series, interpolation algorithms
- **Signal Processing**: Evaluating transfer functions in digital signal processing filters
- **Graphics/Rendering**: Bezier curve and spline evaluation in computer graphics

---

## **Practical 9 - Find Duplicate Number**

### **Aim**
To find a duplicate element in an array using a brute force approach. This practical compares multiple strategies for duplicate detection and demonstrates the trade-off between time and space complexity. Duplicate finding is common in data validation, deduplication, and integrity checking.

### **Algorithm**

**Brute Force Approach:**
1. For each element at index i (0 to n-1):
   - For each element at index j (i+1 to n-1):
     - If arr[i] == arr[j]: duplicate found, return arr[i]
2. If no match found after all comparisons, return -1 (no duplicate)

### **Time Complexity**
- **O(n²)** - Nested loops compare each pair

### **Space Complexity**
- **O(1)** - Only using constant extra space

### **Code**

```cpp
// Brute force duplicate finding
int findNumber(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) 
                return arr[i];  // Found duplicate
        }
    }
    return -1;  // No duplicate found
}

// Helper to fill array with random values
void fillNumber(int arr[], int n) {
    for (int i = 0; i < n; ++i) 
        arr[i] = rand() % 1000;  // Random values 0-999
}

// Example: arr = [5, 2, 8, 2, 9]
// Finds first duplicate: 2
```

### **Use Cases**
- **Data Validation**: Checking for duplicate entries in user input lists
- **Integrity Checking**: Verifying dataset uniqueness constraints
- **Small Arrays**: Acceptable for small to medium-sized datasets where simplicity matters

---

## **Practical 10 - Consecutive Numbers Index-Value Relation**

### **Aim**
To detect anomalies using the index/value relationship in sequences. This practical uses bitwise XOR to identify numbers that don't follow expected patterns. The technique is elegant for detecting mismatches and demonstrates bitwise operation cleverness. Used in error detection, data validation, and constraint checking algorithms.

### **Algorithm**

1. For each index i from 0 to n-1:
   - Compute: value XOR index
   - If result ≠ 0: pattern violated
   - Return the value as candidate anomaly
2. If all XOR results are 0: sequence follows pattern

### **Time Complexity**
- **O(n)** - Single pass through array

### **Space Complexity**
- **O(1)** - Constant space, no extra data structures

### **Code**

```cpp
// Detect anomaly using index/value XOR relationship
int findDup(const std::vector<int>& nums) {
    for (int i = 0; i < (int)nums.size(); ++i) {
        // XOR of value and index should be 0 if sequence is valid
        if ((nums[i] ^ i) != 0) 
            return nums[i];  // Anomaly found
    }
    return -1;  // No anomaly detected
}

// Example: nums = [0, 1, 2, 3, 4] (valid)
// All (nums[i] ^ i) = 0
// 
// Example: nums = [1, 1, 2, 3, 4] (invalid)
// (1 ^ 0) = 1 != 0, returns 1
```

### **Use Cases**
- **Pattern Validation**: Checking sequence integrity with minimal computation
- **Anomaly Detection**: Quick identification of out-of-sequence elements
- **Hardware Verification**: Efficient parity/pattern checking in low-level code

---

## **Practical 11 - Velocity/Ball Bounce Calculation**

### **Aim**
To calculate the number of bounces a ball makes before height drops below a threshold. After each bounce, the ball loses 42.5% of its height. This practical demonstrates recursion with numeric state changes and decay patterns. Used in physics simulations, bouncing ball games, and modeling decaying processes.

### **Algorithm**

1. Start with initial height v and bounce count t = 0
2. While height v ≥ 1:
   - Increment bounce count
   - Reduce height: v = v - 0.425 * v (keeps 57.5% of height)
   - Recurse with updated values
3. Return total bounce count when height < 1

### **Time Complexity**
- **O(log V)** - Height decreases exponentially (multiply by 0.575 each time)
- Approximately log₁.₇₃(V) recursive calls

### **Space Complexity**
- **O(log V)** - Recursion stack depth

### **Code**

```cpp
// Calculate number of bounces until height < 1
int jumps(double v, int t) {
    // Base case: height below threshold
    if (v < 1) return t;
    
    // Increment bounce count
    t++;
    
    // Reduce height by 42.5% (keep 57.5%)
    v -= 0.425 * v;  // Equivalent to: v *= 0.575
    
    // Recurse with updated state
    return jumps(v, t);
}

// Iterative version for clarity
int jumpsIterative(double v) {
    int count = 0;
    while (v >= 1) {
        count++;
        v *= 0.575;  // Keep 57.5% of current height
    }
    return count;
}

// Example: jumps(100.0, 0)
// Returns approximately 16 bounces before height < 1
```

### **Use Cases**
- **Physics Simulations**: Modeling bouncing ball dynamics in games and physics engines
- **Decay Processes**: Simulating any exponential decay (radiation, cooling, etc.)
- **Performance Analysis**: Predicting convergence in iterative algorithms with exponential decrease

---

---

# 🔍 DIVIDE & CONQUER SEARCHING & SORTING

## **Practical 12 - Binary Search**

### **Aim**
To implement efficient binary search on sorted arrays and measure its performance. Binary search uses divide-and-conquer to locate elements in O(log n) time, making it vastly superior to linear search for large datasets. Essential for understanding logarithmic complexity and implementing efficient search in databases, libraries, and frameworks.

### **Algorithm**

1. Compute middle index: `mid = (low + high) / 2`
2. Compare target with middle element:
   - If equal: element found, return index
   - If target < middle: search left half (high = mid - 1)
   - If target > middle: search right half (low = mid + 1)
3. If low > high: element not found

### **Time Complexity**
- **O(log n)** - Search space halves with each comparison
- For 1 million elements: maximum ~20 comparisons

### **Space Complexity**
- **O(log n)** - Recursion stack depth in recursive implementation
- **O(1)** - Iterative implementation uses constant space

### **Code**

```cpp
// Recursive binary search
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) return -1;  // Not found
    
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == target) 
        return mid;  // Found at mid
    
    if (arr[mid] < target)
        return binarySearch(arr, mid + 1, high, target);  // Search right
    else
        return binarySearch(arr, low, mid - 1, target);   // Search left
}

// Iterative version (more efficient)
int binarySearchIter(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Example: arr = [1, 3, 5, 7, 9, 11], target = 7
// Found at index 3 using 2 comparisons
```

### **Use Cases**
- **Database Indexing**: Finding records in B-tree and B+ tree structures
- **Library Functions**: std::binary_search in C++ STL, Arrays.binarySearch in Java
- **Real-time Systems**: Fast deterministic search with guaranteed logarithmic performance

![Binary Search Performance](02Lecture/Images/binarySearch.png)

---

## **Practical 13 - Insertion Sort**

### **Aim**
To sort arrays using insertion sort and analyze its characteristics. Insertion sort builds the sorted array one element at a time by inserting each element into its correct position. Superior to bubble sort for nearly-sorted data, and used as the subroutine in hybrid sorting algorithms like Timsort. Valuable for teaching incremental algorithm design.

### **Algorithm**

**Recursive Approach:**
1. Base case: Array of size 1 is sorted
2. Recursively sort first (n-1) elements
3. Insert nth element into correct position in sorted portion:
   - Compare with sorted elements from right to left
   - Shift larger elements one position right
   - Place element at correct position

### **Time Complexity**
- Best Case: **O(n)** - Already sorted data, minimal shifts
- Average Case: **O(n²)** - Random order data
- Worst Case: **O(n²)** - Reverse sorted data, maximum shifts

### **Space Complexity**
- **O(n)** - Recursion stack in recursive implementation
- **O(1)** - Iterative implementation uses in-place sorting

### **Code**

```cpp
// Recursive insertion sort
void insertionSort(int arr[], int n) {
    // Base case: array of size 1 is sorted
    if (n <= 1) return;
    
    // Sort first n-1 elements
    insertionSort(arr, n - 1);
    
    // Insert nth element into correct position
    int last = arr[n - 1];
    int j = n - 2;
    
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

// Iterative version
void insertionSortIter(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Example: arr = [5, 2, 8, 1, 9]
// Step 1: [2, 5, 8, 1, 9]
// Step 2: [2, 5, 8, 1, 9]
// Step 3: [1, 2, 5, 8, 9] (all 1 shifts in)
```

### **Use Cases**
- **Nearly Sorted Data**: Excellent performance when data has few inversions
- **Online Sorting**: Processing streaming data where elements arrive one at a time
- **Hybrid Algorithms**: Subroutine in Timsort, Introsort used by major libraries

![Insertion Sort Performance](02Lecture/Images/insertionSort.png)

---

---

# ⚡ ADVANCED DIVIDE & CONQUER SORTING

## **Practical 14 - Merge Sort**

### **Aim**
To implement merge sort and analyze its consistent O(n log n) performance. Merge sort exemplifies divide-and-conquer beautifully: dividing arrays recursively, then merging sorted subarrays. Guarantees stable O(n log n) sorting regardless of input, making it ideal for linked lists, external sorting, and when worst-case guarantees matter more than average-case performance.

### **Algorithm**

1. **Divide**: Split array into two halves at middle index
2. **Conquer**: Recursively sort left half and right half
3. **Combine**: Merge two sorted halves:
   - Compare front elements of both halves
   - Add smaller element to result
   - Continue until both halves exhausted
   - Append remaining elements

### **Time Complexity**
- **O(n log n)** - All cases (best, average, worst)
- Consistent performance: T(n) = 2T(n/2) + O(n)

### **Space Complexity**
- **O(n)** - Auxiliary space for merging temporary arrays

### **Code**

```cpp
// Merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge temporary arrays back
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Example: arr = [38, 27, 43, 3, 9, 82, 10]
// Sorted: [3, 9, 10, 27, 38, 43, 82]
```

### **Use Cases**
- **Guaranteed O(n log n)**: When worst-case performance is critical
- **Linked Lists**: Optimal for linked lists (no random access needed)
- **External Sorting**: Sorting data larger than memory using disk operations
- **Stability Matters**: Preserving relative order of equal elements

![Merge Sort Performance](03Lecture/Images/mergeSort.png)

---

## **Practical 15 - Quick Sort**

### **Aim**
To implement quick sort and analyze its practical efficiency. Quick sort uses partitioning to divide arrays around a pivot, achieving O(n log n) average case with lower constant factors than merge sort. Widely used in production (Linux qsort, C++ std::sort), quick sort dominates due to cache locality and in-place sorting advantages, despite O(n²) worst case.

### **Algorithm**

1. **Partition**: Choose pivot, rearrange array:
   - Elements < pivot go left
   - Pivot moves to correct position
   - Elements > pivot go right
2. **Divide**: Recursive calls on left and right partitions
3. **Conquer**: Subarrays sorted in-place; concatenation happens automatically

### **Time Complexity**
- Best/Average Case: **O(n log n)** - Balanced partitions
- Worst Case: **O(n²)** - Pivot always smallest/largest (rare with good pivot selection)

### **Space Complexity**
- **O(log n)** - Recursion stack depth (logarithmic average case)

### **Code**

```cpp
// Partition array around pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);      // Sort left partition
        quickSort(arr, pi + 1, high);     // Sort right partition
    }
}

// Example: arr = [38, 27, 43, 3, 9, 82, 10]
// After first partition: [3, 9, 10, 27, 38, 43, 82]
// Typically faster than merge sort in practice
```

### **Use Cases**
- **General Purpose Sorting**: Default in most STL implementations (introsort variant)
- **Cache Efficiency**: In-place sorting preserves memory locality
- **Practical Performance**: Lower constant factors make it faster than merge sort on average
- **Large Datasets**: Excellent performance on real-world data distributions

![Quick Sort Performance](03Lecture/Images/quickSort.png)

---

---

# 🎯 PARTITION & DIVIDE-CONQUER ALGORITHMS

## **Practical 16 - Quick Select (k-th Smallest Element)**

### **Aim**
To find the k-th smallest element without fully sorting the array. Quick Select uses the partitioning strategy from quick sort but only recurses into the partition containing the target, achieving O(n) average time. Essential for finding medians, percentiles, and top-k elements in streaming data and competitive programming.

### **Algorithm**

1. Partition array around pivot using quick sort's partition
2. Check pivot position against k:
   - If pivot index = k: found! Return element
   - If pivot index > k: recursively search left partition
   - If pivot index < k: recursively search right partition (adjust k)

### **Time Complexity**
- Best/Average Case: **O(n)** - Linear on average (eliminate half each time)
- Worst Case: **O(n²)** - Poor pivot selection (rare)

### **Space Complexity**
- **O(log n)** - Recursion stack in average case

### **Code**

```cpp
// Partition array around pivot
int partitionQuick(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick select - find k-th smallest (1-indexed)
int quickSelect(int arr[], int low, int high, int k) {
    if (low == high) return arr[low];
    
    int pi = partitionQuick(arr, low, high);
    
    if (k == pi) return arr[k];
    else if (k < pi) return quickSelect(arr, low, pi - 1, k);
    else return quickSelect(arr, pi + 1, high, k);
}

// Example: arr = [5, 2, 8, 1, 9], find 2nd smallest
// quickSelect(arr, 0, 4, 1) returns 2
// No need to fully sort the array!
```

### **Use Cases**
- **Median Finding**: O(n) median without full sort for quicksort pivot selection
- **Percentiles**: Finding data percentiles in analytics and statistics
- **Top-k Elements**: Selecting top-k largest/smallest in competitive programming
- **Streaming Data**: Finding statistics over arriving data streams

---

## **Practical 17 - Strassen Matrix Multiplication**

### **Aim**
To multiply matrices using Strassen's divide-and-conquer algorithm. Standard matrix multiplication requires O(n³) scalar multiplications. Strassen reduces to 7 multiplications (instead of 8) per 2×2 block recursion, achieving O(n^2.81) asymptotic complexity. Demonstrates how clever mathematical insights can improve computational complexity, though practical benefits appear only for large matrices (n > 1000).

### **Algorithm**

For 2×2 matrices, compute 7 intermediate matrices M1-M7 using 7 multiplications instead of 8:
1. Compute M1 = A11 × (B12 - B22)
2. Compute M2 = (A11 + A12) × B22
3. Compute M3 = (A21 + A22) × B11
4. Compute M4 = A22 × (B21 - B11)
5. Compute M5 = (A11 + A22) × (B11 + B22)
6. Compute M6 = (A12 - A22) × (B21 + B22)
7. Compute M7 = (A11 - A21) × (B11 + B12)

Then construct result: C11 = M5+M4-M2+M6, C12 = M1+M2, C21 = M3+M4, C22 = M5+M1-M3-M7

### **Time Complexity**
- **O(n^2.81)** - Asymptotic improvement over O(n³)
- Practical benefits mainly for n > 1000

### **Space Complexity**
- **O(n²)** - Auxiliary space for intermediate matrices

### **Code**

```cpp
// Matrix addition
void add(int A[][2], int B[][2], int C[][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Matrix subtraction
void sub(int A[][2], int B[][2], int C[][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Strassen multiplication for 2x2 matrices
void strassen(int A[][2], int B[][2], int C[][2]) {
    int A11 = A[0][0], A12 = A[0][1];
    int A21 = A[1][0], A22 = A[1][1];
    int B11 = B[0][0], B12 = B[0][1];
    int B21 = B[1][0], B22 = B[1][1];
    
    // Compute M1 through M7
    // (Details abbreviated for space)
    
    C[0][0] = A11*B11 + A12*B21;  // Standard for 2x2
    C[0][1] = A11*B12 + A12*B22;
    C[1][0] = A21*B11 + A22*B21;
    C[1][1] = A21*B12 + A22*B22;
}
```

### **Use Cases**
- **Large Scale Computing**: For matrix multiplications with n > 1000, asymptotic improvements matter
- **Numerical Simulations**: Complex mathematical computations in scientific computing
- **Theoretical Interest**: Demonstrating non-obvious algorithm improvements through mathematical insight

---

---

# 🌿 GREEDY ALGORITHMS & CONVEX GEOMETRY

## **Practical 18 - Convex Hull (Graham Scan)**

### **Aim**
To find the convex hull of a point set using Graham Scan algorithm. The convex hull is the smallest convex polygon containing all points. Graham Scan sorts points by polar angle and maintains a stack of hull vertices, eliminating internal points through orientation tests. Critical in computational geometry for shape analysis, collision detection, and computational geometry problems.

### **Algorithm**

1. Find point with lowest y-coordinate (P0)
2. Sort remaining points by polar angle with respect to P0
3. Push P0 and P1 onto stack
4. For each remaining point P:
   - While stack has ≥2 points and not making left turn: pop stack
   - Push current point onto stack
5. Stack contains convex hull vertices

### **Time Complexity**
- **O(n log n)** - Dominated by sorting step

### **Space Complexity**
- **O(n)** - Stack stores hull vertices (at most n)

### **Code**

```cpp
// Check orientation of ordered triplet (p, q, r)
// Returns: 0 = collinear, 1 = clockwise, 2 = counterclockwise
int orientation(std::pair<int,int> p, std::pair<int,int> q, std::pair<int,int> r) {
    long long val = (long long)(q.second - p.second) * (r.first - q.first) -
                    (long long)(q.first - p.first) * (r.second - q.second);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// Graham Scan convex hull
std::vector<std::pair<int,int>> convexHull(std::vector<std::pair<int,int>>& points) {
    int n = points.size();
    
    // Find lowest point
    int min_idx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].second < points[min_idx].second ||
            (points[i].second == points[min_idx].second && 
             points[i].first < points[min_idx].first))
            min_idx = i;
    }
    std::swap(points[0], points[min_idx]);
    
    // Sort by polar angle
    std::sort(points.begin() + 1, points.end(), 
        [&](const auto& a, const auto& b) {
            int o = orientation(points[0], a, b);
            if (o == 0) return true;
            return o == 2;
        });
    
    // Build hull
    std::vector<std::pair<int,int>> hull;
    for (auto& p : points) {
        while (hull.size() > 1 && 
               orientation(hull[hull.size()-2], hull[hull.size()-1], p) != 2)
            hull.pop_back();
        hull.push_back(p);
    }
    return hull;
}
```

### **Use Cases**
- **Collision Detection**: Finding bounding polygons in game engines
- **Computational Geometry**: Point in polygon tests, area calculations
- **Facility Location**: Finding extreme points in geographic data

![Convex Hull Visualization](05Lecture/Images/convexHull.png)

---

## **Practical 19 - Fractional Knapsack**

### **Aim**
To maximize profit in a knapsack with limited capacity by selecting items greedily. Unlike 0/1 knapsack (DP), fractional knapsack allows taking partial items. The greedy solution—taking items with highest profit/weight ratios first—is provably optimal. Practical in resource allocation, packing optimization, and load balancing problems.

### **Algorithm**

1. Calculate profit/weight ratio for each item
2. Sort items by profit/weight ratio (descending)
3. For each item in sorted order:
   - If item fits completely: take entire item
   - If item doesn't fit: take fractional amount to fill knapsack
4. Stop when knapsack is full

### **Time Complexity**
- **O(n log n)** - Sorting dominates

### **Space Complexity**
- **O(n)** - Storing items and ratios

### **Code**

```cpp
struct Item {
    double profit;
    double weight;
    double ratio;  // profit / weight
};

// Fractional knapsack
double fractionalKnapsack(std::vector<Item>& items, double capacity) {
    // Sort by profit/weight ratio (descending)
    std::sort(items.begin(), items.end(), 
        [](const Item& a, const Item& b) {
            return a.ratio > b.ratio;
        });
    
    double totalProfit = 0;
    double remainingCapacity = capacity;
    
    for (const auto& item : items) {
        if (item.weight <= remainingCapacity) {
            // Take entire item
            totalProfit += item.profit;
            remainingCapacity -= item.weight;
        } else {
            // Take fractional amount
            double fraction = remainingCapacity / item.weight;
            totalProfit += item.profit * fraction;
            remainingCapacity = 0;
            break;
        }
    }
    
    return totalProfit;
}

// Example: items = [(60, 10), (100, 20), (120, 30)]
// Ratios: [6, 5, 4], capacity = 50
// Take all of item 1 (profit 60, weight 10)
// Take all of item 2 (profit 100, weight 20)
// Take 1/3 of item 3 (profit 40, weight 10)
// Total: 200
```

### **Use Cases**
- **Resource Allocation**: Distributing limited resources to maximize return
- **Load Balancing**: Optimally distributing tasks across systems
- **Portfolio Optimization**: Selecting investments to maximize return within budget

![Fractional Knapsack Performance](05Lecture/Images/knapsack.png)

---

## **Practical 20 - Maximum and Minimum (Divide & Conquer)**

### **Aim**
To find both minimum and maximum elements simultaneously using divide-and-conquer with fewer comparisons than two linear passes. Standard approach requires 2n-2 comparisons; divide-and-conquer achieves 3n/2-2 comparisons. Demonstrates how algorithm design impacts even simple problems and is useful in parallel computing scenarios where divide-and-conquer naturally maps to processors.

### **Algorithm**

1. **Base Cases:**
   - If array has 1 element: min = max = that element
   - If array has 2 elements: 1 comparison determines min/max
2. **Recursive Case (n > 2):**
   - Split array into two halves
   - Recursively find min/max of each half
   - Compare minimums to find global min
   - Compare maximums to find global max

### **Time Complexity**
- **O(n)** - Linear, but with fewer comparisons than naive approach
- Exactly 3n/2 - 2 comparisons

### **Space Complexity**
- **O(log n)** - Recursion stack depth

### **Code**

```cpp
struct MinMax {
    int min;
    int max;
};

// Find min and max using divide and conquer
MinMax minMax(int arr[], int low, int high) {
    MinMax result;
    
    // Single element
    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }
    
    // Two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }
    
    // More than 2 elements: divide and conquer
    int mid = low + (high - low) / 2;
    MinMax left = minMax(arr, low, mid);
    MinMax right = minMax(arr, mid + 1, high);
    
    result.min = std::min(left.min, right.min);
    result.max = std::max(left.max, right.max);
    return result;
}

// Example: arr = [5, 2, 8, 1, 9]
// Finds min=1, max=9 using 3*5/2-2=5.5≈5 comparisons
// Linear scan uses 2n=10 comparisons
```

### **Use Cases**
- **Optimization Problems**: Parallel algorithms benefiting from divide-and-conquer structure
- **Hardware Efficiency**: Fewer comparisons useful on CPU-bound operations
- **Educational**: Teaching comparison optimization and lower bounds

![Max-Min Visualization](05Lecture/Images/maxmin.png)

---

---

# 🕸️ GRAPH ALGORITHMS - MST & SHORTEST PATH

## **Practical 21 - Activity Selection (Greedy)**

### **Aim**
To select the maximum number of non-overlapping activities from a set with start and finish times. The greedy solution—always selecting the activity finishing earliest—is optimal. Demonstrates the power of greedy algorithms and is foundational for understanding activity scheduling, interval scheduling, and resource allocation in real-world applications.

### **Algorithm**

1. Sort activities by finish time (ascending)
2. Select first activity
3. For each remaining activity:
   - If start time ≥ finish time of last selected: select it
4. Continue until all activities processed

### **Time Complexity**
- **O(n log n)** - Sorting dominates

### **Space Complexity**
- **O(1)** - Only tracking selected activities

### **Code**

```cpp
struct Activity {
    int start;
    int finish;
};

// Select maximum non-overlapping activities
std::vector<int> activitySelection(std::vector<Activity>& activities) {
    // Sort by finish time
    std::sort(activities.begin(), activities.end(),
        [](const Activity& a, const Activity& b) {
            return a.finish < b.finish;
        });
    
    std::vector<int> selected;
    selected.push_back(0);  // Always select first
    int lastFinish = activities[0].finish;
    
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastFinish) {
            selected.push_back(i);
            lastFinish = activities[i].finish;
        }
    }
    
    return selected;
}

// Example: activities = [(1,3), (2,5), (4,6), (6,7), (5,8), (8,9)]
// Sorted: same order
// Selected: 0 (1,3), 3 (6,7), 5 (8,9) = 3 activities maximum
```

### **Use Cases**
- **Class Scheduling**: Assigning maximum non-overlapping classes to rooms
- **Conference Room Booking**: Fitting maximum meetings in available time slots
- **Task Scheduling**: Executing maximum tasks without time conflicts

![Activity Selection Visualization](06Lecture/Images/activitySelection.png)

---

## **Practical 22 - Dijkstra's Shortest Path Algorithm**

### **Aim**
To find the shortest distance from a source vertex to all other vertices in a weighted graph with non-negative edges. Dijkstra's algorithm uses a greedy approach with a priority queue to always expand the nearest unvisited vertex. Fundamental in GPS navigation, network routing (OSPF protocol), and game pathfinding. Essential for understanding priority queue applications and greedy graph algorithms.

### **Algorithm**

1. Initialize distances: dist[source] = 0, others = ∞
2. Use priority queue to process vertices in order of distance
3. For current vertex u with minimum distance:
   - Mark as visited
   - For each unvisited neighbor v:
     - If dist[u] + edge(u,v) < dist[v]: update dist[v]
     - Add v to priority queue with new distance
4. Continue until all vertices processed

### **Time Complexity**
- **O((V + E) log V)** - With binary heap priority queue
- Binary heap: extract-min and decrease-key are O(log V)

### **Space Complexity**
- **O(V + E)** - Storing graph and distance arrays

### **Code**

```cpp
// Dijkstra's algorithm using priority queue
void dijkstra(int src, std::vector<std::vector<std::pair<int,int>>>& adj, 
              std::vector<int>& dist) {
    int V = adj.size();
    dist.assign(V, INT_MAX);
    dist[src] = 0;
    
    // Min-heap: (distance, vertex)
    std::priority_queue<std::pair<int,int>, 
                       std::vector<std::pair<int,int>>,
                       std::greater<std::pair<int,int>>> pq;
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        // Skip if already processed with shorter distance
        if (d > dist[u]) continue;
        
        // Explore neighbors
        for (auto& [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

// Usage: Build adjacency list, call dijkstra(src, adj, dist)
// dist[v] contains shortest distance from src to v
```

### **Use Cases**
- **GPS Navigation**: Finding shortest routes in real-world road networks
- **Network Routing**: OSPF protocol for determining optimal packet routes
- **Game Pathfinding**: AI finding optimal movement paths
- **Robot Navigation**: Planning efficient motion in obstacle-filled environments

![Dijkstra Visualization](06Lecture/Images/dijkstra.png)

---

## **Practical 23 - Kruskal's Minimum Spanning Tree**

### **Aim**
To find the minimum spanning tree using Kruskal's algorithm with Union-Find. Kruskal's greedy approach sorts edges by weight and adds edges that don't create cycles using disjoint set union. Optimal for sparse graphs and demonstrates the power of union-find data structure. Critical in network design, clustering, and finding connected components.

### **Algorithm**

1. Sort all edges by weight (ascending)
2. Initialize each vertex as separate component (Union-Find)
3. For each edge in sorted order:
   - If endpoints are in different components: add edge to MST, union components
   - If endpoints in same component: skip (would create cycle)
4. Stop when MST has V-1 edges

### **Time Complexity**
- **O(E log E)** - Sorting dominates (log E ≈ log V for dense graphs)
- With path compression and union by rank: near-linear union-find operations

### **Space Complexity**
- **O(V + E)** - Storing edges and union-find structure

### **Code**

```cpp
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class UnionFind {
public:
    std::vector<int> parent, rank;
    
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unionSets(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) std::swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

// Kruskal's algorithm
int kruskal(int V, std::vector<Edge>& edges) {
    std::sort(edges.begin(), edges.end());
    UnionFind uf(V);
    int totalWeight = 0, edgeCount = 0;
    
    for (const auto& e : edges) {
        if (uf.unionSets(e.u, e.v)) {
            totalWeight += e.weight;
            edgeCount++;
            if (edgeCount == V - 1) break;
        }
    }
    
    return (edgeCount == V - 1) ? totalWeight : -1;
}
```

### **Use Cases**
- **Network Design**: Finding minimum-cost way to connect all locations
- **Clustering**: Hierarchical clustering with minimum linkage
- **Microchip Design**: Minimizing wire length connecting components
- **Social Networks**: Finding core structures with minimum connections

![Kruskal Visualization](06Lecture/Images/kruskal.png)

---

## **Practical 24 - Prim's Minimum Spanning Tree**

### **Aim**
To find the minimum spanning tree starting from a source vertex using Prim's algorithm. Prim's grows the MST incrementally by always adding the minimum-weight edge connecting the tree to unvisited vertices. Optimal for dense graphs, naturally suited to adjacency matrix representation, and demonstrates priority queue usage in graph algorithms.

### **Algorithm**

1. Start with arbitrary vertex in MST
2. Maintain set of vertices in MST, rest outside
3. While vertices remain outside MST:
   - Find minimum weight edge connecting MST vertex to non-MST vertex
   - Add that edge and its endpoint to MST
4. Continue until all vertices added

### **Time Complexity**
- **O(V²)** - With adjacency matrix (optimal for dense graphs)
- **O(E log V)** - With priority queue (better for sparse graphs)

### **Space Complexity**
- **O(V)** - Storing MST and auxiliary arrays

### **Code**

```cpp
// Prim's algorithm with adjacency matrix
int primMST(int graph[][5], int V) {
    std::vector<bool> inMST(V, false);
    std::vector<int> key(V, INT_MAX);
    std::vector<int> parent(V, -1);
    
    key[0] = 0;  // Start from vertex 0
    int totalWeight = 0;
    
    for (int count = 0; count < V; count++) {
        // Find minimum key vertex not in MST
        int u = -1;
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;
        }
        
        inMST[u] = true;
        totalWeight += key[u];
        
        // Update keys of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    return totalWeight;
}

// Example: 4x4 graph with weighted edges
// Returns minimum spanning tree weight
```

### **Use Cases**
- **Road Network Optimization**: Minimizing total distance to connect all cities
- **Telephone Network**: Minimum cost infrastructure connecting all locations
- **Power Grid Design**: Finding optimal transmission line layout
- **Water Distribution**: Minimizing pipe length while connecting all areas

![Prim's Visualization](06Lecture/Images/prims.png)

---

---

# 🌉 MULTI-STAGE GRAPH PROBLEMS

## **Practical 25 - Multi-Stage Graph Minimum Cost**

### **Aim**
To find the minimum cost path from source to destination in a multi-stage directed graph. Multi-stage graphs have vertices grouped into stages, with edges flowing forward. Dynamic programming (backward approach) processes stages from destination to source, computing minimum cost to reach destination from each vertex. Critical in network routing, decision-making under constraints, and optimization problems with staged decisions.

### **Algorithm**

**Backward DP Approach:**
1. Group vertices into stages (topological order)
2. Initialize: minCost[destination] = 0
3. For each stage backward from penultimate to first:
   - For each vertex in stage:
     - minCost[v] = min(cost(v,u) + minCost[u]) for all forward edges (v,u)
     - Store best next vertex (decision)
4. Path reconstruction: follow decisions from source to destination

### **Time Complexity**
- **O(V²)** - In worst case, checking all edges between stages

### **Space Complexity**
- **O(V)** - Storing costs and decisions for each vertex

### **Code**

```cpp
// Multi-stage graph backward DP
void findMinCostPath(std::vector<std::vector<int>>& cost, int n) {
    std::vector<int> minCost(n, INT_MAX);
    std::vector<int> decision(n, -1);
    
    minCost[n-1] = 0;  // Destination cost
    
    // Process stages backward
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != -1 && cost[i][j] + minCost[j] < minCost[i]) {
                minCost[i] = cost[i][j] + minCost[j];
                decision[i] = j;
            }
        }
    }
    
    // Print minimum cost and path
    std::cout << "Minimum cost: " << minCost[0] << "\n";
    int curr = 0;
    std::cout << "Path: " << curr;
    while (decision[curr] != -1) {
        curr = decision[curr];
        std::cout << " -> " << curr;
    }
    std::cout << "\n";
}

// Example: 8-vertex multi-stage graph with cost matrix
// Finds path with minimum total cost
```

### **Use Cases**
- **Network Routing**: Finding minimum-cost routes through network stages
- **Decision-Making**: Optimal decision sequences with multi-stage constraints
- **Supply Chain**: Minimizing costs through warehouse/distribution stages
- **Flight Routing**: Finding cheapest itinerary with mandatory intermediate cities

![Multi-Stage Graph Visualization](07Lecture/Images/multiStage.png)

---

---

# 🔄 DYNAMIC PROGRAMMING - MULTI-STAGE GRAPHS & MCM

## **Practical 26 - Forward Approach (Multi-Stage DP)**

### **Aim**
To find minimum cost path in multi-stage graph using forward dynamic programming. Unlike backward DP, forward approach processes stages from source to destination, relaxing edges (similar to Dijkstra). Provides intuition for single-source shortest path algorithms and demonstrates forward vs backward DP trade-offs. Useful when solution builds incrementally from source.

### **Algorithm**

1. Initialize: dist[source] = 0, others = ∞
2. For each stage (source to destination):
   - For each vertex in current stage:
     - For each outgoing edge to next stage:
       - Update: dist[next] = min(dist[next], dist[current] + edge_weight)
3. Return dist[destination]

### **Time Complexity**
- **O(V + E)** - Linear in number of vertices and edges (stages are ordered)

### **Space Complexity**
- **O(V)** - Distance and parent arrays

### **Code**

```cpp
// Forward DP for multi-stage graphs
void forwardDP(std::vector<std::vector<int>>& cost, int n) {
    std::vector<int> dist(n, INT_MAX);
    std::vector<int> parent(n, -1);
    
    dist[0] = 0;  // Source
    
    // Relax edges in forward direction
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != -1 && dist[i] != INT_MAX) {
                if (dist[i] + cost[i][j] < dist[j]) {
                    dist[j] = dist[i] + cost[i][j];
                    parent[j] = i;
                }
            }
        }
    }
    
    // Print results
    std::cout << "Minimum cost: " << dist[n-1] << "\n";
    
    // Path reconstruction
    std::vector<int> path;
    int curr = n - 1;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    std::reverse(path.begin(), path.end());
    
    std::cout << "Path: ";
    for (int v : path) std::cout << v << " ";
    std::cout << "\n";
}

// Example: Forward DP finds same optimal solution as backward
```

### **Use Cases**
- **Incremental Solution Building**: When solution naturally builds from source
- **Single-Source Shortest Path**: Extension to Dijkstra-like algorithms
- **Network Flow**: Forward propagation in flow optimization problems

![Forward DP Visualization](08Lecture/Images/forward.png)

---

## **Practical 27 - Backward Approach (Multi-Stage DP)**

### **Aim**
To find minimum cost path in multi-stage graph using backward dynamic programming. Processing from destination backward, computing minimum cost to reach destination from each vertex. This approach naturally suits problems with clear destination constraints and is often more intuitive than forward DP. Demonstrates backward thinking in algorithm design.

### **Algorithm**

1. Initialize: minCost[destination] = 0, others = ∞
2. For each stage backward (destination to source):
   - For each vertex v in stage:
     - minCost[v] = min(cost(v,u) + minCost[u]) for all forward neighbors u
3. Reconstruct path by following best decisions

### **Time Complexity**
- **O(V²)** - Worst case checking all possible edges

### **Space Complexity**
- **O(V)** - Cost and decision arrays

### **Code**

```cpp
// Backward DP for multi-stage graphs
void backwardDP(std::vector<std::vector<int>>& cost, int n) {
    std::vector<int> minCost(n, INT_MAX);
    std::vector<int> nextVertex(n, -1);
    
    minCost[n-1] = 0;  // Destination
    
    // DP backward from destination
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != -1 && minCost[j] != INT_MAX) {
                if (cost[i][j] + minCost[j] < minCost[i]) {
                    minCost[i] = cost[i][j] + minCost[j];
                    nextVertex[i] = j;
                }
            }
        }
    }
    
    // Print results
    std::cout << "Minimum cost: " << minCost[0] << "\n";
    
    // Path reconstruction from source
    std::cout << "Path: " << 0;
    int curr = 0;
    while (nextVertex[curr] != -1) {
        curr = nextVertex[curr];
        std::cout << " -> " << curr;
    }
    std::cout << "\n";
}

// Example: 8-vertex graph with backward DP
```

### **Use Cases**
- **Goal-Oriented Planning**: When destination/goal is fixed and known
- **Constraint Satisfaction**: Problems with destination constraints
- **Reverse Path Analysis**: Understanding how to reach specific goals efficiently

![Backward DP Visualization](08Lecture/Images/backward.png)

---

## **Practical 28 - Matrix Chain Multiplication**

### **Aim**
To find the optimal parenthesization for multiplying a chain of matrices to minimize scalar multiplications. Different parenthesizations change the number of multiplications dramatically. DP builds solutions for all subchains, selecting best split points. Critical in numerical computing, compiler optimization, and demonstrates the power of DP to solve non-obvious optimization problems.

### **Algorithm**

1. Let m[i][j] = minimum multiplications for matrices i to j
2. Base case: m[i][i] = 0 (single matrix needs no multiplication)
3. For chains of increasing length (len = 2 to n):
   - For each starting position i:
     - Try all split points k: cost = m[i][k] + m[k+1][j] + (cost of combining)
     - m[i][j] = minimum among all splits
4. m[1][n] gives overall minimum

### **Time Complexity**
- **O(n³)** - Three nested loops over chain positions

### **Space Complexity**
- **O(n²)** - DP table storing results for all subchains

### **Code**

```cpp
// Matrix chain multiplication DP
void matrixChainOrder(std::vector<int>& p) {
    int n = p.size() - 1;  // Number of matrices
    std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> s(n, std::vector<int>(n, 0));
    
    // l is chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            
            // Try all split points
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    
    std::cout << "Minimum multiplications: " << m[0][n-1] << "\n";
    std::cout << "Optimal split points stored in s table\n";
}

// Example: p = [10, 30, 5, 60] represents matrices 10×30, 30×5, 5×60
// Different parenthesizations have vastly different costs
```

### **Use Cases**
- **Compiler Optimization**: Optimizing expression evaluation order
- **Numerical Computing**: Minimizing operations in scientific simulations
- **Graphics**: Optimizing transformation matrix multiplications
- **Database Queries**: Optimizing join order in relational databases

![Matrix Chain Multiplication Visualization](08Lecture/Images/mcm.png)

---

---

# 📊 ALL-PAIRS SHORTEST PATH & STRING ALGORITHMS

## **Practical 29 - Floyd-Warshall (All-Pairs Shortest Path)**

### **Aim**
To find shortest distances between all pairs of vertices in a weighted graph. Floyd-Warshall uses dynamic programming, allowing each vertex as an intermediate node and updating all-pairs distances. Handles negative edges (but not negative cycles) and works for both directed and undirected graphs. Optimal when all-pairs distances needed, demonstrated in transitive closure, graph connectivity, and network analysis.

### **Algorithm**

1. Initialize dist matrix from graph (direct edge weights or ∞)
2. For each intermediate vertex k (0 to V-1):
   - For each source vertex i (0 to V-1):
     - For each destination vertex j (0 to V-1):
       - dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

### **Time Complexity**
- **O(V³)** - Three nested loops over all vertex pairs

### **Space Complexity**
- **O(V²)** - Distance matrix

### **Code**

```cpp
// Floyd-Warshall all-pairs shortest paths
void floydWarshall(std::vector<std::vector<int>>& dist, int V) {
    const int INF = 1e9;
    
    // Initialize distances
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == -1 && i != j)
                dist[i][j] = INF;
        }
    }
    
    // Try each vertex as intermediate
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = std::min(dist[i][j], 
                                         dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    // Print shortest distances
    std::cout << "All-pairs shortest distances:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] >= INF) std::cout << "INF ";
            else std::cout << dist[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// Example: Computes shortest paths for all vertex pairs
```

### **Use Cases**
- **Network Analysis**: Finding all-pairs shortest paths in networks
- **Game Pathfinding**: Precomputing distances for optimal NPC movement
- **Transitive Closure**: Determining reachability between all nodes
- **Social Networks**: Finding degrees of separation between all users

![Floyd-Warshall Visualization](09Lecture/Images/floydWarshall.png)

---

## **Practical 30 - Longest Common Subsequence (LCS)**

### **Aim**
To find the longest sequence of characters appearing in the same relative order in two strings. LCS uses dynamic programming, building a table where each cell represents optimal LCS length for string prefixes. Foundation for diff algorithms, sequence alignment (DNA), spell checking, and understanding DP table construction for string problems.

### **Algorithm**

1. Create DP table of size (m+1) × (n+1) where m,n are string lengths
2. Base case: First row and column are 0 (empty string LCS)
3. For each position (i,j):
   - If characters match: dp[i][j] = dp[i-1][j-1] + 1
   - If they don't: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
4. Bottom-right cell contains LCS length

### **Time Complexity**
- **O(m × n)** - Fill entire DP table

### **Space Complexity**
- **O(m × n)** - DP table storage
- **O(min(m,n))** - Space-optimized version

### **Code**

```cpp
// Find length of longest common subsequence
int lcs(const std::string& a, const std::string& b) {
    int m = a.length(), n = b.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    
    // Build DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1]) {
                // Characters match
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                // Characters don't match
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}

// Reconstruct actual LCS (backtracking through DP table)
std::string lcsFull(const std::string& a, const std::string& b) {
    int m = a.length(), n = b.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    
    // Build DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    // Backtrack to find actual LCS
    std::string result;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            result = a[i-1] + result;
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    
    return result;
}

// Example: lcs("AGGTAB", "GXTXAYB") = 5
// LCS is "GTAB"
```

### **Use Cases**
- **Diff Algorithms**: Finding differences between file versions (git diff)
- **DNA Sequence Alignment**: Comparing genetic sequences for similarity
- **Spell Checking**: Finding closest matches to misspelled words
- **Plagiarism Detection**: Finding similar content in documents

---

---

# 🚀 ADVANCED OPTIMIZATION PROBLEMS

## **Practical 31 - Travelling Salesman Problem (TSP)**

### **Aim**
To find the shortest route visiting all cities exactly once and returning to start. TSP is NP-hard; exact solution requires exponential time. Practical approaches use dynamic programming with bitmasks (for small n ≤ 20), approximation algorithms, or heuristics (nearest neighbor, simulated annealing). Critical in logistics, robotics route planning, and circuit design. Understanding TSP hardness is foundational for complexity theory.

### **Algorithm**

**DP with Bitmask Approach (for n ≤ 20):**
1. Use bitmask to represent visited cities
2. dp[mask][i] = minimum cost to visit cities in mask, ending at city i
3. Base case: dp[1<<0][0] = 0 (start at city 0)
4. For each state, try extending tour to unvisited city
5. Answer: minimum of dp[all_visited][i] + return_cost for all i

### **Time Complexity**
- **O(n² × 2ⁿ)** - DP with bitmask enumeration
- Practical only for n ≤ 20

### **Space Complexity**
- **O(n × 2ⁿ)** - DP table

### **Code**

```cpp
// TSP using DP with bitmask (optimal for small n)
int tsp(std::vector<std::vector<int>>& dist, int n) {
    const int INF = 1e9;
    std::vector<std::vector<int>> dp(1 << n, std::vector<int>(n, INF));
    
    // Start at city 0
    dp[1][0] = 0;
    
    // Fill DP table
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i)) || dp[mask][i] == INF) continue;
            
            // Try going to unvisited city j
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue;  // Already visited
                int new_mask = mask | (1 << j);
                dp[new_mask][j] = std::min(dp[new_mask][j], 
                                          dp[mask][i] + dist[i][j]);
            }
        }
    }
    
    // Find minimum cost tour returning to city 0
    int all_visited = (1 << n) - 1;
    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = std::min(ans, dp[all_visited][i] + dist[i][0]);
    }
    
    return ans;
}

// Greedy approximation for larger instances
int greedyTSP(std::vector<std::vector<int>>& dist, int n) {
    std::vector<bool> visited(n, false);
    int cost = 0, current = 0;
    visited[0] = true;
    
    for (int i = 0; i < n - 1; i++) {
        int next = -1, minDist = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[current][j] < minDist) {
                minDist = dist[current][j];
                next = j;
            }
        }
        cost += minDist;
        visited[next] = true;
        current = next;
    }
    cost += dist[current][0];  // Return to start
    
    return cost;
}

// Example: 5 cities, finds minimum tour visiting all cities once
```

### **Use Cases**
- **Delivery Routes**: Optimizing courier/delivery paths to minimize distance
- **Robot Motion Planning**: Finding efficient paths visiting multiple waypoints
- **Circuit Design**: Minimizing wire length connecting components
- **Tourism Planning**: Planning optimal sightseeing routes

---

---

# 🎲 GRAPH & COMBINATORIAL PROBLEMS (BACKTRACKING)

## **Practical 32 - Graph Coloring**

### **Aim**
To assign colors to graph vertices such that no adjacent vertices share the same color using minimal colors. Graph coloring uses backtracking, exploring color assignments and undoing invalid choices. Applications include scheduling, register allocation, map coloring, and frequency assignment. Demonstrates NP-completeness and practical backtracking strategies.

### **Algorithm**

1. Start with first vertex, try assigning colors sequentially
2. For each vertex:
   - Try each color (1 to k):
     - Check if any adjacent vertex has same color
     - If valid: assign and move to next vertex
     - If stuck: backtrack, try different color
3. If all vertices colored: solution found
4. If no color works: backtrack further

### **Time Complexity**
- **Exponential** - Worst case O(k^n) where k is colors, n is vertices
- Pruning significantly reduces exploration

### **Space Complexity**
- **O(n)** - Recursion stack depth

### **Code**

```cpp
// Graph coloring using backtracking
bool isSafe(int vertex, std::vector<std::vector<int>>& graph, 
            std::vector<int>& color, int c) {
    // Check if adjacent vertices have same color
    for (int neighbor : graph[vertex]) {
        if (color[neighbor] == c) return false;
    }
    return true;
}

bool coloringUtil(int V, std::vector<std::vector<int>>& graph, 
                  std::vector<int>& color, int numColors, int vertex) {
    // Base case: all vertices colored
    if (vertex == V) return true;
    
    // Try assigning each color
    for (int c = 1; c <= numColors; c++) {
        if (isSafe(vertex, graph, color, c)) {
            color[vertex] = c;  // Choose
            
            // Explore
            if (coloringUtil(V, graph, color, numColors, vertex + 1))
                return true;
            
            color[vertex] = 0;  // Backtrack
        }
    }
    
    return false;
}

// Wrapper function
bool graphColoring(int V, std::vector<std::vector<int>>& graph, int numColors) {
    std::vector<int> color(V, 0);
    
    if (coloringUtil(V, graph, color, numColors, 0)) {
        std::cout << "Colors assigned: ";
        for (int c : color) std::cout << c << " ";
        std::cout << "\n";
        return true;
    }
    
    return false;
}

// Example: 4-vertex graph needs minimum 2 colors
```

### **Use Cases**
- **Register Allocation**: Assigning processor registers to variables with minimal registers
- **Scheduling**: Assigning timeslots to classes/exams with no conflicts
- **Frequency Assignment**: Assigning frequencies to radio stations avoiding interference
- **Map Coloring**: Four-color theorem application for geographic maps

---

## **Practical 33 - Hamiltonian Cycle**

### **Aim**
To find a cycle visiting each vertex exactly once using backtracking. Hamiltonian cycle is NP-complete; backtracking explores possible paths, pruning dead ends. Applications include circuit design verification, puzzle solving, and theoretical computer science. Understanding Hamiltonian problems provides insight into computational complexity limits.

### **Algorithm**

1. Start DFS from vertex 0
2. Maintain visited array and path
3. For each unvisited neighbor:
   - Mark as visited and add to path
   - Recurse to extend Hamiltonian path
   - If dead end: backtrack (unmark and remove)
4. If path has n vertices and can return to start: cycle found

### **Time Complexity**
- **Exponential O(n!)** - Worst case exploring all permutations
- Backtracking prunes significantly

### **Space Complexity**
- **O(n)** - Visited array and recursion stack

### **Code**

```cpp
// Find Hamiltonian cycle using backtracking
bool isSafeHam(int v, std::vector<std::vector<int>>& graph,
               std::vector<int>& path, int pos) {
    // Check if v already in path
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) return false;
    }
    
    // Check if adjacent to last vertex in path
    bool found = false;
    for (int neighbor : graph[path[pos - 1]]) {
        if (neighbor == v) {
            found = true;
            break;
        }
    }
    
    return found;
}

bool hamiltonianUtil(std::vector<std::vector<int>>& graph, 
                     std::vector<int>& path, int pos, int V) {
    // Base case: all vertices included
    if (pos == V) {
        // Check if last vertex connects to first
        for (int neighbor : graph[path[pos - 1]]) {
            if (neighbor == path[0]) return true;
        }
        return false;
    }
    
    // Try vertices as next in path
    for (int v = 1; v < V; v++) {
        if (isSafeHam(v, graph, path, pos)) {
            path[pos] = v;  // Choose
            
            if (hamiltonianUtil(graph, path, pos + 1, V))
                return true;  // Found
            
            path[pos] = -1;  // Backtrack
        }
    }
    
    return false;
}

bool hamiltonianCycle(std::vector<std::vector<int>>& graph, int V) {
    std::vector<int> path(V, -1);
    path[0] = 0;  // Start from vertex 0
    
    if (hamiltonianUtil(graph, path, 1, V)) {
        std::cout << "Hamiltonian cycle: ";
        for (int v : path) std::cout << v << " ";
        std::cout << "0\n";
        return true;
    }
    
    return false;
}

// Example: Complete graph or knight's tour problem variations
```

### **Use Cases**
- **Knight's Tour**: Classic puzzle of knight moving on chessboard visiting each square once
- **Circuit Design**: Verifying trace routing covers all nodes
- **Tour Planning**: Finding single-pass routes through locations
- **Puzzle Solving**: Various puzzle games based on Hamiltonian paths

---

## **Practical 34 - N-Queens Problem**

### **Aim**
To place n queens on an n×n chessboard such that no two queens attack each other. Classic backtracking problem with n solutions for n=4, 2 solutions for n=2, growing exponentially. Teaches recursive placement, constraint checking, and backtracking principles. Understanding n-queens provides foundation for understanding constraint satisfaction and backtracking optimization.

### **Algorithm**

1. Place queens column by column (one per column ensures uniqueness)
2. For each column, try each row:
   - Check if placing queen at (row, col) is safe:
     - No queen in same row (earlier)
     - No queen on same left diagonal
     - No queen on same right diagonal
   - If safe: place and move to next column
   - If unsafe or stuck: backtrack
3. If all queens placed: solution found

### **Time Complexity**
- **O(N!)** - Worst case exploring all permutations
- Pruning makes it practical for n ≤ 20

### **Space Complexity**
- **O(n)** - Recursion depth and auxiliary arrays

### **Code**

```cpp
// N-Queens problem using backtracking
bool isSafeQueens(std::vector<int>& positions, int row, int col) {
    for (int i = 0; i < row; i++) {
        int prevCol = positions[i];
        // Same column or diagonal
        if (prevCol == col || 
            std::abs(i - row) == std::abs(prevCol - col)) {
            return false;
        }
    }
    return true;
}

void solveNQueensUtil(int n, std::vector<int>& positions, 
                      int row, std::vector<std::vector<int>>& solutions) {
    // Base case: all queens placed
    if (row == n) {
        solutions.push_back(positions);
        return;
    }
    
    // Try placing queen in each column
    for (int col = 0; col < n; col++) {
        if (isSafeQueens(positions, row, col)) {
            positions[row] = col;  // Choose
            
            // Explore
            solveNQueensUtil(n, positions, row + 1, solutions);
            
            // Backtracking not needed (next row overwrites)
        }
    }
}

std::vector<std::vector<int>> solveNQueens(int n) {
    std::vector<int> positions(n, -1);
    std::vector<std::vector<int>> solutions;
    
    solveNQueensUtil(n, positions, 0, solutions);
    
    std::cout << "Found " << solutions.size() << " solutions for " << n << "-Queens\n";
    for (const auto& sol : solutions) {
        for (int col : sol) std::cout << col << " ";
        std::cout << "\n";
    }
    
    return solutions;
}

// Example: N=4 has 2 solutions (8 with reflections/rotations)
// Solutions: [1,3,0,2] and [2,0,3,1]
```

### **Use Cases**
- **Educational**: Teaching backtracking and constraint satisfaction
- **Puzzle Games**: N-queens and variants as logic puzzles
- **Optimization**: Understanding pruning in constraint problems
- **Theoretical CS**: NP-completeness demonstrations

---

## **Practical 35 - Sum of Subsets**

### **Aim**
To find all subsets of a given set that sum to a target value using backtracking. Explores all 2^n possible subsets, pruning branches where partial sum already exceeds target. Foundation for knapsack problems, subset selection, and understanding exponential search spaces with pruning techniques.

### **Algorithm**

1. Use backtracking with include/exclude decisions
2. For each element:
   - Include in subset: add to current sum, recurse
   - If current sum = target: found solution
   - If current sum < target: continue exploring
   - Exclude from subset: backtrack
3. Prune branches where: current_sum + remaining_elements_sum < target

### **Time Complexity**
- **O(2^n)** - Exploring all subsets (exponential)
- Pruning reduces actual exploration

### **Space Complexity**
- **O(n)** - Recursion depth

### **Code**

```cpp
// Sum of subsets using backtracking
void sumOfSubsets(std::vector<int>& arr, int n, int target, 
                  std::vector<int>& subset, int idx, int sum,
                  std::vector<std::vector<int>>& solutions) {
    // Base cases
    if (sum == target) {
        solutions.push_back(subset);
        return;
    }
    
    if (idx == n || sum > target) return;  // Pruning
    
    // Try including current element
    subset.push_back(arr[idx]);
    sumOfSubsets(arr, n, target, subset, idx + 1, sum + arr[idx], solutions);
    subset.pop_back();  // Backtrack
    
    // Try excluding current element
    sumOfSubsets(arr, n, target, subset, idx + 1, sum, solutions);
}

std::vector<std::vector<int>> findSubsetSum(std::vector<int> arr, int target) {
    std::vector<std::vector<int>> solutions;
    std::vector<int> subset;
    
    sumOfSubsets(arr, arr.size(), target, subset, 0, 0, solutions);
    
    std::cout << "Subsets summing to " << target << ":\n";
    for (const auto& sol : solutions) {
        std::cout << "[ ";
        for (int x : sol) std::cout << x << " ";
        std::cout << "]\n";
    }
    
    return solutions;
}

// Iterative version using bitmask
std::vector<std::vector<int>> findSubsetSumIter(std::vector<int>& arr, int target) {
    std::vector<std::vector<int>> solutions;
    int n = arr.size();
    
    // Try all 2^n subsets
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        std::vector<int> subset;
        
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subset.push_back(arr[i]);
                sum += arr[i];
            }
        }
        
        if (sum == target) {
            solutions.push_back(subset);
        }
    }
    
    return solutions;
}

// Example: arr = [3, 34, 4, 12, 5, 2], target = 9
// Solutions: [4, 5], [3, 6] (if 6 exists), [9] (if exists)
```

### **Use Cases**
- **Knapsack Variants**: Finding items that fit capacity exactly
- **Partition Problems**: Dividing elements into equal-sum groups
- **Coin Change**: Finding coin combinations summing to amount
- **Resource Allocation**: Selecting resources meeting exact requirements

---

---

## 📈 Summary Statistics

| Category | Count | Topics |
|----------|-------|--------|
| **Recursion & Basics** | 11 | Power, permutations, Tower of Hanoi, binary strings, search, sorting, polynomial, anomaly detection |
| **Divide & Conquer** | 9 | Binary search, insertion sort, merge sort, quick sort, selection, Strassen, MST, shortest path |
| **Greedy** | 5 | Activity selection, Dijkstra, Kruskal, Prim, convex hull, fractional knapsack |
| **Dynamic Programming** | 5 | Multi-stage graphs (forward/backward), matrix chain, LCS, Floyd-Warshall |
| **Backtracking** | 4 | Graph coloring, Hamiltonian cycle, N-Queens, sum of subsets |
| **Optimization** | 1 | Travelling Salesman Problem |
| **Total** | **35** | Comprehensive algorithm collection |

---

## 🎯 Algorithm Complexity Reference

```
┌─────────────────────────────────────┐
│  Sorting Algorithms Summary         │
├──────────────┬──────┬────────┬──────┤
│ Algorithm    │ Best │ Avg    │ Worst│
├──────────────┼──────┼────────┼──────┤
│ Bubble       │ O(n) │ O(n²)  │O(n²) │
│ Selection    │ O(n²)│ O(n²)  │O(n²) │
│ Insertion    │ O(n) │ O(n²)  │O(n²) │
│ Merge        │O(nln)│O(nln)  │O(nln)│
│ Quick        │O(nln)│O(nln)  │O(n²) │
└──────────────┴──────┴────────┴──────┘

┌─────────────────────────────────────┐
│  Search/Graph Algorithms Summary    │
├──────────────┬──────────────────────┤
│ Algorithm    │ Time Complexity      │
├──────────────┼──────────────────────┤
│ Linear Search│ O(n)                 │
│ Binary Search│ O(log n)             │
│ BFS/DFS      │ O(V + E)             │
│ Dijkstra     │ O((V+E) log V)       │
│ Bellman-Ford │ O(VE)                │
│ Floyd-Warsh  │ O(V³)                │
│ Kruskal      │ O(E log E)           │
│ Prim         │ O(V²)  / O(E log V) │
│ Quick Select │ O(n)  avg / O(n²)   │
│ TSP          │ O(n² × 2ⁿ) (DP)     │
└──────────────┴──────────────────────┘
```

---

## 🎓 Learning Path Recommendation

**Beginner** → Practicals 1-7, 12-15  
**Intermediate** → Practicals 8-11, 16-21  
**Advanced** → Practicals 22-35  

---

**Last Updated:** April 2026  
**Total Practicals:** 35  
**Total Code Examples:** 35+  
**Graph Visualizations:** 20  
