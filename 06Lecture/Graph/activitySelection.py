import math
import matplotlib.pyplot as plt

x = [100, 200, 300, 400, 500, 600, 700, 800, 900]
measured = [52, 121, 196, 278, 366, 459, 557, 660, 768]

nlogn = [n * math.log2(n) for n in x]
scale = measured[-1] / nlogn[-1]
nlogn_scaled = [v * scale for v in nlogn]

plt.plot(x, measured, marker="o", label="Activity Selection (Measured)")
plt.plot(x, nlogn_scaled, linestyle="--", label="O(n log n)")

plt.xlabel("Number of Activities (n)")
plt.ylabel("Time Taken (microseconds)")
plt.title("Activity Selection Time Complexity")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../Images/activitySelection.png", dpi=160)
plt.show()
