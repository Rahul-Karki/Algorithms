import math
import matplotlib.pyplot as plt

x = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000]
measured = [145, 322, 515, 718, 931, 1151, 1385, 1624, 1872]

nlogn = [n * math.log2(n) for n in x]
scale_nlogn = measured[-1] / nlogn[-1]
nlogn_scaled = [v * scale_nlogn for v in nlogn]

n2 = [n * n for n in x]
scale_n2 = measured[-1] / n2[-1]
n2_scaled = [v * scale_n2 for v in n2]

plt.plot(x, measured, marker="o", label="Quick Sort (Measured)")
plt.plot(x, nlogn_scaled, linestyle="--", label="O(n log n)")
plt.plot(x, n2_scaled, linestyle="-.", label="O(n^2) Worst Case")

plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (microseconds)")
plt.title("Quick Sort Time Complexity")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../Images/quickSort.png", dpi=160)
plt.show()
