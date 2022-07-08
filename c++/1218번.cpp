#include <bits/stdc++.h>
using namespace std;

string str;
int tc = 1, len;

void solution(){
  stack<char> s1, s2, s3, s4;
  bool flag = false;
  for(int i = 0; i < len; i++){
    if(str[i] == '('){
      s1.push('(');
    }else if(str[i] == ')'){
      if(!s1.empty() and s1.top() == '('){
        s1.pop();
      }else{
        // 플래그
        flag = true;
      }
    }else if(str[i] == '['){
      s2.push('[');
    }else if(str[i] == ']'){
      if(!s2.empty() and s2.top() == '['){
        s2.pop();
      }else{
        // 플래그
        flag = true;
      }
    }else if(str[i] == '{'){
      s3.push('{');
    }else if(str[i] == '}'){
      if(!s3.empty() and s3.top() == '{'){
        s3.pop();
      }else{
        // 플래그
        flag = true;
      }
    }else if(str[i] == '<'){
      s4.push('<');
    }else if(str[i] == '>'){
      if(!s4.empty() and s4.top() == '<'){
        s4.pop();
      }else{
        // 플래그
        flag = true;
      }
    }
  }

  if(s1.empty() and s2.empty() and s3.empty() and s4.empty() and !flag){
    cout << "#" << tc << " " << 1 << "\n";
  }else{
    cout << "#" << tc << " " << 0 << "\n";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  for(; tc <= 10; tc++){
    cin >> len >> str;
    solution();
  }
  return 0;
}