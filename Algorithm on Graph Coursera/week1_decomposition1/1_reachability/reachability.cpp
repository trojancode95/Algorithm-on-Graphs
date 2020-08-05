#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd

int reach(vector<vector<int> > &adj, int x, int y, vector<int>&visited) {
  if (x == y)
    return 1;
  visited[x] = 1;
  for (int i = 0; i < adj[x].size(); i++) {
    if (!visited[adj[x][i]]) {
      if (reach(adj, adj[x][i], y, visited))
        return 1;
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  cin >> x >> y;
  vector<int>visited(adj.size(), 0);
  cout << reach(adj, x - 1, y - 1, visited);
}