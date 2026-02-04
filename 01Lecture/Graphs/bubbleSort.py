import matplotlib.pyplot as plt

sizes = [100, 200, 300, 400, 500, 600, 700, 800, 900]
time_ms = [25, 42, 179, 320, 499, 685, 958, 1267, 1648]


n2 = [n * n for n in sizes]
scale_n2 = time_ms[-1] / n2[-1]
n2_scaled = [v * scale_n2 for v in n2]

n1 = sizes
scale_n1 = time_ms[0] / n1[0]
n1_scaled = [v * scale_n1 for v in n1]

plt.plot(sizes, time_ms, marker='o', label="Bubble Sort (Measured)")
plt.plot(sizes, n2_scaled, linestyle='--', label="O(n²)")
plt.plot(sizes, n1_scaled, linestyle='-.', label="O(n) Best Case")

plt.xlabel("Input Size (n)")
plt.ylabel("Average Time Taken (ms)")
plt.title("Bubble Sort Time Complexity (Practical)")
plt.legend()
plt.grid(True)

plt.show()
