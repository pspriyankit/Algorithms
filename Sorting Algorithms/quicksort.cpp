#include <iostream>
using namespace std;
int partition(int a[],int p,int q)
{
    int pivot=p;
    int i=p;
    int j=i+1;

    while(j<=q)
    {
        if(a[j]<a[pivot])
        {
            i++;
            swap(a[j],a[i]);
        }
        j++;
    }
    swap(a[pivot],a[i]);
    return i;
}
void quicksort(int a[],int p,int q)
{
    if(p==q||p>q)
        return;
    else{
        int pindex=partition(a,p,q);//returns the pivot element time complexity==->O(n)
        quicksort(a,p,pindex-1);//recurrence relation T(n)=2T(n/2)+n
        quicksort(a,pindex+1,q);//solving it using master theorem we get time complexity of quicksort O(n)
    }
}
int main()
{
    int n;
    cout<<"enter size of array you want to sort";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"array before sorting"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    quicksort(a,0,n-1);
     cout<<"array after sorting";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
