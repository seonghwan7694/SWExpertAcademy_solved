#include <bits/stdc++.h>
using namespace std;

int tc, v, a, b;
void solution(){
  cin >> v;
  vector<vector<int>> graph;
  graph.resize(101);
  bool visited[101] = {false};
  while(v--){
    cin >> a >> b; // a -> b;
    graph[a].push_back(b);
  }

  queue<int> q;
  q.push(0); visited[0] = true;
  while(!q.empty()){
    int cur = q.front(); q.pop();
    if(cur == 99){
      cout << "#" << tc << " " << 1 << "\n";
      return;
    }
    for(auto x : graph[cur]){
      if(!visited[x]){
        q.push(x); visited[x] = true;
      }
    }
  }
  cout << "#" << tc << " " << 0 << "\n";
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while(tc != 10){
    cin >> tc;
    solution();
  }

  return 0;
}