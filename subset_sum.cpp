#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[],int n,int sum)
{
    if(sum==0)
        return true;
    if(n==0 && sum!=0)
        return false;

    if(arr[n-1]>sum)
        return isSubsetSum(arr,n-1,sum);


    return isSubsetSum(arr,n-1,sum) || isSubsetSum(arr,n-1,sum-arr[n-1]);

}

bool isSubsetSumDP(int arr[],int n,int sum)
{
    bool subset[n+1][sum+1];


    for(int i=0;i<=n;i++)
        subset[i][0] = true;

    for(int i=1;i<=sum;i++)
        subset[0][i] = false;


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<arr[i-1])
                subset[i][j] = subset[i-1][j];
            if(j>=arr[i-1])
                subset[i][j] = subset[i-1][j] || subset[i-1][j-arr[i-1]];
        }
    }

    return subset[n][sum];
}

int main()
{
    cout << "Enter the number of elements ";
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    cout << "Enter the sum value ";
    int sum;
    cin >> sum;

    if(isSubsetSum(arr,n,sum))
        cout << "Sum exists ";
    else
        cout << "Sum not exists ";

    // dp solution

    cout << endl << "DP solution " << endl;

    if(isSubsetSumDP(arr,n,sum))
        cout << "Sum exists ";
    else
        cout << "Sum not exists ";


    return 0;

}