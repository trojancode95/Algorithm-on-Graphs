#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007


void dfs(int i, int visited[], vector<vector<int> > &adj) {
  visited[i] = 1;
  for (int x = 0; x < adj[i].size(); x++) {
    if (!visited[adj[i][x]])
      dfs(adj[i][x], visited, adj);
  }
}


int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  int n = adj.size();
  int visited[n] = {};
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      res++;
      dfs(i, visited, adj);
    }
  }
  return res;
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
  cout << number_of_components(adj);
}

