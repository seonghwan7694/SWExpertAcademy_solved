#include <bits/stdc++.h>
using namespace std;

int N, tc, ans, t;
int A[55][55];
bool visited[55][55];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solution(){
  cin >> N;
  for(int i = 0; i < N; i++){
    string str; cin >> str;
    fill(visited[i], visited[i] + N, false);
    for(int j = 0; j < N; j++){ A[i][j] = str[j] - '0'; }
  }
  queue<pair<int, pair<int, int>>> q;
  ans = 0;
  visited[N/2][N/2] = true; q.push({0, {N/2, N/2}});
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    ans += A[cur.second.first][cur.second.second];
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.second.first + dx[dir];
      int ny = cur.second.second + dy[dir];
      int ndepth = cur.first + 1;
      if(ndepth > N / 2 or visited[nx][ny]) continue;
      visited[nx][ny] = true; q.push({ndepth, {nx, ny}});
    }
  }
  cout << "#" << ++tc << " " << ans << "\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> t;
  while(t--){
    solution();
  }
  return 0;
}