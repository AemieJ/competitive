// Need explanation for this ques didn't understand!
#include <stdio.h>
bool findPartiion (int arr[], int n)
{
    int sum = 0;
    int i, j;
   
    for (i = 0; i < n; i++)
      sum += arr[i];
     
    if (sum%2 != 0)  
       return false;
   
    bool part[sum/2+1][n+1];
     
    for (i = 0; i <= n; i++)
      part[0][i] = true;
       
    for (i = 1; i <= sum/2; i++)
      part[i][0] = false;     
      
     for (i = 1; i <= sum/2; i++)  
     {
       for (j = 1; j <= n; j++)  
       {
         part[i][j] = part[i][j-1];
         if (i >= arr[j-1])
           part[i][j] = part[i][j] || part[i - arr[j-1]][j-1];
       }        
     }    
      
      
     return part[sum/2][n];
}     
 
int main()
{
 int arr[100],n,T,i;
  
 scanf("%d",&T);
 
 while(T--)
 {
   scanf("%d",&n);
   for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
 
  if (findPartiion(arr, n) == true)
     printf("YES\n");
  else
     printf("NO\n");
 } 
  getchar();
  return 0;
}