#include <bits/stdc++.h>
using namespace std;

int n, res;
int building_high[1010];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  for(int tc = 1; tc <= 10; tc++){
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> building_high[i];
    }
    res = 0; 
    for(int i = 2, tmp; i < n - 2; i++){
      tmp = max({building_high[i-2], building_high[i-1], building_high[i+1], building_high[i+2]});
      if(building_high[i] > tmp){
        res += building_high[i] - tmp;
      }
    }
    cout << "#" << tc << " " << res << "\n";
  }

  return 0;
}