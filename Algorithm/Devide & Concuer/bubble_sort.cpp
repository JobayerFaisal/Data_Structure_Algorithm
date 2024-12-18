#include <bits/stdc++.h>
using namespace std;


void bubble_sort(int A[], int m){
    int temp; 
    for(int i=0; i<m-1; i++){
        for(int j=0; j<m-i-1; j++){
            if(A[j] > A[j+1]) 
            swap(A[j],A[j+1]);
        }
        
    }
}



int main()
{
  int array_size; 
  cout << "Enter the size of the array: " ;
  cin >> array_size ;
  int arr[array_size] ;

  cout << "Enter the array: " ;
  for(int i=0; i<array_size; i++){
    cin >> arr[i] ;
  }
  
  bubble_sort(arr , array_size);
  
  cout << "The sorted array is: " ;
  for(int i=0; i<array_size; i++){
    cout << arr[i] << " ";
  }

  return 0;
}