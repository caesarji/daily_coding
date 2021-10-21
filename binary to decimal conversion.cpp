#include<bits/stdc++.h>
using namespace std;


string firstAlphabet(string S)
	{
    stringstream s(S); 
    string word; 
    string ss=""; 
  
    int count = 0;
    while (s >> word)
        ss+=word[0];
    return ss;
	}

int main(){
    cout<<"here";
    string ans=firstAlphabet("bad  is  badd  ");
    cout<<ans;
    return 1;

}