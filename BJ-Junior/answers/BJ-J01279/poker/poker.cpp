#include <bits/stdc++.h>
using namespace std;
string x,s[55];
int n,cnt = 1;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    cin >> s[0];
    for(int i = 1;i < n;i++){
        cin >> x;
        for(int j = 0;j < cnt;j++){
            if(x == s[j]){
                break;
            }
            s[cnt]=x;
            cnt++;
        }
    }
    cout << 52-cnt;
    return 0;
}