import matplotlib.pyplot as plt

n = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000]
time_ms = [915, 3687, 6912, 9327, 13501, 19577, 25952, 34065, 42901, 53173]

plt.plot(n, time_ms, marker='o')
plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (ms)")
plt.title("Selection Sort: Real Execution Time (Large Input Sizes)")
plt.grid(True)
plt.show()
