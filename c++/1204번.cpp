#include <bits/stdc++.h>
using namespace std;

int tc, tmp;

int solution(){
  int score[101];
  fill(score, score + 101, 0);
  cin >> tmp;
  for(int i = 0, tmp; i < 1000; i++){
    cin >> tmp;
    score[tmp]++;
  }
  int MAX = *max_element(score, score + 101);
  for(int i = 100; i >= 0; i--){
    if(score[i] == MAX){
      return i;
    }
  }
  return 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> tc;
  for(int i = 1; i <= tc; i++){
    cout << "#" << i << " " << solution() << "\n";
  }
  return 0;
}