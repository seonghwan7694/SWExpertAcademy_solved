#include <bits/stdc++.h>
using namespace std;
#define init 375
#define INF 987654321

// (375, 375) ~ (425, 425) 기준, 이 녀석은 그대로
// 죽어있는 세포, 활성화 및 비활성화 상태인 세포를 기록할 배열 
int cell[800][800];

int N, M, K, tc;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init_array(){
  for(int i = 0; i < 800; i++){
    fill(cell[i], cell[i] + 800, 0);
  }
  return;
}

void update_cell(vector<pair<int, pair<int, int>>> &v, int X, int Y, int life){
  if(cell[X][Y] == 0){ // init
    v.push_back({life, {X, Y}});
    cell[X][Y] = life;
    return;
  }

  for(auto iter = v.begin(); iter != v.end(); iter++){ // update
    int x = iter->second.first;
    int y = iter->second.second;
    if(x == X and y == Y and life > iter->first){
      *(iter) = {life, {x, y}};
      cell[x][y] = life;
      return;
    }
  }
}

void solution(int t){
  cin >> N >> M >> K;

  // {k, {x, y}} -> {x, y} 에 위치한 셀은 현재 생명력이 k입니다.
  vector<pair<int, pair<int, int>>> v; // 비활성 세포를 담는 동적 배열

  // {k, {x, y}} -> {x, y} 에 위치한 셀의 원래 생명력은 k입니다.
  queue<pair<int, pair<int, int>>> q; // 활성화된 세포를 담는 큐

  // {k, {x, y}} -> {x, y} 에 위치한 셀의 생명력은 k이다.
  queue<pair<int, pair<int, int>>> tmp; // 새로 기록할 셀을 담는 큐

  for(int i = init; i < init + N; i++){
    for(int j = init; j < init + M; j++){
      cin >> cell[i][j]; // 초기 상태는 비활성 상태
      if(cell[i][j] > 0) v.push_back({cell[i][j], {i, j}});
    }
  }



  // 시뮬레이션 시작!
  for(int k = 1; k <= K; k++){
    cout << "#" << t << " / " << k << "시간 / " << "v : " << v.size() << " / q : " << q.size() << " / tmp : " << tmp.size() << "\n";
    // 활성화된 줄기 세포는 첫 1시간 동안 상, 하, 좌, 우 네 방향으로 동시에 번식을 한다.
    while(!q.empty()){ // (구현 완료) 방금 활성화 상태가 된 셀에 대해 bfs를 돌린다.
      auto x = q.front(); q.pop();
      for(int dir = 0; dir < 4; dir++){
        int nx = x.second.first + dx[dir];
        int ny = x.second.second + dy[dir];
        int life = x.first;

        // 하나의 그리드 셀에는 하나의 줄기 세포만 존재할 수 있기 때문에
        // 번식하는 방향에 이미 줄기 세포가 존재하는 경우 해당 방향으로 추가적으로 번식하지 않는다.
        if(cell[nx][ny] != 0) continue;

        // 현 시간에 그 자리에 세포가 없다면, 큐에 넣는다. 
        tmp.push({cell[x.second.first][x.second.first], {nx, ny}});
      }
    }
    cout << "#" << t << " / " << k << "시간 / " << "v : " << v.size() << " / q : " << q.size() << " / tmp : " << tmp.size() << "\n";

    while(!tmp.empty()){ // 활성화 결과를 기록한다.
      auto cur = tmp.front(); tmp.pop();
      int cur_x = cur.second.first;
      int cur_y = cur.second.second;
      int cur_life = cur.first;
      // 두 개 이상의 줄기 세포가 하나의 그리드 셀에 동시 번식하려고 하는 경우,
      // 생명력 수치가 높은 줄기 세포가 해당 그리드 셀을 혼자서 차지하게 된다.
      if(cur_life > cell[cur_x][cur_y]){
        // 번식된 줄기 세포는 비활성 상태이다.
        update_cell(v, cur_x, cur_y, cur_life);
      }
    }  
    cout << "#" << t << " / " << k << "시간 / " << "v : " << v.size() << " / q : " << q.size() << " / tmp : " << tmp.size() << "\n";

    for(auto iter = v.begin(); iter != v.end(); iter++){ // (구현 완료) 비활성 세포의 생명력이 1 감소한다.
      int cur_x = iter->second.first;
      int cur_y = iter->second.second;
      int cur_life = iter->first;
      if(--cur_life == 0){
        q.push({cell[cur_x][cur_y], {cur_x, cur_y}});
        v.erase(iter);
        iter--;
      }else{
        *iter = {cur_life, {cur_x, cur_y}};
      }
    }

    // 답 = 비활성 상태 세포 + 활성 상태 세포
    cout << "#" << t << " / " << k << "시간 / " << "v : " << v.size() << " / q : " << q.size() << " / tmp : " << tmp.size() << "\n";
    
    
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> tc;
  for(int t = 1; t <= tc; t++){
    init_array();
    solution(t);
  }
  return 0;
}