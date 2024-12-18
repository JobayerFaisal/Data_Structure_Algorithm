#include <bits/stdc++.h>
using namespace std;


void merge_all(int A[], int left, int mid, int right){
    int n1 = mid-left+1;
    int n2 = right-mid ;
    int L[n1];
    int R[n2];

    for(int i=0 ; i<n1; i++){
        L[i] = A[left+i];
    }

    for(int i=0 ; i<n2; i++){
        R[i] = A[mid+1+i];
    }    

    int p=0,q=0,r=left ;

    while (p<n1 && q<n2)
    {
        if(L[p] >= R[q]){
            A[r] = L[p];
            p++;
        }
        else {
            A[r] = R[q];
            q++;
        }
        r++;
    }
        while(p<n1){
            A[r] = L[p];
            r++; p++;
        }
        while(q<n2){
            A[r] = R[q];
            r++; q++;
        }
}

void merge_sort(int A[], int left, int right){
    int mid;
    if(left<right)
        {mid = (left+right-1)/2;

        merge_sort(A,left,mid);
        merge_sort(A,mid+1,right);
        merge_all(A,left,mid,right);
        }
    
}

int min_count(int A[], int n, int target){
    int RA = target;
    int cnt = 0 ;

    for(int i=0; i<n; i++){
        while (target >= A[i])
        {
            cnt ++; 
            target = target - A[i] ;
        }
    }

    if(cnt)
        return cnt ; 
    else    
        return -1;

    
}

int main()
{
    int n = 4;

    int A[n] = {9, 6, 5, 1};
    int sum = 19 ;
    merge_sort(A,0,n-1) ;

    int count;
    count = min_count(A,n, sum);

    cout << "The minimun Number of coin is: " << count << ".\n" ;

    return 0;
}