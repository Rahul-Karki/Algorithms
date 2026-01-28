import matplotlib.pyplot as plt

sizes = [100, 200, 300, 400, 500, 600, 700, 800, 900]
time_ms = [25, 42, 179, 320, 499, 685, 958, 1267, 1648]

plt.plot(sizes, time_ms, marker='o')


plt.xlabel("Input Size (n)")
plt.ylabel("Average Time Taken (ms)")
plt.title("Bubble Sort Time Complexity (Practical)")

plt.grid(True)

plt.show()
