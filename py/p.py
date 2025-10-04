import matplotlib.pyplot as plt
import numpy as np


x = np.linspace(0, 10, 100)

plt.subplot(2, 1, 1)   # (rows, cols, position)
plt.plot(x, np.sin(x))
plt.title("Sine")

plt.subplot(2, 1, 2)
plt.plot(x, np.cos(x))
plt.title("Cosine")

plt.tight_layout()
plt.show()

