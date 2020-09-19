#include <bits/stdc++.h>

using namespace std;

typedef multimap<int, pair <int, int>> mm;
typedef multimap<int, pair <int, int>>::iterator mm_itr;

int main() {
  int n, t1, t2, t3;
  int day_index = 0;
  cin >> n;
  mm projects;
  map<int, int> days;
  for (int i = 0;i < n;i++) {
    cin >> t1 >> t2 >> t3;
    projects.insert({ t2 + 1, {t1,t3} });
    days.insert({ t1, day_index++ });
    days.insert({ t2 + 1, day_index++ });
  }
  long long dp[day_index] = { 0 };
  auto day = days.begin();
  dp[day->second] = 0;

  for (++day;day != days.end();day++) {
    auto prev_day = prev(day);
    dp[day->second] = dp[prev_day->second];
    pair<mm_itr, mm_itr> last_day = projects.equal_range(day->first);
    for (mm_itr itr = last_day.first; itr != last_day.second; itr++) {
      if (dp[days[itr->second.first]] + itr->second.second > dp[day->second]) {
        dp[day->second] = dp[days[itr->second.first]] + itr->second.second;
      }
    }
  }

  cout << dp[days.rbegin()->second];
  return 0;
}