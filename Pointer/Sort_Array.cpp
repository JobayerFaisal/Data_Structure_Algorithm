#include <bits/stdc++.h>
using namespace std;

                                            // A function to implement bubble sort
void bubbleSort(int *arr, int n){
    for (int i = 0; i < n-1; i++)           // Last i elements are already
        for (int j = i+1; j < n; j++)
        {
            if (*(arr+i) > *(arr+j))
            {
                int temp = *(arr+i);        // swaping two numbers
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
            }
        }
}

void printArray(int *arr, int size){        // Function to print an array
    for (int i = 0; i < size; i++)
        cout << *(arr+i) << " ";
    cout << endl;
}

int main(){
    int n;
    cout << " Enter the size of the array: ";
    cin >> n;
    int arr[n];

                                            // Taking INPUT
    cout << " Enter the elements of the array: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout<< &arr[i]<< " ,";              // Location before swap
    }
cout<< endl ;



    bubbleSort(arr, n);
    cout << "The Sorted array is : ";
    printArray(arr, n);


    for (int i = 0; i < n; i++)
    {
        cout<< &arr[i]<< " ,";              // Location after swap
    }
    return 0;
}
