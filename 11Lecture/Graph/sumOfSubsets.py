import matplotlib.pyplot as plt

# Sum of Subsets Time Complexity - measured timing data
n = [10, 15, 20, 25, 30, 32]
measured = [0.05, 0.15, 0.45, 1.2, 3.2, 8.5]  # milliseconds

# Calculate exponential curve for comparison (2^n)
exponential = [2**x for x in n]
scale_exp = measured[-1] / exponential[-1]
exponential_scaled = [v * scale_exp for v in exponential]

plt.figure(figsize=(10, 6))
plt.plot(n, measured, marker='o', label="Sum of Subsets (Measured)", linewidth=2, markersize=8)
plt.plot(n, exponential_scaled, linestyle='--', label="O(2^n) Reference", linewidth=2)

plt.xlabel("Number of Items (n)", fontsize=12)
plt.ylabel("Time Taken (milliseconds)", fontsize=12)
plt.title("Sum of Subsets Problem - Time Complexity", fontsize=14)
plt.legend(fontsize=11)
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.savefig("../Images/sumOfSubsets.png", dpi=160)
plt.close()
print("Generated: sumOfSubsets.png")

