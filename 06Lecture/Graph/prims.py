import matplotlib.pyplot as plt

v = [20, 40, 60, 80, 100, 120, 140, 160, 180]
measured = [41, 156, 346, 610, 947, 1360, 1848, 2413, 3052]

v2 = [n * n for n in v]
scale = measured[-1] / v2[-1]
v2_scaled = [x * scale for x in v2]

plt.plot(v, measured, marker="o", label="Prim's (Measured)")
plt.plot(v, v2_scaled, linestyle="--", label="O(V^2)")

plt.xlabel("Number of Vertices (V)")
plt.ylabel("Time Taken (microseconds)")
plt.title("Prim's MST Time Complexity")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../Images/prims.png", dpi=160)
plt.show()
