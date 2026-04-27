import math
import matplotlib.pyplot as plt

x = [100, 200, 300, 400, 500, 600, 700, 800, 900]
measured = [64, 145, 235, 331, 434, 542, 656, 775, 900]

nlogn = [n * math.log2(n) for n in x]
scale = measured[-1] / nlogn[-1]
nlogn_scaled = [v * scale for v in nlogn]

plt.plot(x, measured, marker="o", label="Fractional Knapsack (Measured)")
plt.plot(x, nlogn_scaled, linestyle="--", label="O(n log n)")

plt.xlabel("Number of Items (n)")
plt.ylabel("Time Taken (microseconds)")
plt.title("Fractional Knapsack Time Complexity")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../Images/knapsack.png", dpi=160)
plt.show()
