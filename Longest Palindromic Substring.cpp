
#include <bits/stdc++.h>
using namespace std;

// Function to print a substring
// str[low..high]
void printSubStr(string str, int low, int high)
{
	for (int i = low; i <= high; ++i)
		cout << str[i];
}

string longestPalSubstr(string str)
{
	int n = str.size();

	bool table[n][n];

	memset(table, 0, sizeof(table));

	int maxLength = 1;

	for (int i = 0; i < n; ++i)
		table[i][i] = true;

	// check for sub-string of length 2.
	int start = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (str[i] == str[i + 1]) {
			table[i][i + 1] = true;
			start = i;
			cout<<start<<endl;
			maxLength = 2;
		}
	}

	// Check for lengths greater than 2.
	// k is length of substring
	for (int k = 3; k <= n; ++k) {
		// Fix the starting index
		for (int i = 0; i < n - k + 1; ++i) {
			// Get the ending index of substring from
			// starting index i and length k
			int j = i + k - 1;

// 			checking for sub-string from ith index to
			// jth index iff str[i+1] to str[j-1] is a
			// palindrome
			if (table[i + 1][j - 1] && str[i] == str[j]) {
				table[i][j] = true;

				if (k > maxLength) {
					start = i;
				// 	cout<<start<<" "<<j<<endl;
					maxLength = k;
				}
			}
		}
	}

	string s;
    for (int i = start; i <= start+maxLength-1; ++i){
        // cout<<(char)str[i];
        s.push_back((char)str[i]);
    }
// 		cout<<endl<<s;
	return s;
}

int main()
{
	string str = "abb";
	cout << longestPalSubstr(str);
	return 0;
}
