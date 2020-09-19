#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	int coins[n];
	int dp[x] = {0};

	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
		if (coins[i] - 1 < x)
			dp[coins[i] - 1] = 1;
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i - coins[j] >= 0)
			{
				if (dp[i - coins[j]] != 0)
				{
					if (dp[i] == 0)
						dp[i] = dp[i - coins[j]] + 1;
					else
						dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				}
			}
		}
	}
	if (dp[x - 1] == 0)
	{
		cout << -1;
		return 0;
	}
	cout << dp[x - 1];
	return 0;
}
