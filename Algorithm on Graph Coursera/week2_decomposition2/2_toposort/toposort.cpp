#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
  used[x] = 1;
  for (int i = 0; i < adj[x].size(); i++) {
    if (!used[adj[x][i]])
      dfs(adj, used, order, adj[x][i]);
  }
  order.push_back(x);
}

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);
  vector<int> order;
  for (int i = 0; i < adj.size(); i++) {
    if (!used[i])
      dfs(adj, used, order, i);
  }
  reverse(order.begin(), order.end());
  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
