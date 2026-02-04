import matplotlib.pyplot as plt

n = [15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]
time_ms = [172, 416, 629, 1428, 2042, 4610, 7004, 17837, 35189, 69458, 112613]

exp = [2 ** v for v in n]
scale_exp = time_ms[-1] / exp[-1]
exp_scaled = [v * scale_exp for v in exp]

plt.plot(n, time_ms, marker='o', label="Tower of Hanoi (Measured)")
plt.plot(n, exp_scaled, linestyle='--', label="Worst Case O(2ⁿ)")

plt.xlabel("Number of Disks (n)")
plt.ylabel("Time Taken (ms)")
plt.title("Tower of Hanoi Time Complexity")
plt.legend()
plt.grid(True)
plt.show()
