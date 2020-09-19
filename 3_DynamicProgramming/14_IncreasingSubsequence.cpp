#include <bits/stdc++.h>

using namespace std;

/*
You are given an array containing n integers. Your task is to determine the longest increasing subsequence in the array, i.e., the longest subsequence where every element is larger than the previous one.

A subsequence is a sequence that can be derived from the array by deleting some elements without changing the order of the remaining elements.

Input

The first line contains an integer n: the size of the array.

After this there are n integers x1,x2,…,xn: the contents of the array.

Output

Print the length of the longest increasing subsequence.

Constraints

    1≤n≤2⋅105


1≤xi≤109


Example

Input:
8
7 3 5 3 6 2 9 8

Output:
4
*/

int main() {
  int n, ip;
  int sol = 0;
  cin >> n;
  cin >> ip;
  vector<int> al = { ip }; // active lists method
  for (int i = 1;i < n;i++) {
    cin >> ip;
    if (ip == al.front() || ip == al.back())
      continue;
    if (ip < al.front()) {
      al.front() = ip;
    }
    else if (ip > al.back()) {
      al.push_back(ip);
    }
    else {
      auto temp = lower_bound(al.begin(), al.end(), ip); // returns the first element not lower than ip
      *temp = ip;
    }
  }
  cout << al.size();
  return 0;
}