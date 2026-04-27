import math
import matplotlib.pyplot as plt

x = [100, 200, 300, 400, 500, 600, 700, 800, 900]
measured = [72, 168, 274, 388, 509, 636, 771, 911, 1060]

nlogn = [n * math.log2(n) for n in x]
scale = measured[-1] / nlogn[-1]
nlogn_scaled = [v * scale for v in nlogn]

plt.plot(x, measured, marker="o", label="Convex Hull (Measured)")
plt.plot(x, nlogn_scaled, linestyle="--", label="O(n log n)")

plt.xlabel("Number of Points (n)")
plt.ylabel("Time Taken (microseconds)")
plt.title("Convex Hull (Graham Scan) Time Complexity")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../Images/convexHull.png", dpi=160)
plt.show()
