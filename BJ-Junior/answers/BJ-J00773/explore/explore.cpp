#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
char c;
int mp[1005][1005];
int b[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while (t--){
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        memset(mp,0,sizeof(mp));
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin>>c;
                if (c=='x'){
                    mp[i][j]=1;
                }
                else{
                    mp[i][j]=0;
                }
            }
        }
        b[x][y]=1;
        int ans=0;
        while (k--){
            int tx=x+dx[d],ty=y+dy[d];
            if (mp[tx][ty]==1 or tx<1 or tx>n or ty<1 or ty>m){
                d=(d+1)%4;
            }
            else{
                b[tx][ty]=1;
                x=tx;
                y=ty;
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (b[i][j]==1) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
                    /////////////////////////////////////         PPPPPPPPPPPPPPPPPPPPPPPPPPPPPP                  888888888888888888888888
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8   
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           PPPPPPPPPPPPPPPPPPPPPPPPPPPPPP                   88888888888888888888888 
                                    ///                           P                                               8                       8 
                                    ///                           P                                              8                         8
                                    ///                           P                                             8                           8 
                                    ///                           P                                             8                           8 
                                    ///                           P                                             8                           8
                                    ///                           P                                             8                           8
                                    ///                           P                                             8                           8
                                    ///                           P                                             8                           8
                                    ///                           P                                             8                           8
                                    ///                           P                                             8                           8
                           ///     ///                            P                                             8                           8
                            /////////                             P                                              888888888888888888888888888
*/