import matplotlib.pyplot as plt

n = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000]
time_ms = [915, 3687, 6912, 9327, 13501, 19577, 25952, 34065, 42901, 53173]

n2 = [v * v for v in n]
scale_n2 = time_ms[-1] / n2[-1]
n2_scaled = [v * scale_n2 for v in n2]

n1 = n
scale_n1 = time_ms[0] / n1[0]
n1_scaled = [v * scale_n1 for v in n1]

plt.plot(n, time_ms, marker='o', label="Selection Sort (Measured)")
plt.plot(n, n2_scaled, linestyle='--', label="Worst Case O(n²)")
plt.plot(n, n1_scaled, linestyle='-.', label="Best Case O(n)")

plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (ms)")
plt.title("Selection Sort Time Complexity")
plt.legend()
plt.grid(True)
plt.show()
