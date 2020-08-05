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

struct edge {
  int u;
  int v;
  double weight;

  edge(int a, int b, double c) {
    u = a;
    v = b;
    weight = c;
  }
};

bool compare(edge a, edge b) {
  return a.weight < b.weight;
}

double weight(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

struct dsu {
  vector<int>p;
  void init(int n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  int get(int x) {
    return (x == p[x] ? x : p[x] = get(p[x]));
  }
  void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
    }
  }
};

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  int n = x.size();
  vector<edge>edges;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      edges.pb(edge(i, j, weight(x[i], y[i], x[j], y[j])));
    }
  }
  sort(edges.begin(), edges.end(), compare);
  dsu G;
  G.init(n);
  int m = edges.size();
  for (int i = 0; i < m; ++i) {
    int uu = edges[i].u;
    int vv = edges[i].v;
    double ww = edges[i].weight;
    if (G.get(uu) != G.get(vv)) {
      G.unite(uu, vv);
      result += ww;
    }
  }

  return result;
}

int32_t main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  cout << fixed << setprecision(10) << minimum_distance(x, y) << endl;
}
