#include <bits/stdc++.h>

using namespace std;

int main()
{
  int books, max_price;
  cin >> books >> max_price;
  int prices[books], pages[books];
  int dp[max_price + 1] = {0};
  for (int i = 0; i < books; i++)
  {
    cin >> prices[i];
  }
  for (int i = 0; i < books; i++)
  {
    cin >> pages[i];
  }
  for (int i = 0; i < books; i++)
  {
    for (int j = max_price; j >= prices[i]; j--)
    {
      dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
    }
  }
  cout << dp[max_price];
  return 0;
}