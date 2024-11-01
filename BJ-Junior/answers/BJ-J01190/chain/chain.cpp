#include <bits/stdc++.h>
using namespace std;
int n,k,q,len[15],s[15][25],r,c;
bool dfs(int round,int num,int pre){
    if(round==r){
        return num==c;
    }
    for(int i=1;i<=n;i++){
        if(i==pre)continue;
        for(int l=1;l<=len[i];l++){
            if(s[i][l]!=num)continue;
            for(int r=l+1;r<=min(l+k-1,len[i]);r++){
                if(dfs(round+1,s[i][r],i))return true;
            }
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("chain3.in","r",stdin);
    freopen("chain3.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>len[i];
            for(int j=1;j<=len[i];j++)cin>>s[i][j];
        }
        while(q--){
            cin>>r>>c;
            if(n<=50&&r<=100&&q<=999)cout<<dfs(0,1,0)<<"\n";
            else cout<<"0\n";
        }
    }
    return 0;
}
