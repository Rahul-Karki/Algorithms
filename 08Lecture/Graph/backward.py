import matplotlib.pyplot as plt

n = [20, 40, 60, 80, 100, 120, 140, 160, 180]
measured = [31, 122, 271, 479, 745, 1068, 1450, 1889, 2383]

n2 = [x * x for x in n]
scale = measured[-1] / n2[-1]
n2_scaled = [v * scale for v in n2]

plt.plot(n, measured, marker="o", label="Backward Approach (Measured)")
plt.plot(n, n2_scaled, linestyle="--", label="O(n^2)")

plt.xlabel("Number of Nodes (n)")
plt.ylabel("Time Taken (microseconds)")
plt.title("Multi-Stage Graph Backward Approach")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../Images/backward.png", dpi=160)
plt.show()
