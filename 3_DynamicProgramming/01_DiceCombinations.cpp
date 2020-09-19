#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long dp[1000000];
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	dp[3] = 8;
	dp[4] = 16;
	dp[5] = 32;
	for (int i = 6; i < n; i++)
	{
		dp[i] = dp[i - 1];
		for (int j = 2; j <= 6; j++)
		{
			dp[i] = (dp[i] + dp[i - j]) % 1000000007;
		}
	}
	cout << dp[n - 1];
}
