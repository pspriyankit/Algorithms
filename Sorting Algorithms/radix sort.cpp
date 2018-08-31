#include <iostream>

using namespace std;
int maxnum(int a[],int n)
{
    int i=0;
    for(int j=1;j<n;j++)
          if(a[j]>a[i])
            i=j;
return a[i];
}
void count_sort(int a[],int n,int x)
{   int op[n];
    int count[10]={0};
    for(int i=0;i<n;i++)
    count[(a[i]/x)%10]++;
for(int i=1;i<10;i++)
{
    count[i]+=count[i-1];
}
for(int i=n-1;i>=0;i--)//to maintain the algorithm stable and main their relative ordering
{
op[count[(a[i]/x)%10]-1]=a[i];
count[(a[i]/x)%10]--;
}
for(int i=0;i<n;i++)
    a[i]=op[i];

}

void radix_sort(int a[],int n)
{
    int m=maxnum(a,n);//we find the maximum element and we rum the loop till its max digits
    for(int x=1;m/x>0;x*=10)
        count_sort(a,n,x);//takes O(n+b) where b is the space taken by extra array of base of a number
}                          // time complexity==-> d*O(n+b)
                     //since d is the max digits therefore it depends on log(base b) l(where l is the max no of array.
int main()           //time complexity==->O(log(base b) l*n)
{
   int n;
   cout<<"enter how many numbers you want to sort";

   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
    cin>>a[i];
   cout<<"array before sorting";
   for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
   cout<<endl;
   radix_sort(a,n);
   cout<<"output after sorting";
   for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}
