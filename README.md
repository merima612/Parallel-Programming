# ParallelComputing
1. CPU Performance (OpenMP)
[image1](img1.png)

Local machine results:

Copy: 11,585 MB/s

Mul: 11,624 MB/s

Add: 12,896 MB/s

Triad: 12,918 MB/s

Dot: 17,820 MB/s

The CPU achieved ~12.9 GB/s sustained memory bandwidth. Dot operation was fastest due to cache optimization.

2. OpenCL Attempt (Integrated GPU)
[image2](img2.png)

OpenCL compiled successfully but failed at runtime with clGetPlatformIDs error. This indicates no OpenCL-capable devices were found on the local machine, which is common in lab environments without GPU drivers.

3. GPU Specifications
[image3](img3.png)

Lab Server GPU: NVIDIA GeForce RTX 2060 SUPER

Driver: 580.95.05

CUDA Version: 13.0

Memory: 8GB GDDR6

4. CUDA Performance (Dedicated GPU)
[image4](img4.png)

Server GPU results:

Copy: 396,040 MB/s (~396 GB/s)

Mul: 394,287 MB/s (~394 GB/s)

Add: 403,987 MB/s (~404 GB/s)

Triad: 404,030 MB/s (~404 GB/s)

Dot: 419,523 MB/s (~420 GB/s)

Configuration: 136 work groups × 1024 threads = 139,264 parallel threads