#include<iostream>
#include<cstdio>
using namespace std;
int T,map[1005][1005],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int tim=0;tim<T;tim++){
        int n,m,k,x,y,d,cnt=1;
        cin>>n>>m>>k>>x>>y>>d;
        x--;y--;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char a;
                cin>>a;
                if(a=='x') map[i][j]=0;
                else map[i][j]=1;
            }
        }
        map[x][y]=2;
        for(int i=0;i<k;i++){
            if(map[x+dx[d]][y+dy[d]]){
                x=x+dx[d];
                y=y+dy[d];
                if(map[x][y]==1){
                    map[x][y]=2;
                    cnt++;
                }
            }else d=(d+1)%4;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
