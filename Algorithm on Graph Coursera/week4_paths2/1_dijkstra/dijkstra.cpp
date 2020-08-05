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

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int src, int destination) {
  int n = adj.size();
  vector<int>dist(n, inf);
  dist[src] = 0;
  set<pair<int, int>>s;
  s.insert({0, src});
  while (!s.empty()) {
    auto x = *(s.begin());
    int d = x.first;
    int node = x.second;
    s.erase(s.begin());
    for (int i = 0; i < adj[node].size(); i++) {
      if (d + cost[node][i] < dist[adj[node][i]]) {
        auto f = s.find({dist[adj[node][i]], adj[node][i]});
        if (f != s.end())
          s.erase(f);
        dist[adj[node][i]] = d + cost[node][i];
        s.insert({dist[adj[node][i]], adj[node][i]});
      }
    }
  }
  if (dist[destination] != inf)
    return dist[destination];
  return -1;
}

int32_t main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  cin >> s >> t;
  s--, t--;
  cout << distance(adj, cost, s, t);
}