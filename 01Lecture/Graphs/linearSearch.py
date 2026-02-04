import matplotlib.pyplot as plt

n = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000]
time_ms = [4, 13, 15, 20, 25, 30, 35, 40, 45, 50]

on = n
scale_on = time_ms[-1] / on[-1]
on_scaled = [v * scale_on for v in on]

plt.plot(n, time_ms, marker='o', label="Linear Search (Measured)")
plt.plot(n, on_scaled, linestyle='--', label="O(n)")

plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (ms)")
plt.title("Linear Search Time Complexity")
plt.legend()
plt.grid(True)
plt.show()
