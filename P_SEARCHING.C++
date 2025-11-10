#include<iostream>
using namespace std;

int linearsearch(int arr[],int n,int target)
{
    for(int i=0;i<n;i++)
    {
            if(arr[i]==target)
            {
                return i;
            }
    }
    return -1;

}

void bubblesort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int binarysearch(int arr[],int n,int target)
{
    int low=0; int high=n-1;

    while(low<=high)
    {
        int mid = (low + high)/2;

        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<target)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}

int main()
{
    int customers[50];
    int n;
    int target;

    cout<<" Enter no of customers: "<<endl;
    cin>>n;

    cout<<"Enter customer account id"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>customers[i];
    }

    cout<<"Enter target"<<endl;
    cin>>target;

    // linear search
    int pos = linearsearch(customers,n,target);
    if(pos == -1)
    {
        cout<<" Lineear search : not found"<<endl;
    }
    else{
        cout<<"Lineear search : found at"<<pos<<endl;
    }

    bubblesort(customers,n);

    // binary search
    pos = binarysearch(customers,n,target);
    if(pos == -1)
    {
        cout<<"Binary search : not found"<<endl;
    }
    else{
        cout<<"Binary search : found at"<<pos<<endl;
    }

    return 0;
}