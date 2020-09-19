#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int dp[n + 1] = {0};
  for (int i = 1; i <= n; i++)
  {
    dp[i] = 1e6;
    int num = i;
    while (num >= 1)
    {
      if (i >= (num % 10))
      {
        dp[i] = min(dp[i], dp[i - (num % 10)] + 1);
      }

      num = num / 10;
    }
  }
  cout << dp[n];
  return 0;
}
