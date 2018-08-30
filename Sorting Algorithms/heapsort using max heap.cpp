#include <iostream>
//sorting array using max heap
using namespace std;
void max_heapify(int a[],int n,int i)
{
    int large=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&a[l]>a[large])
        large=l;
    if(r<n&&a[r]>a[large])
        large=r;
    if(large!=i)
   {

    swap(a[i],a[large]);
    max_heapify(a,n,large);
}
}
void heapsort(int a[],int n)
{   //building max heap
    for(int i=(n/2)-1;i>=0;i--)//creating a max heap tree such that parent is always greater from its child
    {                          //n/2-1 is the largest index of non leaf node
        max_heapify(a,n,i);    //leaf nodes are already max heaps.
    }                          //time complexity of building heap is O(n)
    for(int i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);//extracting each element from the top which is the maximal elements of our max heap and placing it at the end of array
        max_heapify(a,i,0);//now we keep on deleting every element and apply max heap to find next maximal
    }                      //each deletion takes O(logn) time therefore for n elements it takes O(nlogn) 
}

int main()
{
    int n;
    cout<<"Enter how many elements you want in your array";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<endl;
    cout<<"array before sorting";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    heapsort(a,n);
    cout<<endl<<"array after sorting";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
