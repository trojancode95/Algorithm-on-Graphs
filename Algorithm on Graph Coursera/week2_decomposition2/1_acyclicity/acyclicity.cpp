#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd

bool dfs(int node, vector<vector<int> > &adj, vector<int>&visited, vector<int>&stack) {
  visited[node] = 1;
  stack[node] = 1;
  for (int i = 0; i < adj[node].size(); i++) {
    if (stack[adj[node][i]] == 1)
      return true;
    else if (!visited[adj[node][i]]) {
      bool cycle_mila = dfs(adj[node][i], adj, visited, stack);
      if (cycle_mila == true)
        return true;
    }
  }
  stack[node] = false;
  return false;
}


int acyclic(vector<vector<int> > &adj) {
  int n = adj.size();
  vector<int>visited(n, 0);
  vector<int>stack(n, 0);
  for (int i = 0; i < adj.size(); i++) {
    if (!visited[i]) {
      bool ans = dfs(i, adj, visited, stack);
      if (ans == true)
        return 1;
    }
  }
  return 0;
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
  std::cout << acyclic(adj);
}