import matplotlib.pyplot as plt

x = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000]
measured = [624, 2491, 5605, 9759, 15375, 21937, 29763, 39100, 49880]

n2 = [n*n for n in x]
scale_n2 = measured[-1] / n2[-1]
n2_scaled = [v * scale_n2 for v in n2]

n1 = x
scale_n1 = measured[0] / n1[0]
n1_scaled = [v * scale_n1 for v in n1]

plt.plot(x, measured, marker='o', label="Insertion Sort (Measured)")
plt.plot(x, n2_scaled, linestyle='--', label="O(n²)")
plt.plot(x, n1_scaled, linestyle='-.', label="O(n) Best Case")

plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (ms)")
plt.title("Insertion Sort Time Complexity")
plt.legend()
plt.grid(True)
plt.show()
