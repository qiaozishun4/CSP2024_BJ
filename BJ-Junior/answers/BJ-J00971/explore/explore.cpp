#include <bits/stdc++.h>
using namespace std;
char mp[2000][2000];
int dis[4][2]={0,1,0,-1,1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        for(int j=0;j<=1000;j++){
            for(int k=0;k<=1000;k++){
                mp[i][j]='x';
            }
        }
        int sum=1;
        int xn,yn;
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;

        for(int i=1;i<=n;i++){
            cin>>mp[i];
        }
        for(int i=0;i<k;i++){
            xn=x+dis[d][0];
            yn=y+dis[d][1];
            if(yn<=m&&yn>=1&&xn<=n&&xn>=1&&mp[xn][yn]=='.'){
                x=xn;
                y=yn;
                sum++;
                
            }
            else{
                d++;
                d=d%4;
            }
        }
        cout<<sum<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
