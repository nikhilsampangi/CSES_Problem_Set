#include <bits/stdc++.h>

using namespace std;

/*
You have n coins with certain values. Your task is to find all money sums you can create using these coins.

Input

The first input line has an integer n: the number of coins.

The next line has n integers x1,x2,…,xn: the values of the coins.

Output

First print an integer k: the number of distinct money sums. After this, print all possible sums in increasing order.

Constraints

    1≤n≤100


1≤xi≤1000


Example

Input:
4
4 2 5 2

Output:
9
2 4 5 6 7 8 9 11 13
*/

const int max_n = 100, max_X = 1000;
int dp[max_n * max_X + 1] = { 0 };
int ip[max_n];


int main() {
  int n;
  int sum = 0, count = 0;
  cin >> n;
  for (int j = 0; j < n; j++) {
    cin >> ip[j];
    sum += ip[j];

    if (!dp[ip[j]]) {
      count++;
      dp[ip[j]] = j + 1; // to know in which round the value was added
    }
    for (int i = 1; i <= sum; i++) {
      if (dp[i] && (dp[i] < j + 1)) { // if the value was present in the previous round then you can safely add current value without having any repetitions
        if (!dp[i + ip[j]]) {
          count++;
          dp[i + ip[j]] = j + 1;
        }

      }
    }
  }

  cout << count << endl;
  for (int i = 1; i < sum; i++) {
    if (dp[i])
      cout << i << " ";
  }
  cout << sum;
  return 0;
}