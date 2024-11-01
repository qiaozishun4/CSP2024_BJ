#include<bits/stdc++.h>
using namespace std;
int t,n,m,d,k,x,y;
int a[1003][1003];
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int z=1;z<=t;z++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        char c;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c;
                if(c=='.') a[i][j]=0;
                else a[i][j]=-1;
            }
        }
        long long ans=0;
        a[x][y]=1;
        while(k>0){
            if(a[x+dx[d]][y+dy[d]] == -1 || x+dx[d]>n || y+dy[d]>m || x+dx[d]<1 || y+dy[d]<1){
                k--;
                d=(d+1)%4;
            }
            else{
                k--;
                x+=dx[d];
                y+=dy[d];
                a[x][y]=1;
//                cout<<x<<" "<<y<<endl;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==1) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

