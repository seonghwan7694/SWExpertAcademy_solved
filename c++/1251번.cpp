#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 최소 스패닝 트리?
typedef struct{
  ll x, y;
}Node;

ll tc, N;
ll parent[1010];
bool visited[1010], is_merge;
Node node[1010];

double E;

ll find(int u){
  if(u == parent[u]) return u;
  return parent[u] = find(parent[u]);   
}

void merge(int u, int v){
  is_merge = false;
  u = find(u);
  v = find(v);

  if(u == v){
    return;
  }
  if(u < v) parent[v] = u;
  else parent[u] = v;
  is_merge = true;
  return;
}

ll get_cost(Node u, Node v){
  return (abs(u.x - v.x)*abs(u.x - v.x)) + (abs(u.y - v.y)*abs(u.y - v.y));
}

void solution(){
  vector<pair<ll, pair<ll, ll>>> edge;
  for(ll i = 0; i < N - 1; i++){
    for(ll j = i + 1; j < N; j++){
      edge.push_back({get_cost(node[i], node[j]), {i, j}});
    }
  }
  sort(edge.begin(), edge.end());

  ll sum = 0;
  ll num = 0;
  for(ll i = 0; i < edge.size(); i++){
    ll weight = edge[i].first;
    ll u = find(edge[i].second.first);
    ll v = find(edge[i].second.second);

    merge(u, v);
    if(is_merge){
      sum += weight;
      num++;
    }

    if(num == N - 1){
      cout << (ll) floor(sum * E + 0.5) << "\n";
      break;
    }
  }
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  cin >> tc;
  for(int t = 1; t <= tc; t++){
    cin >> N; // N : 섬의 개수

    for(int i = 0; i < N; i++){
      parent[i] = i;
    }
    for(int i = 0; i < N; i++){ cin >> node[i].x; }
    for(int i = 0; i < N; i++){ cin >> node[i].y; }

    cin >> E; // E : 환경 부담 세율
    cout << "#" << t << " ";
    solution();
  }

  return 0;
}