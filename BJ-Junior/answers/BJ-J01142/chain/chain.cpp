#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int c[N][N],t[N];
int n,k,q;
bool dfs(int x,int y,int u){
    bool p=0;
    if(x==1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<t[i];j++){
                if(c[i][j]!=u)break;
                for(int p=j+1;p<j+k;p++){
                    if(p>t[i])break;
                    //cout<<c[i][p]<<" "<<y<<endl;
                    if(c[i][p]==y){
                        //cout<<i<<" "<<p<<endl;
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<t[i];j++){
            if(c[i][j]!=u)break;
            for(int p=j+1;p<j+k;p++){
                if(p>t[i])break;
                p=p|dfs(x-1,y,c[i][p]);
                //cout<<x-1<<" "<<y<<" "<<c[i][p]<<" "<<dfs(x-1,y,c[i][p])<<endl;
            }
        }
    }
    return p;

}
int main(){
    freopen("chain1.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>t[i];
            for(int j=1;j<=t[i];j++){
                cin>>c[i][j];
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<dfs(x,y,1)<<endl;
        }
    }
    cout<<dfs(1,4,2);
}
