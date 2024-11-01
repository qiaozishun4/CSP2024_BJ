#include<stdio.h>
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int m,n,k,x,y,d,ans=0;
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        char map[n][m];
        for(int j=0;j<n;j++)scanf("%s",map[j]);
        map[x-1][y-1]='@';
        for(int j=0;j<k;j++){
            if(d==0){
                if(1<=y+1&&y+1<=m&&map[x-1][y]=='.'||map[x-1][y]=='@'){y++;
                    map[x-1][y-1]='@';

                }
                else d=(d+1)%4;
            }
            else if(d==1){
                if(1<=x+1&&x+1<=m&&map[x][y-1]=='.'||map[x][y-1]=='@'){x++;
                    map[x-1][y-1]='@';

                }
                else d=(d+1)%4;
            }
            else if(d==2){
                if(1<=y-1&&y-1<=m&&map[x-1][y-2]=='.'||map[x-1][y-2]=='@'){y--;
                    map[x-1][y-1]='@';

                }
                else d=(d+1)%4;
            }
            else{
                if(1<=x-1&&x-1<=m&&map[x-2][y-1]=='.'||map[x-2][y-1]=='@'){x--;
                    map[x-1][y-1]='@';

                }
                else d=(d+1)%4;
            }
        }
        for(int j=0;j<n;j++)for(int g=0;g<m;g++)if(map[j][g]=='@')ans++;
        printf("%d\n",ans);
    }
    return 0;
}