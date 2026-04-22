import math
import matplotlib.pyplot as plt

x = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000]
measured = [180, 395, 630, 878, 1139, 1410, 1698, 1992, 2298]

nlogn = [n * math.log2(n) for n in x]
scale_nlogn = measured[-1] / nlogn[-1]
nlogn_scaled = [v * scale_nlogn for v in nlogn]

plt.plot(x, measured, marker="o", label="Merge Sort (Measured)")
plt.plot(x, nlogn_scaled, linestyle="--", label="O(n log n)")

plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (microseconds)")
plt.title("Merge Sort Time Complexity")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../Images/mergeSort.png", dpi=160)
plt.show()
