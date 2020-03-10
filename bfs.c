#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>
#include<sys/resource.h>
#define SIZE 30
int q[SIZE];
int f=0,r=-1;
int visited[10];
void bfs(int v,int n,int a[][n])
{
 int i;
 for(i=0;i<n;i++)
  {
    if(a[v][i] && !visited[1])
     q[++r]=i;
  }
while(f<=r)
 {
   visited[f]=1;
   printf("visited node %d\t",q[f++]);
 }
f=0;
r=-1;
if(v<(n-1))
 bfs(v+1,n,a);

}
int main(void)
{
 int n;
 struct timeval tv1,tv2;
 struct rusage r_usage;
 int i,j,h;
 printf("Enter no of rows\n");
 scanf("%d",&n);
 int a[n][n];
 printf("Enter the elements of adjancy matrix");
 for(i=0;i<n;i++)
 {
   for(j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
    }
 }
for(i=0;i<n;i++)
{
  visited[i] = 0;
}
printf("Enter index for source mode\n");
scanf("%d",&i);
printf("source node is %d \t",i);
gettimeofday(&tv1,NULL);
bfs(i,n,a);
gettimeofday(&tv2,NULL);
printf("Time of depth first search %f microseconds",(double)(tv2.tv_usec-tv1.tv_usec));
getrusage(RUSAGE_SELF,&r_usage);
printf("Memory usage %ld killobytes\n",r_usage.ru_maxrss);
return 0;
}
