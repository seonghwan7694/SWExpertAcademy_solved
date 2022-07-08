#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  for(int i = 1, res; i <= n; i++){
    res = 0;
    for(int j = 0, tmp; j < 10; j++){
      cin >> tmp;
      res += tmp;
    }
    cout << "#" << i << " " << (int) floor((res/10.0) + 0.5)<< "\n";
  }
  return 0;
}