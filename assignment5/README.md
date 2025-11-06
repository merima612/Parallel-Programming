OPT1
student@itcenter-lab128:~/Desktop/assignment5$ make opt1
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -fopt-info-vec-optimized -fopt-info-vec-missed -mprefer-vector-width=128 -fopt-info-vec-optimized=vec_report_opt1.txt -c main.c -o main.o
cc1: warning: ignoring possibly conflicting option ‘-fopt-info-vec-optimized=vec_report_opt1.txt’
main.c:10:22: optimized: loop vectorized using 16 byte vectors
main.c:20:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
/usr/include/x86_64-linux-gnu/bits/stdio2.h:112:10: missed: statement clobbers memory: __printf_chk (1, "Minimum dt is %lf\n", mymindt_6);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -fopt-info-vec-optimized -fopt-info-vec-missed -mprefer-vector-width=128 -fopt-info-vec-optimized=vec_report_opt1.txt -c timestep_opt1.c -o timestep_opt1.o
cc1: warning: ignoring possibly conflicting option ‘-fopt-info-vec-optimized=vec_report_opt1.txt’
timestep_opt1.c:10:22: missed: couldn't vectorize loop
timestep_opt1.c:10:22: missed: not vectorized: control flow in loop.
timestep_opt1.c:12:25: missed: statement clobbers memory: wavespeed_46 = sqrt (_9);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -fopt-info-vec-optimized -fopt-info-vec-missed -mprefer-vector-width=128 -fopt-info-vec-optimized=vec_report_opt1.txt -c timer.c -o timer.o
cc1: warning: ignoring possibly conflicting option ‘-fopt-info-vec-optimized=vec_report_opt1.txt’
timer.c:10:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:15:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -fopt-info-vec-optimized -fopt-info-vec-missed -mprefer-vector-width=128 -fopt-info-vec-optimized=vec_report_opt1.txt -o stream_triad_opt1 main.o timestep_opt1.o timer.o -lm

OPT2
student@itcenter-lab128:~/Desktop/assignment5$ make opt2
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -fopt-info-vec-optimized -fopt-info-vec-missed -mprefer-vector-width=256 -fopt-info-vec-optimized=vec_report_opt2.txt -c timestep_opt2.c -o timestep_opt2.o
cc1: warning: ignoring possibly conflicting option ‘-fopt-info-vec-optimized=vec_report_opt2.txt’
timestep_opt2.c:9:25: missed: couldn't vectorize loop
timestep_opt2.c:9:25: missed: not vectorized: control flow in loop.
timestep_opt2.c:17:32: missed: statement clobbers memory: wavespeed_46 = sqrt (_12);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -fopt-info-vec-optimized -fopt-info-vec-missed -mprefer-vector-width=256 -fopt-info-vec-optimized=vec_report_opt2.txt -o stream_triad_opt2 main.o timestep_opt2.o timer.o -lm

OPT3
student@itcenter-lab128:~/Desktop/assignment5$ make opt3
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -fopt-info-vec-optimized -fopt-info-vec-missed -mprefer-vector-width=256 -fopt-info-vec-optimized=vec_report_opt3.txt -fno-trapping-math -fno-math-errno -c timestep_opt3.c -o timestep_opt3.o
cc1: warning: ignoring possibly conflicting option ‘-fopt-info-vec-optimized=vec_report_opt3.txt’
timestep_opt3.c:11:9: optimized: loop vectorized using 32 byte vectors
timestep_opt3.c:13:9: optimized: loop vectorized using 16 byte vectors
timestep_opt3.c:11:9: optimized: loop vectorized using 32 byte vectors
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -fopt-info-vec-optimized -fopt-info-vec-missed -mprefer-vector-width=256 -fopt-info-vec-optimized=vec_report_opt3.txt -fno-trapping-math -fno-math-errno -o stream_triad_opt3 main.o timestep_opt3.o timer.o -lm
student@itcenter-lab128:~/Desktop/assignment5$ 

likwid
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:       Intel Core SandyBridge processor
CPU clock:      3.29 GHz
ERROR - [./src/perfgroup.c:perfgroup_readGroup:858] No such file or directory.
Cannot read group file MEM_DP.txt. Searched in /usr/share/likwid/perfgroups/sandybridge/MEM_DP.txt and /root/.likwid/groups/sandybridge/MEM_DP.txt
ERROR - [./src/perfmon.c:perfmon_addEventSet:2152] No such file or directory.
Access to performance group MEM_DP not allowed
