import math
import matplotlib.pyplot as plt

e = [100, 200, 300, 400, 500, 600, 700, 800, 900]
measured = [79, 184, 299, 422, 553, 689, 831, 978, 1131]

elog = [m * math.log2(m) for m in e]
scale = measured[-1] / elog[-1]
elog_scaled = [v * scale for v in elog]

plt.plot(e, measured, marker="o", label="Kruskal (Measured)")
plt.plot(e, elog_scaled, linestyle="--", label="O(E log E)")

plt.xlabel("Number of Edges (E)")
plt.ylabel("Time Taken (microseconds)")
plt.title("Kruskal MST Time Complexity")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../Images/kruskal.png", dpi=160)
plt.show()
