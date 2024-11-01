#include<bits/stdc++.h>
using namespace std;
bool cnt[4][13];
char hs[4] = {'D','C','H','S'};
char ds[13] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int x,y;
        for(int i = 0;i < 4;i++){
            if(hs[i] == s[0]) x = i;
        }
        for(int i = 0;i < 13;i++){
            if(ds[i] == s[1]) y = i;
        }
        cnt[x][y] = true;
    }
    int ans = 0;
    for(int i = 0;i <4;i++){
        for(int j = 0;j < 13;j++){
            if(cnt[i][j] == false) ans++;
        }
    }
    cout<<ans;
    return 0;
}
