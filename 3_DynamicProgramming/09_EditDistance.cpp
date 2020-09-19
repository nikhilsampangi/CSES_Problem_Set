#include <bits/stdc++.h>

using namespace std;

/*
The edit distance between two strings is the minimum number of operations required to transform one string into the other.

The allowed operations are:

		Add one character to the string.
		Remove one character from the string.
		Replace one character in the string.

For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.

Your task is to calculate the edit distance between two strings.

Input

The first input line has a string that contains n characters between A–Z.

The second input line has a string that contains m characters between A–Z.

Output

Print one integer: the edit distance between the strings.

Constraints

		1≤n,m≤5000


Example

Input:
LOVE
MOVIE

Output:
2
*/

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	int n = str1.length();
	int m = str2.length();
	int dp[n + 1][m + 1];
	// initialization
	for (int i = 0;i <= n;i++) {
		dp[i][0] = i;
	}
	for (int j = 0;j <= m;j++) {
		dp[0][j] = j;
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			int temp1 = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1); // addition and deletion
			int temp2 = 1; // for modification
			if (str1[i - 1] == str2[j - 1]) {
				temp2 = 0; // if the characters are the same no need for modification
			}
			dp[i][j] = min(temp1, dp[i - 1][j - 1] + temp2);
		}
	}
	cout << dp[n][m];
	return 0;
}
