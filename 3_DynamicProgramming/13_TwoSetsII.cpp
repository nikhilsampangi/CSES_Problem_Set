#include <bits/stdc++.h>

using namespace std;

/*
Your task is to count the number of ways numbers 1,2,…,n can be divided into two sets of equal sum.

For example, if n=7, there are four solutions:

    {1,3,4,6}

and {2,5,7}

{1,2,5,6}
and {3,4,7}

{1,2,4,7}
and {3,5,6}

{1,6,7}
and {2,3,4,5}


Input

The only input line contains an integer n.

Output

Print the answer modulo 109+7.

Constraints

    1≤n≤500


Example

Input:
7

Output:
4
*/

const int mod = 1000000007;
const int max_n = 500;
long long dp[max_n + 1][62625 + 1] = { 0 };

int main() {
  int n;
  cin >> n;
  int sum = (n * (n + 1)) / 2;
  if (sum % 2) {
    cout << 0;
    return 0;
  }
  sum = sum / 2;
  dp[1][1] = 1;
  for (int i = 2;i <= n;i++) {// no of subsets in set 1toi which have sum j 
    dp[i][i] = 1;
    for (int j = 1;j <= sum && j <= ((i * (i + 1)) / 2) + 1;j++) {
      dp[i][j] = (dp[i][j] + dp[i - 1][j]) % (2 * mod);
      if (j > i) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % (2 * mod);
      }
    }
  }
  cout << (dp[n][sum] / 2); // since we need pairs
  return 0;
}