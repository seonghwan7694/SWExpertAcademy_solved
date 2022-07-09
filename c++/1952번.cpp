#include <bits/stdc++.h>
using namespace std;

int tc, fee[4];
int plan[13];
int dp[13]; // dp[i] = cost : i번째 달까지 이용할 수 있는 최소 금액은 cost입니다.
void solution(int t){
  dp[1] = min({fee[0]*plan[1], fee[1]});
  dp[2] = min({dp[1] + fee[0] * plan[2], dp[1] + fee[1]});
  for(int i = 3; i <= 12; i++){
    dp[i] = min({dp[i-1] + fee[0] * plan[i], dp[i-1] + fee[1], dp[i-3] + fee[2]});
  }
  cout << "#" << t << " " << min(dp[12], fee[3]) << "\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> tc;
  for(int i = 1; i <= tc; i++){
    for(int i = 0; i < 4; i++){ cin >> fee[i]; }
    for(int i = 1; i <= 12; i++){ cin >> plan[i]; }
    solution(i);
  }
  return 0;
}