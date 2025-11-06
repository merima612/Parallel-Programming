CC = gcc
TIMER_OBJ = timer.o
CFLAGS_BASE = -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -fopt-info-vec-optimized -fopt-info-vec-missed

all: opt1 opt2 opt3

opt1: CFLAGS = $(CFLAGS_BASE) -mprefer-vector-width=128 -fopt-info-vec-optimized=vec_report_opt1.txt
opt1: stream_triad_opt1

opt2: CFLAGS = $(CFLAGS_BASE) -mprefer-vector-width=256 -fopt-info-vec-optimized=vec_report_opt2.txt
opt2: stream_triad_opt2

opt3: CFLAGS = $(CFLAGS_BASE) -mprefer-vector-width=256 -fopt-info-vec-optimized=vec_report_opt3.txt -fno-trapping-math -fno-math-errno
opt3: stream_triad_opt3

stream_triad_opt1: main.o timestep_opt1.o $(TIMER_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm

stream_triad_opt2: main.o timestep_opt2.o $(TIMER_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm

stream_triad_opt3: main.o timestep_opt3.o $(TIMER_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm

main.o: main.c timestep.h
	$(CC) $(CFLAGS) -c main.c -o main.o

timestep_opt1.o: timestep_opt1.c timestep.h
	$(CC) $(CFLAGS) -c timestep_opt1.c -o timestep_opt1.o

timestep_opt2.o: timestep_opt2.c timestep.h
	$(CC) $(CFLAGS) -c timestep_opt2.c -o timestep_opt2.o

timestep_opt3.o: timestep_opt3.c timestep.h
	$(CC) $(CFLAGS) -c timestep_opt3.c -o timestep_opt3.o

timer.o: timer.c timer.h
	$(CC) $(CFLAGS) -c timer.c -o timer.o

clean:
	rm -f *.o stream_triad_opt1 stream_triad_opt2 stream_triad_opt3 vec_report_opt*.txt likwid_opt*.txt
