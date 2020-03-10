#include<stdio.h>
#include<sys/time.h>
#include<time.h>
#include<sys/resource.h>
int a[20][20],reach[20],n;
void dfs(int v)
{
 int i;
 reach[v]=1;
for(i=1;i<=n;i++)
{
 if(a[v][i] && !reach[i])
  {
    printf("\n %d -> %d ",v,i);
    dfs(i);
  }
}
}
void main()
{
 int i;
 int j,v,count = 0;
 struct timeval tv1,tv2;
 struct rusage r_usage;
 printf("Enter the vertices:"); 
 scanf("%d",&n);
 printf("Enter the adjacent matrix");
 for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++) 
    {
      scanf("%d",&a[i][j]);
    }
  }
printf("Enter the source vertex\n");
scanf("%d",&v);
for(i=1;i<=n;i++)
 {
  if(reach[i])
  count++;
 }
gettimeofday(&tv1,NULL);
dfs(v);
gettimeofday(&tv2,NULL);
printf("Time of depth first search %f microseconds",(double)(tv2.tv_usec-tv1.tv_usec));
getrusage(RUSAGE_SELF,&r_usage);
printf("Memory usage %ld killobytes\n",r_usage.ru_maxrss);
}
