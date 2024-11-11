#include <bits/stdc++.h>
using namespace std;


void bubble_sort(int A[], int m){
    int temp; 
    //int m = a.size();
    for(int i=0; i<m-1; i++){
        for(int j=0; j<m-i-1; j++){
            if(A[j] > A[j+1]) 
            swap(A[j],A[j+1]);
        }
        
    }
}

int binary_search(int A[],int first,int last,int item){
    int mid = (first+last)/2 ;
    if(item == A[mid]){
        return mid ;
    }
    else{
        if(A[mid] > item){
            binary_search( A, first, mid-1, item);
        }

        else{
             binary_search( A, mid+1, last, item);
        }
    }
};



int main()
{

  int n; 
  cout << "Enter the size of the array: " ;
  cin >> n ;
  int arr[n] ;

  cout << "Enter the array: " ;
  for(int i=0; i<n; i++){
    cin >> arr[i] ;
  }

  bubble_sort(arr,n);

  int f = arr[0];
  int l = arr[n-1];
  int search_item;
  cout << "Inter the item to Search: " ;
  cin >> search_item ;

  // The binary search helps to find a NUMBER. 
  // Before search , the array must be sorted.

  int c = binary_search(arr ,f,l,search_item);
  cout <<"The Index of the number is: " << c ;

  return 0;
}