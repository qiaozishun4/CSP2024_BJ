#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        bool b[1003][1003]={false};
        bool p[1003][1003]={false};
        int n,m,k,x,y,d,s=1;
        cin>>n>>m>>k>>x>>y>>d;
        p[x][y]=true;
        for(int i=1;i<=n;i++){
            getchar();
            for(int j=1;j<=m;j++)
                b[i][j]=(getchar()=='.');
        }
        while(k--){
            int xp=x,yp=y;
            if(d==0)
                yp++;
            if(d==1)
                xp++;
            if(d==2)
                yp--;
            if(d==3)
                xp--;
            if(b[xp][yp]){
                x=xp;
                y=yp;
                if(!p[x][y]){
                    s++;
                    p[x][y]=true;
                }
            }
            else
                d=(d+1)%4;
        }
        cout<<s<<'\n';
    }
    return 0;
}
