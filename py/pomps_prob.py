import math
import matplotlib.pyplot as plt

def nested_sqrt_sequence(x, steps=50):
    values = []
    val = 0
    for _ in range(steps):
        val = math.sqrt(x + val)
        values.append(val)
    return values

x = 2
values = nested_sqrt_sequence(x, steps=50)

plt.plot(values, marker='o')
plt.axhline(2, linestyle='--', label='Limit = 2')
plt.title("Convergence of Nested Square Root (x = 2)")
plt.xlabel("Iteration")
plt.ylabel("Value")
plt.legend()
plt.grid()

plt.show()
