import matplotlib.pyplot as plt

v = [20, 40, 60, 80, 100, 120, 140, 160, 180]
measured = [33, 129, 286, 506, 786, 1133, 1544, 2016, 2550]

v2 = [n * n for n in v]
scale = measured[-1] / v2[-1]
v2_scaled = [x * scale for x in v2]

plt.plot(v, measured, marker="o", label="Multi-Stage Graph (Measured)")
plt.plot(v, v2_scaled, linestyle="--", label="O(V^2)")

plt.xlabel("Number of Vertices (V)")
plt.ylabel("Time Taken (microseconds)")
plt.title("Multi-Stage Graph Min-Cost Path Complexity")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../Images/multiStage.png", dpi=160)
plt.show()
