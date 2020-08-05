#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd

int distance(vector<vector<int> > &adj, int s, int t) {
  int n = adj.size();
  vector<int>distance(n, INT_MAX);
  distance[s] = 0;
  queue<pair<int, int>>q;
  q.push({s, 0});
  while (!q.empty()) {
    pair<int, int>p = q.front();
    q.pop();
    int node = p.first;
    int dist = p.second;
    for (int i = 0; i < adj[node].size(); i++) {
      if (distance[adj[node][i]] == INT_MAX) {
        distance[adj[node][i]] = dist + 1;
        q.push({adj[node][i], dist + 1});
      }
    }
  }
  if (distance[t] != INT_MAX)
    return distance[t];

  return -1;
}

int32_t main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}