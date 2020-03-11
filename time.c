#include<stdio.h>
#include<sys/time.h>
#include<time.h>
#include<sys/resource.h>


struct timeval  tv1, tv2;

 struct rusage r_usage;

gettimeofday(&tv1, NULL);

gettimeofday(&tv2, NULL);


 printf("Time of selection sort = %f microseconds",(double)(tv2.tv_usec-tv1.tv_usec));
//  printf ("Total time = %f seconds\n", (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +  (double) (tv2.tv_sec - tv1.tv_sec));
 getrusage(RUSAGE_SELF,&r_usage);
 printf("Memory usage: %ld kilobytes\n",r_usage.ru_maxrss);
