#include<bits/stdc++.h>
using namespace std;
long long x,y,d,n,t,m,k;
char a[10005][10005];
long long v[10005][10005];
int main(){
    cin>>t;
    freopen(explore,"r",stdin);
    freopen(explore,"w",stdout);
    for(int guang=1;guang<=t;guang++){
        memset(v,0,sizeof(v));
        long long num=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        v[x][y]=1;
        for(int i=1;i<=k;i++)
            if(d==0)
                if(a[x][y+1]=='.'){
                    y++;
                    if(v[x][y]==0){
                        num++;
                        v[x][y]=1;
                    }
                }
                else{
                    d++;
                }
            else if(d==1)
                if(a[x+1][y]=='.'){
                    x++;
                    if(v[x][y]==0){
                        num++;
                        v[x][y]=1;
                    }
                }
                else{
                    d++;
                }
            else if(d==2)
                if(a[x][y-1]=='.'){
                    y--;
                    if(v[x][y]==0){
                        num++;
                        v[x][y]=1;
                    }
                }
                else{
                    d++;
                }
            else if(d==3)
                if(a[x-1][y]=='.'){
                    x--;
                    if(v[x][y]==0){
                        num++;
                        v[x][y]=1;
                    }
                }
                else{
                    d=0;
                }
        cout<<num<<endl;
    }
    return 0;
}