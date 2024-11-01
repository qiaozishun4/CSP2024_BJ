#include <iostream>
#include <cstdio>
using namespace std;
int t,n,m,k,x,y,d,ans;
int tmp[1001][1001];
string a[1005];
void dfs(int x,int y,int d){
    k--;
    if(!k){
        return ;
    }
    a[x][y]='/';
    if(d==0){
        if(y+1<=m&&a[x][y+1]!='x'){
            if(a[x][y+1]=='.'){
                ans++;
            }
            dfs(x,y+1,d);
        }else{
            dfs(x,y,(d+1)%4);
        }
    }else if(d==1){
        if(x+1<=n&&a[x+1][y]!='x'){
            if(a[x+1][y]=='.'){
                ans++;
            }
            dfs(x+1,y,d);
        }else{
            dfs(x,y,(d+1)%4);
        }
    }else if(d==2){
        if(y-1>=1&&a[x][y-1]!='x'){
            if(a[x][y-1]=='.'){
                ans++;
            }
            dfs(x,y-1,d);
        }else{
            dfs(x,y,(d+1)%4);
        }
    }else{
        if(x-1>=1&&a[x-1][y]!='x'){
            if(a[x-1][y]=='.'){
                ans++;
            }
            dfs(x-1,y,d);
        }else{
            dfs(x,y,(d+1)%4);
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        k++;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]='.'+a[i];
        }
        ans=1;
        dfs(x,y,d);
        cout<<ans<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}