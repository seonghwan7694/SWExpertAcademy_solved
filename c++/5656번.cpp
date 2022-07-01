#include <bits/stdc++.h>
using namespace std;

int tc, N, W, H;
int board[20][20];
int tmp[5][20][20][20]; // tmp[N][H][W][type]
vector<int> ans;

void input(){
  cin >> N >> W >> H;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> board[i][j];
    }
  }
  return;
}

void erase_brick(int w, int type){

}

void move_brick(int w, int type){

}
int check_brick(){

}
void solution(int n, int w, int type){ // n번 남은 기회로, w 열에 구슬을 떨어뜨린다.
  if(n == 0){
    ans.push_back(check_brick());
    return;
  }else{ 
    erase_brick(w, type);
    move_brick(w, type);
  }
  for(int i = 0; i < w; i++){
    solution(n - 1, i, i);
  }
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> tc;
  
  for(int i = 1; i <= tc; i++){
    input();
    cout << "#" << i << " " << solution(N, W, W) << "\n";
  }
  return 0;
}