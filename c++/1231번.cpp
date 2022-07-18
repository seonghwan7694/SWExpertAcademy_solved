#include <bits/stdc++.h>
using namespace std;

int tc;
char node[101];

void DFS(vector<int> adj[], int cur){
  if(adj[cur].size() == 2){
    DFS(adj, adj[cur][0]);
    cout << node[cur];
    DFS(adj, adj[cur][1]);
  }else if(adj[cur].size() == 1){
    DFS(adj, adj[cur][0]);
    cout << node[cur];
  }else if(adj[cur].empty()){
    
  }
}

void solution(){
  int N;
  cin >> N;
  vector<int> adj[101];
  int tree[101] = {0};
  fill(node, node + 101, 0);
  string str;
  while(N--){
    getline(cin, str);
    node[str[0] - '0'] = str[2];
    if(str.length() >= 7){
      adj[str[0] - '0'].push_back(str[4] - '0');
      adj[str[0] - '0'].push_back(str[6] - '0');
    }else if(str.length() >= 5){
      adj[str[0] - '0'].push_back(str[4] - '0');
    }
  }

  cout << "#" << ++tc << " ";
  DFS(adj, 1);
  cout << "\n";
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