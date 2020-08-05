#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd

bool oddcycle = false;
void bipartiteCheck(int node, int parent, int color, vector<int>&visited, vector<vector<int> > &adj) {
  visited[node] = color;
  for (int i = 0; i < adj[node].size(); i++) {
    if (!visited[adj[node][i]])
      bipartiteCheck(adj[node][i], node, 3 - color, visited, adj);
    else if (parent != node && color == visited[adj[node][i]]) {
      oddcycle = true;;
      return;
    }
  }
}

int bipartite(vector<vector<int> > &adj) {
  int n = adj.size();
  vector<int>visited(n, 0);
  for (int i = 0; i < n; i++) {
    if (!visited[i])
      bipartiteCheck(i, -1, 1, visited, adj);
    if (oddcycle)
      return 0;
  }

  return 1;
}

int main() {
  FASTIO;
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
