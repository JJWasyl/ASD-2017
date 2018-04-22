#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int maximum = 160000;

int cmpfunc(const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

int main(){

   clock_t start, end;

   FILE* f = fopen("input.txt", "r");
   FILE* o = fopen("output.txt", "w");
   int x;
   int tab[maximum];
   int i = 0;
  
   fscanf(f, "%d", &x);
   while(!feof(f)){
      tab[i] = x; 
      i++;
      fscanf(f, "%d", &x);
   }
   start = clock();
   qsort(tab, i, sizeof(int), cmpfunc);
   end = clock();
   for(int j = 0; j < i; j++){
      fprintf(o, "%d \n", tab[j]);
   }

   double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
   printf("Elapsed Time = %d\n", time_taken);

fclose(f);
fclose(o);

return 0;
}
