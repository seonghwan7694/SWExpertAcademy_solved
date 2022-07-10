#include <bits/stdc++.h>
using namespace std;

int trash_value;
int st_x, st_y, en_y;
int dx[3] = {0, 0, -1};
int dy[3] = {-1, +1, 0};

void solution(int tc){
  int board[100][100] = {0};
  bool visited[100][100] = {0};
  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      cin >> board[i][j];
      if(board[i][j] == 2){
        st_x = i;
        st_y = j;
      }
    }
  }
  queue<pair<int, int>> q;
  q.push({st_x, st_y}); visited[st_x][st_y] = true;

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    if(cur.first == 0){
      en_y = cur.second;
      break;
    }
    for(int dir = 0; dir < 3; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if(nx < 0 or nx >= 100 or ny < 0 or ny >= 100 or visited[nx][ny] or board[nx][ny] == 0) continue;
      q.push({nx, ny}); visited[nx][ny] = true;
      break;
    }
  }
  cout << "#" << tc << " " << en_y << "\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  while(trash_value != 10){
    cin >> trash_value;
    solution(trash_value);
  }

  return 0;
}