#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,k,x,y,d,ans,n,m;
    char mp[1005][1005],v[1005][1005];
    for(int i = 0; i < T; i++){
        ans = 1;
        cin >> n >> m >> k >> x >> y >> d;
        for(int j = 0; j < n; j++){
            for(int k2 = 0; k2 < m; k2++){
                cin >> mp[j][k2];
                v[j][k2] = '0';
            }
        }
        for(int j = 0; j < k; j++){
            v[x][y] = '1';
            if(d==0 && x+1<=m && mp[x+1][y]=='.'){
                x+=1;
                if(v[x][y]=='0') ans++;
            }
            else if(d==1 && y+1<=n && mp[x][y+1]=='.'){
                y+=1;
                if(v[x][y]=='0') ans++;
            }
            else if(d==2 && x-1>=0 && mp[x-1][y]=='.'){
                x-=1;
                if(v[x][y]=='0') ans++;
            }
            else if(d==3 && y-1>=0 && mp[x][y-1]=='.'){
                y-=1;
                if(v[x][y]=='0') ans++;
            }else{
                d = (d+1)%4;
            }
        }
        cout << ans;
    }
    return 0;
}