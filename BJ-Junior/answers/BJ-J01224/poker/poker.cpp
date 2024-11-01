#include<bits/stdc++.h>
using namespace std;
char h[52];
char s[52];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >>n;
    int ans = 0;
    for(int i = 0;i<n;i++){
        bool f = false;
        f = false;
        cin >> h[i] >> s[i];
        for(int j = 0;j<i;j++){
            if(j == i){
                continue;
            }else{
                if(h[j] == h[i] && s[j] == s[i]){
                    f = true;
                }
            }
        }
        if(f == false){
                ans++;
        }
    }
    cout <<52-ans;
    return 0;
}
