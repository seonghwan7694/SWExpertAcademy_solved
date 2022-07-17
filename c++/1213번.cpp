#include <bits/stdc++.h>
using namespace std;

int tc; string a, b;

void solution(){
  int ans = 0;
  cin >> a >> b;

  for(int i = 0; i < b.length(); i++){
    if(b[i] == a[0]){
      int cnt = 0;
      for(int j = i; j < i + a.length(); j++){
        if(b[j] == a[j - i]) cnt++;
        else break;
      }
      if(cnt == a.length()) ans++;
    }
  }
  cout << "#" << tc << " " << ans << "\n";
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while(cin >> tc){
    solution();
  } 
  return 0;
}