#include<bits/stdc++.h>
using namespace std;



int maxLeft(int arr[] , int x){
        int mx=INT_MIN;
        for(int i=0; i<x; i++){
            if(arr[i]>mx)mx=arr[i];
        }
        return mx;
    }
int maxRightt(int arr[] , int x , int n ){
    int mx=INT_MIN;
    // if(x==arr.size()-1) return ;
    for(int i=x+1; i<n; i++){
        if(arr[i]>mx)mx=arr[i];
    }
    return mx;
}
    
    long long  trappingWater(int arr[], int n){
        long long tot=0;
        if(n==1) return (int)0;
        for( int i=1 ; i<n-1 ; i++){
            int maxLeft1=maxLeft(arr , i);
            int maxRight1=maxRightt(arr , i , n);
            
            tot+=max( min(maxLeft1 , maxRight1)-arr[i] , 0);
        }
    }

int main(){


}