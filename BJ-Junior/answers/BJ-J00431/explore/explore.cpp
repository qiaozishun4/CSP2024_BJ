#include <bits/stdc++.h>
using namespace std;
char v[1050][1050];
int dre_x[4]={0,1,0,-1},dre_y[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int xs=1;xs<=t;xs++){
        int n,m,k,x,y,d,ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int xs1=1;xs1<=n;xs1++){
            for(int xs2=1;xs2<=m;xs2++){
                cin>>v[xs1][xs2];
            }
        }
        for(int xs1=0;xs1<=k;xs1++){
            if(v[x][y]!='l')ans++;
            v[x][y]='l';
            int xl=x+dre_x[d],yl=y+dre_y[d];
            if(xl>0&&xl<=n&&yl>0&&yl<=m&&v[xl][yl]!='x'){
                x+=dre_x[d];
                y+=dre_y[d];
            }else{
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
