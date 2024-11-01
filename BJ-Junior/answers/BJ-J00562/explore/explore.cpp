#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    char game_map[1001][1001];
    while(T--){
        int n,m,k;
        cin>>n>>m>>k;
        memset(game_map,0,sizeof(game_map));
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>game_map[i][j];
            }
        }
        int ans=1;
        for(int work=1;work<=k;work++){
            if(d==0){
                if(y+1>m||game_map[x][y+1]=='x'){
                        d=(d+1)%4;
                    }else{
                        game_map[x][y]=';';
                        y++;
                        if(game_map[x][y]!=';'){
                            ans++;
                        }
                    }
            }else if(d==1){
                if(x+1>n||game_map[x+1][y]=='x'){
                        d=(d+1)%4;
                    }else{
                        game_map[x][y]=';';
                        x++;
                        if(game_map[x][y]!=';'){
                            ans++;
                        }
                    }
            }else if(d==2){
                if(y-1<1||game_map[x][y-1]=='x'){
                        d=(d+1)%4;
                    }else{
                        game_map[x][y]=';';
                        y--;
                        if(game_map[x][y]!=';'){
                            ans++;
                        }

                    }
            }else if(d==3){
                if(x-1<1||game_map[x-1][y]=='x'){
                        d=(d+1)%4;
                    }else{
                        game_map[x][y]=';';
                        x--;
                        if(game_map[x][y]!=';'){
                            ans++;
                        }
                    }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
