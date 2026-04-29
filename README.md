# Algorithms Practicals

A curated README for the Algorithms folder. It collects the practicals in one place and embeds graph snapshots wherever the repository already has them.

## What's Inside

- Recursion, sorting, and searching practicals.
- Divide-and-conquer, backtracking, and dynamic programming examples.
- Graph-based routines with generated plot previews.

## Featured Graphs

| Practical | Preview |
| --- | --- |
| Bubble Sort | ![Bubble Sort](01Lecture/Images/bbSort.png) |
| Linear Search | ![Linear Search](01Lecture/Images/linearSearch.png) |
| Merge Sort | ![Merge Sort](03Lecture/Images/mergeSort.png) |
| Quick Sort | ![Quick Sort](03Lecture/Images/quickSort.png) |
| Convex Hull | ![Convex Hull](05Lecture/Images/convexHull.png) |
| Dijkstra | ![Dijkstra](06Lecture/Images/dijkstra.png) |
| Multi-Stage Graph | ![Multi-Stage Graph](07Lecture/Images/multiStage.png) |
| Matrix Chain Multiplication | ![Matrix Chain Multiplication](08Lecture/Images/mcm.png) |
| Floyd-Warshall | ![Floyd-Warshall](09Lecture/Images/floydWarshall.png) |

Tip: to regenerate graphs, run the plotting scripts under the corresponding `Graphs/` folders.

---

**Practical 1 - bubbleSort**
- **Aim:** Implement recursive bubble sort and measure runtime.
- **Algorithm:**
  1. If array length is 1 return.
  2. Run a single pass swapping adjacent elements where needed.
  3. Recurse on the first n-1 elements.
- **Time Complexity:** Best O(n), Average O(n^2), Worst O(n^2)
- **Space Complexity:** O(n) (recursion depth)
- **Code:**
```cpp
void bubbleSortRecursive(int arr[], int n) {
	if (n == 1) return;
	for (int i = 0; i < n - 1; i++) if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
	bubbleSortRecursive(arr, n - 1);
}

int getAverageTime(int n) {
	int total_diff = 0; int arr[10000];
	for (int i = 0; i < 100; i++) { for (int j = 0; j < n; j++) arr[j] = rand();
		auto x = std::chrono::high_resolution_clock::now();
		bubbleSortRecursive(arr, n);
		auto y = std::chrono::high_resolution_clock::now();
		total_diff += std::chrono::duration_cast<std::chrono::microseconds>(y - x).count(); }
	return total_diff / 100;
}
```
- **Use Cases:**
  - Teaching sorting stability and complexity.
  - Demonstrating behavior on small or nearly-sorted datasets.
  - Classroom exercises comparing recursive vs iterative implementations.
- **Graph:**
![Bubble Sort Time](01Lecture/Images/bbSort.png)

**Practical 2 - consecutive**
- **Aim:** Detect duplicate using index/value relation.
- **Algorithm:**
  - Iterate indices; if value XOR index != 0, report the value as candidate duplicate.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)
- **Code:**
```cpp
int findDup(const std::vector<int>& nums) {
	for (int i = 0; i < (int)nums.size(); ++i) if ((nums[i] ^ i) != 0) return nums[i];
	return -1;
}
```
- **Use Cases:**
  - Bitwise reasoning exercises.
  - Detecting index-value anomalies in constrained sequences.
  - Quick sanity checks in contest solutions.
- **Graph:** (none)

**Practical 3 - duplicateNumber**
- **Aim:** Find the first duplicate using brute force.
- **Algorithm:**
  1. For each element i, compare with all j > i.
  2. If a match found, return the duplicated value.
  3. If none found, return -1.
- **Time Complexity:** O(n^2)
- **Space Complexity:** O(1)
- **Code:**
```cpp
int findNumber(int arr[], int n) { for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) if (arr[i]==arr[j]) return arr[i]; return -1; }
void fillNumber(int arr[], int n) { for (int i = 0; i < n; ++i) arr[i] = rand()%1000; }
```
- **Use Cases:**
  - Teaching brute-force detection.
  - Small-array debugging tasks.
  - Baseline for comparing more optimal methods.
- **Graph:** (none)

