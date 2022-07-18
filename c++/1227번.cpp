#include <bits/stdc++.h>
using namespace std;
int tc;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void solution(){
  bool visited[100][100] = {false};
  int board[100][100];
  queue<pair<int, int>> q;
  for(int i = 0; i < 100; i++){
    string str; cin >> str;
    for(int j = 0; j < 100; j++){
      board[i][j] = str[j] - '0';
      if(board[i][j] == 2){
        q.push({i, j}); visited[i][j] = true;
      }
    }
  }
  
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    if(board[cur.first][cur.second] == 3){
      cout << "#" << tc << " 1" << "\n";
      return;
    }

    for(int dir = 0; dir < 4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if(nx < 0 or nx >= 100 or ny < 0 or ny >= 100) continue;
      if(!visited[nx][ny] and board[nx][ny] != 1){
        q.push({nx, ny}); visited[nx][ny] = true;
      }
    }
  }
  cout << "#" << tc << " 0" << "\n";
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int cnt = 10;
  while(cnt--){
    cin >> tc;
    solution();
  }

  return 0;
}