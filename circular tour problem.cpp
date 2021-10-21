#include<bits/stdc++.h>
using namespace std;

int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
int i=0,j=0,dis=0,gas=0,n=A.size();
int ans=-1; int k=0;
    do
    {
        if(gas>=dis)
        {
            gas=gas+A[j];
            dis=dis+B[j];
            // cout<<gas<<" "<<dis<<" i-"<<i<<"  "<<"j-"<<j<<endl;
            j=(j+1)%n; k++;
        }
        else
        {
            dis=0; gas=0; i=k;
            // cout<<"fuel low"<<endl;
            // gas=gas-A[i];
            // dis=dis-B[i];
            // cout<<gas<<" "<<dis<<endl;

            // i++;
        }
        if(     (j+1)%n==i  &&  gas+A[j]>=dis+B[j])
        { 
            // cout<<i<<"    "<<j+1<<endl;
            ans=i;
            break;
        }
    }
    while(i<n );
return ans;
}
int main(){
    
    
    vector<int>A={6,7,4,10,6,5};
    vector<int>B={5,6,7,8,6,4};
    cout<<canCompleteCircuit(A,B);
    
    // int t; cin>>t;
    // while(t--){
    //     solve();
        
    // }

    
    


}

