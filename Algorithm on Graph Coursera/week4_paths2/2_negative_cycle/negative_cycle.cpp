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

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  int n = adj.size();
  vector<ll>dist(n, inf);
  dist[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int u = 0; u < n; u++) {
      for (int k = 0; k < adj[u].size(); k++) {
        int v = adj[u][k];
        int w = cost[u][k];
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          if (i == n - 1)
            return 1;
        }
      }
    }
  }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  cout << negative_cycle(adj, cost);
}
