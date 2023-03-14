#include "stack.h"
#include <stack>

bool validP(string a){
  stack<char> str;
  for(int i=0;i<a.length();i++){
    if(a[i]=='(' || a[i]=='[' || a[i]=='{'){
      str.push(a[i]);
    }
    else if(a[i]==')'){
      if(str.empty() || str.top() !='('){
        return false;
        }
      str.pop();
    }
    else if(a[i]==']'){
      if(str.empty() || str.top() !='['){
        return false;
        }
      str.pop();
    }
    else if(a[i]=='}'){
      if(str.empty() || str.top() !='{'){
        return false;
        }
      str.pop();
    }
  }
  return str.empty();
}
