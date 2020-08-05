#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd

void dfs(int node, vector<int>&visited, vector<int>&order, vector<vector<int> > &adj) {
  visited[node] = 1;
  for (int i = 0; i < adj[node].size(); i++) {
    if (!visited[adj[node][i]])
      dfs(adj[node][i], visited, order, adj);
  }
  order.push_back(node);
}

void rdfs(int node, vector<int>&visited, vector<vector<int> > &radj) {
  visited[node] = 1;
  for (int i = 0; i < radj[node].size(); i++) {
    if (!visited[radj[node][i]])
      rdfs(radj[node][i], visited, radj);
  }
}
int number_of_strongly_connected_components(vector<vector<int> > &adj, vector<vector<int> > &radj) {
  int result = 0;
  int n = adj.size();
  vector<int>order;
  vector<int>visited(n, 0);
  for (int i = 0; i < n; i++) {
    if (!visited[i])
      dfs(i, visited, order, adj);
  }
  for (int i = 0; i < n; i++)
    visited[i] = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (!visited[order[i]]) {
      result++;
      rdfs(order[i], visited, radj);
    }
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> >radj(n, vector<int>());
  vector<vector<int> >adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    radj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_strongly_connected_components(adj, radj);
}