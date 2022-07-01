#include <bits/stdc++.h>
using namespace std;

int tc;

int solution(){
  int cnt = 10, res = 0, tmp;
  
  while(cnt--){
    cin >> tmp;
    (tmp % 2 == 1) ? res += tmp : 0;
  }
  return res;
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