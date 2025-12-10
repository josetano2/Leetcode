#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> p;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    p.push_back(t);
  }

  priority_queue<int> pq;
  int i = 0;
  for (i = 0; i < n; i++) {
    int currMilk = m - p[i];
    pq.push(p[i]);

    // Enough milk
    if (currMilk >= 0) {
      m -= p[i];
    }
    // Try to use biscuit
    else {
      if (k == 0) break;

      int top = pq.top();
      m = m + top - p[i];
      k--;
      pq.pop();
    }
  }
  cout << i << endl;

  return 0;
}