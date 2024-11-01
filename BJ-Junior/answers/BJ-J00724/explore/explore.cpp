#include <iostream>
using namespace std;
char map_[1024][1024];
int n,m;

bool check(int x,int y){
    return (x>=1&&x<=n&&y>=1&&y<=m&&map_[x][y]!='x');
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int ans=1;
        int k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>map_[i][j];
        for(int i=0;i<k;i++){
            int next_x,next_y;
            if(d==0){
                next_x=x;
                next_y=y+1;
            }
            else if(d==1){
                next_x=x+1;
                next_y=y;
            }
            else if(d==2){
                next_x=x;
                next_y=y-1;
            }
            else if(d==3){
                next_x=x-1;
                next_y=y;
            }
            if(check(next_x,next_y)){
                x=next_x;
                y=next_y;
                if(map_[x][y]=='.'){
                    ans++;
                    map_[x][y]='*';

                }
            }
            else{
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
