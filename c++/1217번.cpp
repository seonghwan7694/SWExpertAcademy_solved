#include <bits/stdc++.h>
using namespace std;

int tmp, n, m;

int POW(int a, int b){
  if(b == 0) return 1;
  return a * POW(a, b - 1);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  for(int t = 1; t <= 10; t++){
    cin >> tmp;
    cin >> n >> m;
    cout << "#" << tmp << " " << POW(n, m) << "\n";
  }
  return 0;
}