#include <bits/stdc++.h>
using namespace std;

int N;

void clap(int k){
  stringstream ss;
  ss << k;
  string num = ss.str();
  int cnt = 0;
  for(char x : num){
    if(x == '3' or x == '6' or x == '9'){
      cnt++;
    }
  }
  if(!cnt){
    cout << k << " ";
  }else{
    while(cnt--) cout << "-";
    cout << " ";
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;

  for(int i = 1; i <= N; i++){
    clap(i);
  }

  return 0;
}