# Parallel-Programming

student@itcenter-lab128:~/Desktop/newfolder$ make valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./memory_demo
==9103== Memcheck, a memory error detector
==9103== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9103== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==9103== Command: ./memory_demo
==9103== 
==9103== Invalid write of size 4
==9103==    at 0x1091C6: main (main.c:7)
==9103==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==9103==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==9103==    by 0x109185: main (main.c:5)
==9103== 
==9103== Conditional jump or move depends on uninitialised value(s)
==9103==    at 0x1091F4: main (main.c:9)
==9103==  Uninitialised value was created by a stack allocation
==9103==    at 0x109169: main (main.c:3)
==9103== 
==9103== Invalid read of size 4
==9103==    at 0x1091EF: main (main.c:9)
==9103==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==9103==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==9103==    by 0x109185: main (main.c:5)
==9103== 
==9103== 
==9103== HEAP SUMMARY:
==9103==     in use at exit: 40 bytes in 1 blocks
==9103==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==9103== 
==9103== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==9103==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==9103==    by 0x109185: main (main.c:5)
==9103== 
==9103== LEAK SUMMARY:
==9103==    definitely lost: 40 bytes in 1 blocks
==9103==    indirectly lost: 0 bytes in 0 blocks
==9103==      possibly lost: 0 bytes in 0 blocks
==9103==    still reachable: 0 bytes in 0 blocks
==9103==         suppressed: 0 bytes in 0 blocks
==9103== 
==9103== For lists of detected and suppressed errors, rerun with: -s
==9103== ERROR SUMMARY: 14 errors from 4 contexts (suppressed: 0 from 0)

#include <stdlib.h>

int main(int argc, char *argv[]){
   int ipos=0, ival=-1;
   int *iarray = (int *) malloc(10*sizeof(int));
   if (argc == 2) ival = atoi(argv[1]);
   for (int i = 0; i<10; i++){ iarray[i] = ipos; }
   for (int i = 0; i<10; i++){
     if (ival == iarray[i]) ipos = i;
  }
  free(iarray);
  return 0;
 }
 
1. I initialized ipos and ival because the compiler recognized uninitialized variables.
2. with for (int i = 0; i<10; i++) we limited the array reordering, instead of 11, we have 10 prints
3. free(array) prevents memory leaks



student@itcenter-lab128:~/Desktop/newfolder$ make valgrind
gcc -Wall -Wextra -g -std=c99 -o memory_demo main.c
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./memory_demo
==9797== Memcheck, a memory error detector
==9797== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9797== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==9797== Command: ./memory_demo
==9797== 
==9797== 
==9797== HEAP SUMMARY:
==9797==     in use at exit: 0 bytes in 0 blocks
==9797==   total heap usage: 1 allocs, 1 frees, 40 bytes allocated
==9797== 
==9797== All heap blocks were freed -- no leaks are possible
==9797== 
==9797== For lists of detected and suppressed errors, rerun with: -s
==9797== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
student@itcenter-lab128:~/Desktop/newfolder$ 
