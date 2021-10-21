#include <bits/stdc++.h>
using namespace std;
string hex2bin(string s)
{
	// hexadecimal to binary conversion
	unordered_map<char, string> mp;
	mp['0'] = "0000";
	mp['1'] = "0001";
	mp['2'] = "0010";
	mp['3'] = "0011";
	mp['4'] = "0100";
	mp['5'] = "0101";
	mp['6'] = "0110";
	mp['7'] = "0111";
	mp['8'] = "1000";
	mp['9'] = "1001";
	mp['A'] = "1010";
	mp['B'] = "1011";
	mp['C'] = "1100";
	mp['D'] = "1101";
	mp['E'] = "1110";
	mp['F'] = "1111";
	string bin = "";
	for (int i = 0; i < s.size(); i++) {
		bin += mp[s[i]];
	}
	return bin;
}
string bin2hex(string s)
{
	// binary to hexadecimal conversion
	unordered_map<string, string> mp;
	mp["0000"] = "0";
	mp["0001"] = "1";
	mp["0010"] = "2";
	mp["0011"] = "3";
	mp["0100"] = "4";
	mp["0101"] = "5";
	mp["0110"] = "6";
	mp["0111"] = "7";
	mp["1000"] = "8";
	mp["1001"] = "9";
	mp["1010"] = "A";
	mp["1011"] = "B";
	mp["1100"] = "C";
	mp["1101"] = "D";
	mp["1110"] = "E";
	mp["1111"] = "F";
	string hex = "";
	for (int i = 0; i < s.length(); i += 4) {
		string ch = "";
		ch += s[i];
		ch += s[i + 1];
		ch += s[i + 2];
		ch += s[i + 3];
		hex += mp[ch];
	}
	return hex;
}

string permute(string k, int* arr, int n)
{
	string per = "";
	for (int i = 0; i < n; i++) {
		per += k[arr[i] - 1];
	}
	return per;
}


int main()
{
	string pt, key;
	cin>>pt;
	cout<<"Enter key(in hexadecimal): ";
	cin>>key;

	// pt = "123456ABCD132536";
	key = "AABB09182736CCDD";

	key = hex2bin(key);

	int keyp[56] = { 57, 49, 41, 33, 25, 17, 9,
					1, 58, 50, 42, 34, 26, 18,
					10, 2, 59, 51, 43, 35, 27,
					19, 11, 3, 60, 52, 44, 36,
					63, 55, 47, 39, 31, 23, 15,
					7, 62, 54, 46, 38, 30, 22,
					14, 6, 61, 53, 45, 37, 29,
					21, 13, 5, 28, 20, 12, 4 };

	key = permute(key, keyp, 56); 

	
}
