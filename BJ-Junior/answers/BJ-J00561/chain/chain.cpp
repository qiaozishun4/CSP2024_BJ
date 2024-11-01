#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,s[1001][1001],l[1001],r,c,tong[10];
bool vis[1001][1001];
bool check(int i,int j,int u){
    for(int p = j;p<=u;p++){
        if(vis[i][p]==true)
                return false;
    }
    return true;
}
bool dfs(int step,int x,int y,int need){
    if(step>r&&need==c){
        return true;
    }
    else if(step>r&&need!=c)
        return false;
    if(tong[need]==0){
        return false;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=l[i];j++){
            if(s[i][j]==need){
  //                  cout << i << " " << j << endl;
                for(int u = j+1;u<j+k&&u<=l[i];u++){
                    if(check(i,j,u)){
                        for(int v = j;v<=u;v++){
                            vis[i][v]==true;
                            tong[s[i][v]]--;
                        }
                        bool result=dfs(step+1,i,u,s[i][u]);
                        for(int v = j;v<=u;v++){
                            vis[i][v]==false;
                            tong[s[i][v]]++;
                        }
                        if(result)
                            return true;
                    }
                }
            }
        }
    }
    return false;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int le = 1;le<=t;le++){
        cin>>n>>k>>q;
        for(int i =1;i<=n;i++){
            cin>>l[i];
            for(int j = 1;j<=l[i];j++){
                cin>>s[i][j];
                tong[s[i][j]]++;
            }
        }
        for(int i = 1;i<=q;i++){
            cin>>r>>c;
            if(dfs(1,1,1,1)){
                cout <<1<<endl;
            }else
                cout <<0 <<endl;
        }
    }
    return 0;
}
