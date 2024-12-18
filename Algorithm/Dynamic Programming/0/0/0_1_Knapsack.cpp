#include <bits/stdc++.h>
using namespace std;

void knapSack(int W, int WT[], int val[], int n)
{
    int DP[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else if (WT[i - 1] <= j)
                DP[i][j] = max(val[i - 1] + DP[i - 1][j - WT[i - 1]], DP[i - 1][j]);
            else
                DP[i][j] = DP[i - 1][j];
        }
    }

    cout <<"Max profit: "<< DP[n][W] << endl;

    cout << "Selected Objects are:- \n" ;
    int weight = W ;
    for(int i=4; i>0; i--){
        if(DP[i][W] != DP[i-1][W]){
            cout <<"Obj: "<< i << endl;
            weight -= WT[i] ;
        }
        
    }

    //return DP[n][W];
}




int main()
{
    int weight[] = {3,2,5,4};
    int profit[] = {4,3,6,5};
    int W = 5;
    int n = 4;
    knapSack(W, weight, profit, n);

    //cout << knapSack(W, weight, profit, n);
    return 0;
}