#include <bits/stdc++.h>
using namespace std;
#define ll long long
int tc, n;
ll arr[1010101], money, st, en;

/*
ll* get_max_element(ll* st, ll* en){
  ll* max_element_position;
  ll tmp = 0;
  for(ll* p = st; p < en; p++){
    if(*p > tmp){
      tmp = *p;
      max_element_position = p;
    }
  }
  return max_element_position;
}
*/

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> tc;
  for(int i = 1; i <= tc; i++){
    cin >> n;
    for(int j = 0; j < n; j++){
      cin >> arr[j];
    }
    money = 0;
    st = 0, en = n;
    while(st < en){
      ll p = max_element(arr + st, arr + en) - arr;
      if(p == st){
        st++; continue;
      }
      for(int k = st; k < p; k++){
        money -= arr[k];
      }
      money += (arr[p] * (p - st));
      st = p + 1;
    }
    cout << "#" << i << " " << money << "\n";
  }

  return 0;
}