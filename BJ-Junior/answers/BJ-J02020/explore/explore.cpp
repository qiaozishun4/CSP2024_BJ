#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,m,k,x,y,d;
    cin>>T;
    while(T>0){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        char mp[1005][1005];
        mp[x][y]='#';
        int cnt=1;
        for(int i=0;i<=n+1;i++){
            mp[i][0]='x';
            mp[i][m+1]='x';
        }
        for(int j=0;j<=m+1;j++){
            mp[0][j]='x';
            mp[n+1][j]='x';
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        while(k>0){
        if(d%4==0){
            if(mp[x][y+1]=='.'){
                cnt++;
                y++;
                mp[x][y]='#';
            }else if(mp[x][y+1]=='#'){
                y++;
            }else if(mp[x][y+1]=='x'){
                d++;
            }
        }else if(d%4==1){
            if(mp[x+1][y]=='.'){
                cnt++;
                x++;
                mp[x][y]='#';
            }else if(mp[x+1][y]=='#'){
                x++;
            }else if(mp[x+1][y]=='x'){
                d++;
            }
        }else if(d%4==2){
            if(mp[x][y-1]=='.'){
                cnt++;
                y--;
                mp[x][y]='#';
            }else if(mp[x][y-1]=='#'){
                y--;
            }else if(mp[x][y-1]=='x'){
                d++;
            }
        }else if(d%4==3){
            if(mp[x-1][y]=='.'){
                cnt++;
                x--;
                mp[x][y]='#';
            }else if(mp[x-1][y]=='#'){
                x--;
            }else if(mp[x-1][y]=='x'){
                d++;
            }
        }
        k--;
        }

        cout<<cnt<<endl;
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}