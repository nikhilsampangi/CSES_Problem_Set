#include <bits/stdc++.h>

using namespace std;

/*
There is a list of n numbers and two players who move alternately. On each move, a player removes either the first or last number from the list, and their score increases by that number. Both players try to maximize their scores.

What is the maximum possible score for the first player when both players play optimally?

Input

The first input line contains an integer n: the size of the list.

The next line has n integers x1,x2,…,xn: the contents of the list.

Output

Print the maximum possible score for the first player.

Constraints

    1≤n≤5000


−109≤xi≤109


Example

Input:
4
4 5 1 3

Output:
8
*/

const int max_n = 5000;
long long ip[max_n];
long long dp[max_n][max_n][2] = { 0 };

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ip[i];
  }

  int player_switch = 0;
  for (int i = 0;i < n;i++) {
    dp[i][i][player_switch] = ip[i]; // base case
  }
  for (int j = 1;j < n;j++) {
    player_switch = !player_switch;
    for (int i = 0;i + j < n;i++) {
      if (dp[i + 1][i + j][player_switch] + ip[i] > dp[i][i + j - 1][player_switch] + ip[i + j]) {
        dp[i][i + j][player_switch] = dp[i + 1][i + j][player_switch] + ip[i];
        dp[i][i + j][!player_switch] = dp[i + 1][i + j][!player_switch];
      }
      else {
        dp[i][i + j][player_switch] = dp[i][i + j - 1][player_switch] + ip[i + j];
        dp[i][i + j][!player_switch] = dp[i][i + j - 1][!player_switch];
      }
    }
  }

  cout << dp[0][n - 1][player_switch];
  return 0;
}