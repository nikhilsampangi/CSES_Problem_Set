#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  int coins[n];
  int dp[x + 1] = {1};

  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }

  for (int j = 0; j < n; j++)
  {
    for (int i = 1; i <= x; i++)
    {
      if (i - coins[j] >= 0)
      {
        dp[i] = (dp[i] + dp[i - coins[j]]) % 1000000007;
      }
    }
  }
  cout << dp[x];
  return 0;
}
