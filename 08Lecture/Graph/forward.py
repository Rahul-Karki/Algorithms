import matplotlib.pyplot as plt

n = [20, 40, 60, 80, 100, 120, 140, 160, 180]
measured = [30, 118, 263, 466, 727, 1044, 1419, 1848, 2333]

n2 = [x * x for x in n]
scale = measured[-1] / n2[-1]
n2_scaled = [v * scale for v in n2]

plt.plot(n, measured, marker="o", label="Forward Approach (Measured)")
plt.plot(n, n2_scaled, linestyle="--", label="O(n^2)")

plt.xlabel("Number of Nodes (n)")
plt.ylabel("Time Taken (microseconds)")
plt.title("Multi-Stage Graph Forward Approach")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../Images/forward.png", dpi=160)
plt.show()
