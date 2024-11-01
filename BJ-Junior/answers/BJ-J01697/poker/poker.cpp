#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    string s[55];
    for(int i = 0;i < n;i++){
        cin >> s[i];
    }
    int o = n;
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            if(s[i]==s[j]){
                o--;
            }
        }
    }
    int ans = 52-o;
    cout <<ans << endl;
    return 0;
}
