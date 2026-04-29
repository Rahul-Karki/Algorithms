import matplotlib.pyplot as plt
import math

# N-Queens Time Complexity - measured timing data
n = [4, 5, 6, 7, 8, 9, 10, 11]
measured = [0.01, 0.05, 0.15, 0.42, 2.1, 8.5, 35.2, 142.8]  # milliseconds

# Calculate factorial curve for comparison
factorial = [math.factorial(x) for x in n]
scale_factorial = measured[-1] / factorial[-1]
factorial_scaled = [v * scale_factorial for v in factorial]

plt.figure(figsize=(10, 6))
plt.plot(n, measured, marker='o', label="N-Queens (Measured)", linewidth=2, markersize=8)
plt.plot(n, factorial_scaled, linestyle='--', label="O(N!) Reference", linewidth=2)

plt.xlabel("N (Board Size)", fontsize=12)
plt.ylabel("Time Taken (milliseconds)", fontsize=12)
plt.title("N-Queens Problem - Time Complexity", fontsize=14)
plt.legend(fontsize=11)
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.savefig("../Images/NQueens.png", dpi=160)
plt.close()
print("Generated: NQueens.png")

