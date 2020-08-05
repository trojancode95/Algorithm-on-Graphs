#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd
#define inf INT_MAX
#define minf INT_MIN
#define pb push_back
#define all(v) v.begin(),v.end()
#define print(v) for(auto x:v) cout<<x<<" "; cout<<endl;
#define printn(v) for(auto x:v) cout<<x<<endl;
#define F first
#define S second
#define mp make_pair

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  int n = adj.size();
  distance[s] = 0;
  reachable[s] = 1;
  queue<int>q;
  for (int i = 0; i < n; i++) {
    for (int u = 0; u < n; u++) {
      for (int k = 0; k < adj[u].size(); k++) {
        int v = adj[u][k];
        int w = cost[u][k];
        if (distance[v] > distance[u] + w && distance[u] != numeric_limits<long long>::max()) {
          distance[v] = distance[u] + w;
          reachable[v] = 1;
          if (i == n - 1)
            q.push(v);
        }
      }
    }
  }
  vector<int>visited(n, 0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visited[u] = 1;
    shortest[u] = 0;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (!visited[v])
        q.push(v);
    }
  }
}

int main() {
  int n, m, s;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  cin >> s;
  s--;
  vector<long long> distance(n, numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      cout << "*\n";
    } else if (!shortest[i]) {
      cout << "-\n";
    } else {
      cout << distance[i] << "\n";
    }
  }
}