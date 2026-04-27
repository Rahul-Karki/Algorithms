import math
import matplotlib.pyplot as plt

v = [20, 40, 60, 80, 100, 120, 140, 160, 180]
measured = [86, 208, 349, 501, 662, 833, 1009, 1192, 1381]

e = [2 * n for n in v]
complexity = [(vv + ee) * math.log2(vv) for vv, ee in zip(v, e)]
scale = measured[-1] / complexity[-1]
curve = [c * scale for c in complexity]

plt.plot(v, measured, marker="o", label="Dijkstra (Measured)")
plt.plot(v, curve, linestyle="--", label="O((V+E) log V)")

plt.xlabel("Number of Vertices (V)")
plt.ylabel("Time Taken (microseconds)")
plt.title("Dijkstra Time Complexity")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../Images/dijkstra.png", dpi=160)
plt.show()
