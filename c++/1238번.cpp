#include <bits/stdc++.h>
using namespace std;

int tc;

void solution(){
  bool check[101][101] = {false};
  vector<int> graph[101];
  vector<int> dist[202];
  bool visited[101] = {false};
  int from, to, n, m, prev;

  cin >> n >> m;
  n /= 2;
  while(n--){
    cin >> from >> to;
    if(!check[from][to]){
      check[from][to] = true;
      graph[from].push_back(to);
    }
  }

  for(int i = 1; i <= 100; i++){
    sort(graph[i].begin(), graph[i].end());
  }
  
  queue<pair<int, int>> q;

  q.push({0, m});
  visited[m] = true;
  dist[0].push_back(m);

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(auto nxt : graph[cur.second]){
      if(!visited[nxt]){
        q.push({cur.first + 1, nxt});
        visited[nxt] = true;
        dist[cur.first + 1].push_back(nxt);
      }
    }
  }
  
  cout << "#" << ++tc << " ";
  for(int i = 104; i >= 0; i--){
    if(dist[i].empty()) continue;
    cout << *max_element(dist[i].begin(), dist[i].end()) << "\n";
    return;
  }
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int ten = 10;
  while(ten--){
    solution();
  }

  return 0;
}