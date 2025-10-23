https://docs.google.com/spreadsheets/d/1E1LtkFCVHIl2pDSVgJeZLxFvapOWIVzO98Y-UODzgMc/edit?usp=sharing


U KODU JE POPRAVLJENO SLJEDECE: 
1.Memory allocation added - a new memory block is created - SoA_type* AoSoA = new SoA_type[num_blocks];
2. the loop was completed to fill the data: AoSoA[j].R[i] = rand();
                                                AoSoA[j].G[i] = rand();
                                                AoSoA[j].B[i] = rand();
3. iat the and memory deallocation is added to prevent memory-leak - delete[] AoSoA;

U MAKEFILE-u: 
TARGET_SRC = aosoa_measurement.cpp- - added following line

and in terminal this commad were executed: make test_1M..., and that made results_N1000.csv and others, and these values were added to google sheet.

![graph_image](/resources/Screenshot%20from%202025-10-23%2015-56-29.png)

