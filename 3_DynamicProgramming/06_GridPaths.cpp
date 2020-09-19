#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int path[n][n];
  char temp;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      path[i][j] = 0;
      cin >> temp;
      if (temp == '*')
      {
        path[i][j] = -1;
      }
    }
  }
  path[0][0]++;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (path[i][j] != -1)
      {
        if (i >= 1 && path[i - 1][j] != -1)
        {
          path[i][j] = (path[i][j] + path[i - 1][j]) % 1000000007;
        }
        if (j >= 1 && path[i][j - 1] != -1)
        {
          path[i][j] = (path[i][j] + path[i][j - 1]) % 1000000007;
        }
      }
    }
  }
  if (path[n - 1][n - 1] == -1)
    cout << 0;
  else
    cout << path[n - 1][n - 1];
  return 0;
}