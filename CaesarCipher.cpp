#include <bits/stdc++.h>
using namespace std;

string encrypt(string text, int k)
{
    string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        if((int)text[i]>=65  && (int)text[i]<=90)
        result += char(int(text[i] + k - 65 +26) % 26 + 65);
        else
        result += char(int(text[i] + k - 97 +26) % 26 + 97);
    }

    return result;
}
string decrypt(string result, int k)
{
    string res = "";

    for (int i = 0; i < result.length(); i++)
    {
        if((int)result[i]>=65  && (int)result[i]<=90)
        res += char(int(result[i] - k - 65 +26) % 26 + 65);
        else
        res += char(int(result[i] - k - 97 + 26) % 26 + 97);
    }

    return res;
}

int main()
{
    string text;
    cin >> text;
    int k;
    cin >> k;
    k=k%25;
    // cout<<(int)'a';
    // cout<<char((int('a'- k - 65) % 26 + 65))<<endl;
    // cout<<(int)'B'<<endl;
    cout << encrypt(text, k)<<endl;
    cout << decrypt(encrypt(text, k), k);
     return 0;
}
