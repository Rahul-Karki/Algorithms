import matplotlib.pyplot as plt

x = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000]
measured = [19, 37, 56, 73, 91, 109, 127, 145, 163]

linear = x
scale = measured[-1] / linear[-1]
linear_scaled = [v * scale for v in linear]

plt.plot(x, measured, marker="o", label="Max-Min D&C (Measured)")
plt.plot(x, linear_scaled, linestyle="--", label="O(n)")

plt.xlabel("Array Size (n)")
plt.ylabel("Time Taken (microseconds)")
plt.title("Max-Min Divide and Conquer Time Complexity")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../Images/maxmin.png", dpi=160)
plt.show()
