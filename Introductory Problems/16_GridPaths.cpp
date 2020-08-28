#include <bits/stdc++.h>

using namespace std;

bool visited[7][7];
string ip;
int sol = 0;

void pathFind(int row, int col, int len_path = 0)
{
  if (row == 6 && col == 0)
  {
    if (len_path == 48)
    {
      sol++;
    }
    return;
  }
  visited[row][col] = true;
  if (ip[len_path] == '?' || ip[len_path] == 'L')
  {
    if (col && !visited[row][col - 1])
    {
      if (!(!(col - 2 >= 0 && !visited[row][col - 2]) && row + 1 < 7 && !visited[row + 1][col - 1] && row - 1 >= 0 && !visited[row - 1][col - 1]))
      {
        pathFind(row, col - 1, len_path + 1);
      }
    }
  }
  if (ip[len_path] == '?' || ip[len_path] == 'R')
  {
    if (col < 6 && !visited[row][col + 1])
    {
      if (!(!(col + 2 < 7 && !visited[row][col + 2]) && row + 1 < 7 && !visited[row + 1][col + 1] && row - 1 >= 0 && !visited[row - 1][col + 1]))
      {
        pathFind(row, col + 1, len_path + 1);
      }
    }
  }
  if (ip[len_path] == '?' || ip[len_path] == 'U')
  {
    if (row && !visited[row - 1][col])
    {
      if (!(!(row - 2 >= 0 && !visited[row - 2][col]) && col + 1 < 7 && !visited[row - 1][col + 1] && col - 1 >= 0 && !visited[row - 1][col - 1]))
      {
        pathFind(row - 1, col, len_path + 1);
      }
    }
  }
  if (ip[len_path] == '?' || ip[len_path] == 'D')
  {
    if (row < 6 && !visited[row + 1][col])
    {
      if (!(!(row + 2 < 7 && !visited[row + 2][col]) && col + 1 < 7 && !visited[row + 1][col + 1] && col - 1 >= 0 && !visited[row + 1][col - 1]))
      {
        pathFind(row + 1, col, len_path + 1);
      }
    }
  }

  visited[row][col] = false;
}

int main()
{
  cin >> ip;
  pathFind(0, 0);
  cout << sol;
  return 0;
}