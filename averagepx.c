#include <stdio.h>
#include "/usr/local/opt/libomp/include/omp.h"
#include <stdlib.h>


int main() {
    int n, i;
    unsigned int sum = 0,*suml;
    unsigned *input;
    int threads_num = omp_get_max_threads();
    omp_set_num_threads(threads_num);
    scanf("%d", &n);
    input = (unsigned *) malloc(n * sizeof(unsigned));
    suml = (unsigned int *) malloc(threads_num * sizeof(unsigned int));
    for (i = 0; i < n; i++) {
        scanf("%u", &input[i]);
    }
    #pragma omp parallel for reduction(+:sum) 
    for (i = 0; i < n; i++) {
         sum += input[i];
    }
    
    printf("%u", sum/n); 
    free(input);
    free(suml);
    return 0;
}
