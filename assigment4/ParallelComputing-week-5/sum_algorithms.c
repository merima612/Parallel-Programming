//
// Created by Adnan Hajro on 29. 10. 2025..
//

#include <stdlib.h>
#include <math.h>
#include "sum_algorithms.h"

double do_sum(double* restrict var, long ncells)
{
   double sum = 0.0;
   for (long i = 0; i < ncells; i++){
      sum += var[i];
   }
   return sum;
}
double do_pair_sum(double* restrict var, long ncells)
{
   double *pwsum = (double *)malloc(ncells/2 * sizeof(double));
   if (!pwsum) return 0.0;

   long nmax = ncells/2;
   for (long i = 0; i < nmax; i++) {
      pwsum[i] = var[i*2] + var[i*2+1];
   }

   for (long j = 1; j < log2(ncells); j++) {
      nmax /= 2;
      for (long i = 0; i < nmax; i++) {
         pwsum[i] = pwsum[i*2] + pwsum[i*2+1];
      }
   }

   double sum = pwsum[0];
   free(pwsum);
   return sum;
}
double do_kahan_sum(double* restrict var, long ncells)
{
   double sum = 0.0;
   double c = 0.0; 
   for (long i = 0; i < ncells; i++) {
      double y = var[i] - c;
      double t = sum + y;
      c = (t - sum) - y;
      sum = t;
   }
   return sum;
}
double do_knuth_sum(double* restrict var, long ncells)
{
   double sum = 0.0;
   double err = 0.0;
   for (long i = 0; i < ncells; i++) {
      double temp = sum + var[i];
      if (fabs(sum) >= fabs(var[i]))
         err += (sum - temp) + var[i];
      else
         err += (var[i] - temp) + sum;
      sum = temp;
   }
   return sum + err;
}
long double do_longdouble_sum(double* restrict var, long ncells)
{
   long double sum = 0.0;
   for (long i = 0; i < ncells; i++) {
      sum += (long double)var[i];
   }
   return sum;
}
