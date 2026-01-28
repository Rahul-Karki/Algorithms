import matplotlib.pyplot as plt

n = [15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]
time_ms = [172, 416, 629, 1428, 2042, 4610, 7004, 17837, 35189, 69458, 112613]

plt.plot(n, time_ms, marker='o')
plt.xlabel("Number of Disks (n)")
plt.ylabel("Time Taken (ms)")
plt.title("Tower of Hanoi: Real Execution Time (Exponential Growth)")
plt.grid(True)
plt.show()