**Practical 4 - Horner**
- **Aim:** Efficient polynomial evaluation using Horner's rule.
- **Algorithm:**
  1. If only one coeff remains return it.
  2. Return coeff[0] * x + horner(coeff+1, n-1, x).
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)
- **Code:**
```cpp
int horner(int coeff[], int n, int x) { if (n==1) return coeff[0]; return coeff[0]*x + horner(coeff+1,n-1,x); }
```
- **Use Cases:**
  - Fast polynomial evaluation in numerical routines.
  - Embedded systems where minimal operations matter.
  - Teaching transformation from naive to nested evaluation.
- **Graph:** (none)

**Practical 5 - linearSearch**
- **Aim:** Recursive linear search with timing harness.
- **Algorithm:**
  1. If index >= n return false.
  2. If arr[index] == target return true.
  3. Else recurse with index+1.
- **Time Complexity:** Best O(1), Average/Worst O(n)
- **Space Complexity:** O(n)
- **Code:**
```cpp
bool linearSearch(int arr[], int n, int target, int index) { if (index>=n) return false; if (arr[index]==target) return true; return linearSearch(arr,n,target,index+1); }
```
- **Use Cases:**
  - Baseline comparison with binary search.
  - Educational demonstration of recursion overhead.
  - Simple lookups in tiny arrays.
- **Graph:**
![Linear Search Time](01Lecture/Images/linearSearch.png)

**Practical 6 - power**
- **Aim:** Compute x^n using fast exponentiation and naive recursion.
- **Algorithm:**
  1. If n==0 return 1.
  2. Compute half = powerRec(x, n/2).
  3. If n even return half*half else half*half*x.
- **Time Complexity:** O(log n) (fast), O(n) (naive)
- **Space Complexity:** O(log n) or O(n)
- **Code:**
```cpp
int powerRec(int x,int n){ if(n==0) return 1; int half = powerRec(x,n/2); if(n%2==0) return half*half; return half*half*x; }
int powerRec2(int x,int n){ if(n==0) return 1; return x*powerRec2(x,n-1); }
```
- **Use Cases:**
  - Fast modular exponentiation (with mod extension).
  - Contest-level exponent problems.
  - Performance-critical repeated-power computations.
- **Graph:** (none)

**Practical 7 - selectionSort**
- **Aim:** Recursive selection sort.
- **Algorithm:**
  1. Find minimum index from i..n-1.
  2. Swap with i.
  3. Recurse for i+1.
- **Time Complexity:** O(n^2)
- **Space Complexity:** O(n)
- **Code:**
```cpp
int minIndex(int arr[],int i,int n){ int mn=i; for(int j=i;j<n;j++) if(arr[j]<arr[mn]) mn=j; return mn; }
void selectionSort(int arr[],int i,int n){ if(i==n) return; int idx=minIndex(arr,i,n); std::swap(arr[i],arr[idx]); selectionSort(arr,i+1,n); }
```
- **Use Cases:**
  - Teaching selection sort steps.
  - Very small datasets where simplicity matters.
  - Comparing sorting algorithms in class.
- **Graph:**
![Selection Sort Time](01Lecture/Images/selectionSort.png)

**Practical 8 - stringPermutation**
- **Aim:** Generate all permutations of a string.
- **Algorithm:**
  1. If index==len print.
  2. For i from index..len-1: swap(index,i), recurse, swap back.
- **Time Complexity:** O(n * n!)
- **Space Complexity:** O(n)
- **Code:**
```cpp
void permute(std::string &s,int index){ if(index==(int)s.length()){ std::cout<<s<<"\n"; return; } for(int i=index;i<(int)s.length();++i){ std::swap(s[index],s[i]); permute(s,index+1); std::swap(s[index],s[i]); } }
```
- **Use Cases:**
  - Generating exhaustive test cases.
  - Combinatorics exercises.
  - Small brute-force searches.
- **Graph:** (none)

**Practical 9 - towerOfHanio**
- **Aim:** Demonstrate Tower of Hanoi recursion.
- **Algorithm:**
  1. If n==1 return.
  2. Move n-1 from source->helper.
  3. Move nth from source->dest.
  4. Move n-1 from helper->dest.
- **Time Complexity:** O(2^n)
- **Space Complexity:** O(n)
- **Code:**
```cpp
void towerOfHanoi(int n,char src,char dst,char hlp){ if(n==1) return; towerOfHanoi(n-1,src,hlp,dst); towerOfHanoi(n-1,hlp,dst,src); }
```
- **Use Cases:**
  - Demonstrating exponential recursion.
  - Visual recursion walkthroughs.
  - Complexity growth examples.
