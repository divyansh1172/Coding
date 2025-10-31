import numpy as np
import ctypes
from PIL import Image

# Setting the pointere to send to c file for compression

img=np.ctypeslib.ndpointer(dtype=np.uint8, flags='C_CONTIGUOUS')

# setting the path to .so file
svd_lib=ctypes.CDLL('./ee.so')

#Defining the input to the c code
svd_reconstruct_c=svd_lib.svd_reconstruct
# in c the function looks like void svd_reconstruct(const unsigned char *input, unsigned char *output, int m, int n, int k)
svd_reconstruct_c.argtypes=[img, img , ctypes.c_int, ctypes.c_int, ctypes.c_int]
svd_reconstruct_c.restype= None #because the function is void 

#loading and preparing an image 
try:
    input_image=Image.open("globe.jpg").convert('L')
except FileNotFoundError:
    print("File not found i guess there is some error")
    #sys.exit(1)

input_ar=np.array(input_image)
m , n=input_ar.shape

#calling the c function for different values of k

#defining diff ks
#k_vals=[1,5,10,25,50, 100]

k_vals=[500]
max_rank = min(m,n)
k_vals_to_run=[k for k in k_vals if k<=max_rank]
if max_rank< k_vals[-1]:
    k_vals_to_run.append(max_rank)

for k in k_vals:
    output_ar=np.empty_like(input_ar)
    #calling the c code
    svd_reconstruct_c(input_ar, output_ar, m,n,k)

    output_image=Image.fromarray(output_ar, mode='L')
    output_filename=f"reconstruct_k{k}.jpg"
    output_image.save(output_filename)