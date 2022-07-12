#include <bits/stdc++.h>
using namespace std;
#define INF 210000000
int tc;
int arr[100][100];
int ans;

void solution(){
  ans = -INF;
  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      cin >> arr[i][j];
    }
  }
  
  int tmp3 = 0, tmp4 = 0;
  for(int i = 0; i < 100; i++){
    int tmp1 = 0, tmp2 = 0;
    for(int j = 0; j < 100; j++){
      tmp1 += arr[i][j];
      tmp2 += arr[j][i];
      if(i == j) tmp3 += arr[i][j];
      if(i + j == 99) tmp4 += arr[i][j];
    }
    ans = max({ans, tmp1, tmp2});
  }
  ans = max({ans, tmp3, tmp4});
  cout << "#" << tc << " " << ans << "\n";
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while(tc != 10){
    cin >> tc;
    solution();
  }


  return 0;
}