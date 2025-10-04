import numpy as np

A = np.array([[1,2],[3,4]])
B = np.array([[5,6],[7,8]])

print(np.matmul(A,B))     # matrix multiplication
print(np.linalg.inv(A))   # inverse
print(np.linalg.det(A))   # determinant
print(np.linalg.eig(A))   # eigenvalues/vectors
