//PASS
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt[4][22];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int x,y;
        if(s[0]=='D'){
            x=0;
        }
        else if(s[0]=='C'){
            x=1;
        }
        else if(s[0]=='H'){
            x=2;
        }
        else{
            x=3;
        }
        y=s[1]-'0';
        if(s[1]=='A')y=1;
        else if(s[1]=='T')y=10;
        else if(s[1]=='J')y=11;
        else if(s[1]=='Q')y=12;
        else if(s[1]=='K')y=13;
        cnt[x][y]++;
    }
    int ans=0;
    for(int i=0;i<4;i++){
        for(int j=1;j<=13;j++){
            if(cnt[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
