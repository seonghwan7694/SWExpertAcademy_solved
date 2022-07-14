#include <bits/stdc++.h>
using namespace std;

int st_x, st_y, en_x, en_y;
int tc, n, result, current;

struct Node{
  int x;
  int y;
  int idx;
};

bool visited[10];
Node customer[10];

void DFS(int x, int y, int count){
  if(count == n){
    current += abs(en_x - x) + abs(en_y - y);
    result = min(result, current);
    current -= abs(en_x - x) + abs(en_y - y);
    return;
  }

  for(int i = 0; i < n; i++){
    if(!visited[customer[i].idx]){
      visited[customer[i].idx] = true;
      current += abs(customer[i].x - x) + abs(customer[i].y - y);

      DFS(customer[i].x, customer[i].y, count + 1);

      current -= abs(customer[i].x - x) + abs(customer[i].y - y);
      visited[customer[i].idx] = false;
    }
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> tc;
  for(int i = 1; i <= tc; i++){
    cin >> n >> st_x >> st_y >> en_x >> en_y;
    result = 987654321;
    current = 0;
    for(int j = 0; j < n; j++){
      cin >> customer[j].x >> customer[j].y;
      customer[j].idx = j;
      visited[j] = false;
    }
    DFS(st_x, st_y, 0);
    cout << "#" << i << " " << result << "\n";
  }

  return 0;
}