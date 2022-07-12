#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int tc = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solution(int t){
  int st_x, st_y;
  int board[16][16] = {0};
  bool visited[16][16] = {0};
  for(int i = 0; i < 16; i++){
    string str; cin >> str;
    for(int j = 0; j < 16; j++){
      board[i][j] = str[j] - '0';
      if(board[i][j] == 2){
        st_x = i;
        st_y = j;
      }
    }
  }

  queue<pair<int ,int>> q;
  q.push({st_x, st_y}); visited[st_x][st_y] = true;
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    if(board[cur.first][cur.second] == 3){
      cout << "#" << tc << " " << 1 << "\n";
      return;
    }
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if(nx < 0 or nx >= 16 or ny < 0 or ny >= 16 or visited[nx][ny] or board[nx][ny] == 1) continue;
      q.push({nx, ny}); visited[nx][ny] = true;
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
    solution(tc);
  }
}