- **Graph:**
![Tower of Hanoi Time](01Lecture/Images/TOH.png)

**Practical 10 - TruthTable**
- **Aim:** Generate all binary strings of length n.
- **Algorithm:**
  1. If length==n print.
  2. Append '0', recurse, backtrack, then '1', recurse.
- **Time Complexity:** O(2^n)
- **Space Complexity:** O(n)
- **Code:**
```cpp
void generate(std::string s,int n){ if((int)s.length()==n){ std::cout<<s<<"\n"; return;} s.push_back('0'); generate(s,n); s.pop_back(); s.push_back('1'); generate(s,n); }
```
- **Use Cases:**
  - Digital logic truth tables.
  - Exhaustive test-case generation.
  - Teaching binary counting.
- **Graph:** (none)

**Practical 11 - velocity**
- **Aim:** Count jumps until value decays below threshold.
- **Algorithm:**
  - If v<1 return count.
  - Else reduce v and recurse with incremented count.
- **Time Complexity:** O(log V)
- **Space Complexity:** O(log V)
- **Code:**
```cpp
int jumps(double v,int t){ if(v>=1){ t++; v-=0.425*v; return jumps(v,t);} return t; }
```
- **Use Cases:**
  - Modeling decaying processes.
  - Small physics simulations.
  - Recursion practice with numeric state.
- **Graph:** (none)

**Practical 12 - quickSort**
- **Aim:** Partition-based quicksort implementation.
- **Algorithm:**
  1. Choose pivot, partition elements.
  2. Recurse on left and right partitions.
- **Time Complexity:** Average O(n log n), Worst O(n^2)
- **Space Complexity:** O(log n)
- **Code:**
```cpp
void partition(std::vector<int>& arr,int low,int high){ if(low>high) return; int smaller=low,pivot=arr[low]; for(int i=low+1;i<high;i++) if(arr[i]<=pivot) smaller++; std::swap(arr[low],arr[smaller]); partition(arr,low,smaller-1); partition(arr,smaller+1,high); }
```
- **Use Cases:**
  - General-purpose in-memory sorting.
  - Library algorithm study.
  - Performance tuning experiments.
- **Graph:**
![Quick Sort Time](03Lecture/Images/quickSort.png)

**Practical 13 - merge**
- **Aim:** Merge sort implementation.
- **Algorithm:**
  1. Split array in half.
  2. Recursively sort halves.
  3. Merge sorted halves.
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n)
- **Code:**
```cpp
void merge(int arr[],int left,int mid,int right){ int n1=mid-left+1,n2=right-mid; int L[n1],R[n2]; for(int i=0;i<n1;i++) L[i]=arr[left+i]; for(int j=0;j<n2;j++) R[j]=arr[mid+1+j]; int i=0,j=0,k=left; while(i<n1 && j<n2) arr[k++]= (L[i]<=R[j])?L[i++]:R[j++]; while(i<n1) arr[k++]=L[i++]; while(j<n2) arr[k++]=R[j++]; }
void mergeSort(int arr[],int l,int r){ if(l>=r) return; int m=l+(r-l)/2; mergeSort(arr,l,m); mergeSort(arr,m+1,r); merge(arr,l,m,r); }
```
- **Use Cases:**
  - Stable sorting needs.
  - External sorting variants.
  - Teaching divide-and-conquer.
- **Graph:**
![Merge Sort Time](03Lecture/Images/mergeSort.png)

**Practical 14 - binarySearch**
- **Aim:** Recursive binary search.
- **Algorithm:**
  1. Compute mid.
  2. Return or recurse left/right accordingly.
- **Time Complexity:** O(log n)
- **Space Complexity:** O(log n)
- **Code:**
```cpp
int binarySearch(int arr[],int low,int high,int target){ if(low>high) return -1; int mid=low+(high-low)/2; if(arr[mid]==target) return mid; if(arr[mid]<target) return binarySearch(arr,mid+1,high,target); return binarySearch(arr,low,mid-1,target); }
```
- **Use Cases:**
  - Fast lookup in sorted arrays.
  - Foundation for search algorithms.
  - Competitive programming basics.
- **Graph:**
![Binary Search Time](02Lecture/Images/binarySearch.png)

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
