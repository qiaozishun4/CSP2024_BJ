#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l,r,c,ok;
int s[1005][2005];
int dfs(int rs,int cs,int cr){
    if(rs==0&&cs==c){
        ok=1;
        return 0;
    }
    if(rs==0){
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;s[i][j]!=0;j++){
            if(s[i][j]==cs&&i!=cr){
                for(int l=1;l<k&&s[i][j+l]!=0;l++){
                    dfs(rs-1,s[i][j+l],i);
                }
            }
        }
    }
    return 0;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    cin>>n>>k>>q;
    for(int l=1;l<=t;l++){
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>s[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            dfs(r,1,0);
            if(ok==0){
                cout<<"0"<<endl;
            }
            else{
                cout<<"1"<<endl;
            }
            ok=0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
