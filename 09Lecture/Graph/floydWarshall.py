import matplotlib.pyplot as plt

v = [10, 20, 30, 40, 50, 60, 70, 80, 90]
measured = [8, 51, 170, 401, 782, 1349, 2138, 3185, 4526]

v3 = [n * n * n for n in v]
scale = measured[-1] / v3[-1]
v3_scaled = [x * scale for x in v3]

plt.plot(v, measured, marker="o", label="Floyd-Warshall (Measured)")
plt.plot(v, v3_scaled, linestyle="--", label="O(V^3)")

plt.xlabel("Number of Vertices (V)")
plt.ylabel("Time Taken (microseconds)")
plt.title("Floyd-Warshall Time Complexity")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../Images/floydWarshall.png", dpi=160)
plt.show()
