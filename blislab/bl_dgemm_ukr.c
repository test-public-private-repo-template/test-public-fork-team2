#include "bl_config.h"
#include "bl_dgemm_kernel.h"

#define a(i, j, ld) a[ (i)*(ld) + (j) ]
#define b(i, j, ld) b[ (i)*(ld) + (j) ]
#define c(i, j, ld) c[ (i)*(ld) + (j) ]

//
// C-based micorkernel
//
void bl_dgemm_ukr( int    k,
		   int    m,
                   int    n,
                   double *a,
                   double *b,
                   double *c,
                   unsigned long long ldc,
                   aux_t* data )
{
    int l, j, i;

    for ( l = 0; l < k; ++l )
    {                 
        for ( j = 0; j < n; ++j )
        { 
            for ( i = 0; i < m; ++i )
            { 
	      // ldc is used here because a[] and b[] are not packed by the
	      // starter code
	      // cse260 - you can modify the leading indice to DGEMM_NR and DGEMM_MR as appropriate
	      //
	      c( i, j, ldc ) += a( i, l, ldc) * b( l, j, ldc );   
            }
        }
    }

}


// cse260
// you can put your optimized kernels here
// - put the function prototypes in bl_dgemm_kernel.h
// - define BL_MICRO_KERNEL appropriately in bl_config.h
//
