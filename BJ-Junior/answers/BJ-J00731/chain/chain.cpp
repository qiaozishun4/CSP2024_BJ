#include<iostream>
#include<cstdio>
using namespace std;
int T;
int s[1001][2001];
bool flag;
void dfs(int n,int k,int t,int rj,int cj,int rt,int last){
    if(flag==1)return;
    if(rt==rj){
        if(last==cj){
            flag=1;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s[i][0];j++){
            for(int l=j+1;l-j+1<=k&&l<=s[i][0];l++){
                if(s[i][j]==last){
                    dfs(n,k,t,rj,cj,rt+1,s[i][l]);
                }
            }
        }
    }

}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    for(int t=1;t<=T;t++){
        int n=0,k=0,q=0;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>s[i][0];
            for(int j=1;j<=s[i][0];j++){
                cin>>s[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            int r,c;
            cin>>r>>c;
            flag=0;
            dfs(n,k,t,r,c,1,1);
            if(flag)cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
