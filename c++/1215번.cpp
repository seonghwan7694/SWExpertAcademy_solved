#include <bits/stdc++.h>
using namespace std;

char board[8][8];
bool visited[8][8];
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int tc = 1;
int n, ans;
string tmp;

bool palindrome(){
  for(int i = 0; i < tmp.length()/2; i++){
    if(tmp[i] != tmp[tmp.length() - i - 1]){
      return false;
    }
  }
  return true;
}

void input(){
  cin >> n;
  for(int i = 0; i < 8; i++){
    string str; cin >> str;
    fill(visited[i], visited[i] + 8, false);
    for(int j = 0; j < 8; j++){
      board[i][j] = str[j];
    }
  }
}

int func(int x, int y, int k, int type){
  if(k == n){
    return palindrome();
  }

  int nx = x + dx[type];
  int ny = y + dy[type];
  if(nx < 0 or nx >= 8 or ny < 0 or ny >= 8) return 0;
  if(!visited[nx][ny]){
    visited[nx][ny] = true; tmp.push_back(board[nx][ny]);
    ans += func(nx, ny, k + 1, type);
    visited[nx][ny] = false; tmp.pop_back();
  }
   return 0;
}

void solution(){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      for(int k = 0; k < 2; k++){
        visited[i][j] = true; tmp.push_back(board[i][j]);
        ans += func(i, j, 1, k);
        visited[i][j] = false; tmp.pop_back();
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while(tc != 11){
    ans = 0;
    input();
    solution();
    cout << "#" << tc++ << " " << ans << "\n";
  }

  return 0;
}