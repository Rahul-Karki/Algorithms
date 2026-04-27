import matplotlib.pyplot as plt

n = [10, 15, 20, 25, 30, 35, 40, 45, 50]
measured = [12, 40, 93, 181, 312, 494, 734, 1040, 1419]

n3 = [x * x * x for x in n]
scale = measured[-1] / n3[-1]
n3_scaled = [v * scale for v in n3]

plt.plot(n, measured, marker="o", label="MCM DP (Measured)")
plt.plot(n, n3_scaled, linestyle="--", label="O(n^3)")

plt.xlabel("Number of Matrices (n)")
plt.ylabel("Time Taken (microseconds)")
plt.title("Matrix Chain Multiplication Time Complexity")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../Images/mcm.png", dpi=160)
plt.show()
