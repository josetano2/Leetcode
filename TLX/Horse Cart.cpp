#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<long long int, long long int>> treasures;
  for (int i = 0; i < n; i++) {
    long long int x, y;
    cin >> x >> y;
    treasures.push_back({x, y});
  }

  sort(treasures.begin(), treasures.end(),
       [](const pair<long long int, long long int>& a,
          const pair<long long int, long long int>& b) {
         if (a.second != b.second) {
           return a.second > b.second;
         }
         return a.first < b.first;
       });

  multiset<long long int> carts;
  for (int i = 0; i < m; i++) {
    long long int c;
    cin >> c;
    carts.insert(c);
  }

  long long int tot = 0;

  for (int i = 0; i < n; i++) {
    auto it = carts.lower_bound(treasures[i].first);

    if (it == carts.end()) continue;

    tot += treasures[i].second;
    carts.erase(it);
  }

  cout << tot << endl;

  return 0;
}