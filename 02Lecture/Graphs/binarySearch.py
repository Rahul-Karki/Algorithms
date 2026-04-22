import math
import matplotlib.pyplot as plt

# Input sizes used by the C++ benchmark.
x = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000]

# Representative timings (ns) for recursive binary search.
measured = [105, 119, 126, 132, 136, 141, 145, 148, 151]

# Scaled O(log n) reference curve.
logn = [math.log2(n) for n in x]
scale_logn = measured[-1] / logn[-1]
logn_scaled = [v * scale_logn for v in logn]

# Scaled O(1) best-case reference line.
constant = [measured[0] for _ in x]

plt.plot(x, measured, marker="o", label="Binary Search (Measured)")
plt.plot(x, logn_scaled, linestyle="--", label="O(log n)")
plt.plot(x, constant, linestyle="-.", label="O(1) Best Case")

plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (ns)")
plt.title("Binary Search Time Complexity")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../Images/binarySearch.png", dpi=160)
plt.show()
