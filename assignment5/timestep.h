#ifndef PARALLELCOMPUTING_TIMESTEP_H
#define PARALLELCOMPUTING_TIMESTEP_H
#define REAL_CELL 1


double timestep(int ncells, double g, double sigma, int* __restrict celltype,
                double * __restrict H, double * __restrict U, double * __restrict V,
                double * __restrict dx, double * __restrict dy);
#endif 
