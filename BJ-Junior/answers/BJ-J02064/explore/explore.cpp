#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int p[maxn][maxn];
int n,m,k,ans = 1;
void search_(int x,int y,int dir,int step){
    if(step == k){
        return;
    }
    if(dir == 0){
        if(y+1<=m && p[x][y+1] == 0){
            ans++;
            search_(x,y+1,dir,step+1);
        }
        else{
            search_(x,y,(dir+1)%4,step+1);
        }
    }
    else if(dir == 1){
        if(x+1<=n && p[x+1][y] == 0){
            ans++;
            search_(x+1,y,dir,step+1);
        }
        else{
            search_(x,y,(dir+1)%4,step+1);
        }
    }
    else if(dir == 2){
        if(y-1>=0 && p[x][y-1] == 0){
            ans++;
            search_(x,y-1,dir,step+1);
        }
        else{
            search_(x,y,(dir+1)%4,step+1);
        }
    }
    else{
        if(x-1>=0 && p[x-1][y] == 0){
            ans++;
            search_(x-1,y,dir,step+1);
        }
        else{
            search_(x,y,(dir+1)%4,step+1);
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int x_s,y_s,d_s;
        cin>>x_s>>y_s>>d_s;
        for(int i = 0; i <= n-1; i++){
            string help;
            cin>>help;
            for(int j = 0; j <= m-1; j++){
                if(help[j] == '.'){
                    p[i][j] = 0;
                }
                else{
                    p[i][j] = 1;
                }
            }
        }
        search_(x_s,y_s,d_s,1);
        cout<<ans;
        ans = 0;
    }

    return 0;
}
