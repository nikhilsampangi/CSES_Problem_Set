#include <bits/stdc++.h>

using namespace std;

/*
You know that an array has n integers between 1 and m, and the difference between two adjacent values is at most 1.

Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.

Input

The first input line has two integers n and m: the array size and the upper bound for each value.

The next line has n integers x1,x2,…,xn: the contents of the array. Value 0 denotes an unknown value.

Output

Print one integer: the number of arrays modulo 109+7.

Constraints

    1≤n≤105


1≤m≤100

0≤xi≤m


Example

Input:
3 5
2 0 2

Output:
3
*/

const int mod = 1e9 + 7;


int main()
{
  int n, m;
  cin >> n >> m;
  long long dp[n][m + 1]; // stores the no of solutions till n for a given m value
  for(int i=0;i<n;i++){
	  for(int j=0;j<=m;j++){
		  dp[i][j]=0;
	  }
  }
  long long arr_descr[n];
  for (int i = 0; i < n; i++){
    cin >> arr_descr[i];
  }

  if (arr_descr[0] == 0){
    for (int i = 1; i <= m; i++)
      dp[0][i] = 1;
  }
  else{
    dp[0][arr_descr[0]] = 1;
  }
  for (int i = 1; i < n; i++){
    if (arr_descr[i] == 0){
	for (int j = 1; j <= m; j++){
		if(j-1 > 0 && j-1 <=m)
			dp[i][j]=(dp[i][j] + dp[i-1][j-1]) % mod;
		if(j>0 && j<=m)
			dp[i][j]=(dp[i][j] + dp[i-1][j]) % mod;
		if(j+1>0 && j+1<=m)
			dp[i][j]=(dp[i][j] + dp[i-1][j+1]) % mod;	
	}
    }
    else{
	int j=arr_descr[i];
	if(j-1 > 0 && j-1 <=m)
		dp[i][j]=(dp[i][j] + dp[i-1][j-1]) % mod;
	if(j>0 && j<=m)
		dp[i][j]=(dp[i][j] + dp[i-1][j]) % mod;
	if(j+1>0 && j+1<=m)
		dp[i][j]=(dp[i][j] + dp[i-1][j+1]) % mod;
    }
  }
  int sol = 0;
  for (int i = 1; i <= m; i++){
    sol = (sol + dp[n - 1][i])%mod;
  }
	cout << sol;
  return 0;
}

