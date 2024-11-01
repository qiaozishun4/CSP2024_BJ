#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    int x = 52;
    string str[100];
    cin >> n;
    for(int i = 1; i <= n; i++){
           cin >> str[i];
           int flag = 1;
           for(int j = 1; j < i; j++){ 
                 if(str[i] == str[j]){
                       flag = 0;
                        break;
                  }
           }
            if(flag == 1) x--;
    }
    cout << x;
    return 0;
}