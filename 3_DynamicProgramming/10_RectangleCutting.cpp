#include <bits/stdc++.h>

using namespace std;

/*
Given an a×b rectangle, your task is to cut it into squares. On each move you can select a rectangle and cut it into two rectangles in such a way that all side lengths remain integers. What is the minimum possible number of moves?

Input

The only input line has two integers a and b.

Output

Print one integer: the minimum number of moves.

Constraints

		1≤a,b≤500


Example

Input:
3 5

Output:
3
*/

int main() {
	int dp[501][501], a, b; // dp[i][j] to store num  of cuts for rectangle of i rows and j cols
	cin >> a >> b;
	for (int i = 0;i <= a;i++) {
		dp[i][0] = 0;
	}
	for (int j = 0;j <= b;j++) {
		dp[0][j] = 0;
	}
	for (int i = 1;i <= 500;i++) {
		for (int j = i;j <= 500;j++) { // symmetric matrix
			if (i == j) {
				dp[i][j] = 0; // square
			}
			else {
				dp[i][j] = 250000;
				for (int j0 = 1;j0 <= j / 2;j0++) {
					dp[i][j] = min(dp[i][j], dp[i][j - j0] + dp[i][j0] + 1); // all possible column cuts
				}
				for (int i0 = 1;i0 <= i / 2;i0++) {
					dp[i][j] = min(dp[i][j], dp[i - i0][j] + dp[i0][j] + 1);// all possible row cuts
				}
				dp[j][i] = dp[i][j]; // symmetric
			}
		}
	}
	cout << dp[a][b];
	return 0;
}
