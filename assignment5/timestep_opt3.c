
#include <math.h>
#include "timestep.h"
#define REAL_CELL 1

double timestep(int ncells, double g, double sigma, int* __restrict celltype,
                double* __restrict H, double* __restrict U, double* __restrict V,
                double* __restrict dx, double* __restrict dy){
    double mymindt = 1.0e20;

#pragma omp simd reduction(min:mymindt)
    for (int ic = 0; ic < ncells; ++ic) {
        if (celltype[ic] == REAL_CELL) {
            double Hi = H[ic];
            double Ui = U[ic];
            double Vi = V[ic];
            double dxi = dx[ic];
            double dyi = dy[ic];

            double wavespeed = sqrt(g * Hi);
            double xspeed = (fabs(Ui) + wavespeed) / dxi;
            double yspeed = (fabs(Vi) + wavespeed) / dyi;
            double dt = sigma / (xspeed + yspeed);

            if (dt < mymindt) mymindt = dt;
        }
    }
    return mymindt;
}
