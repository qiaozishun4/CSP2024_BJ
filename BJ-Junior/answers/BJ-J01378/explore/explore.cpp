#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n,m,k,x,y,x1,y1,d,i,j,op,opop,ans;
    bool a[1001][1001],b[1001][1001];
    string s;
    cin>>op;
    for(opop=0;opop<op;opop++){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cin>>n>>m>>k>>x>>y>>d;
        ans=1;x--;y--;
        b[x][y]=1;
        for(i=0;i<n;i++){
            cin>>s;
            for(j=0;j<m;j++){
                if(s[j]=='x')a[i][j]=1;
            }
        }
        for(i=0;i<k;i++){
            x1=x,y1=y;
            if(d==0)y1++;
            else if(d==1)x1++;
            else if(d==2)y1--;
            else if(d==3)x1--;
            if(x1<0 || y1<0 || x1>=n || y1>=m)d=(d+1)%4;
            else if(a[x1][y1]==1)d=(d+1)%4;
            else{
                x=x1;y=y1;
                if(b[x][y]==0){
                    b[x][y]=1;
                    ans++;
                }
            }
        }cout<<ans<<endl;
    }
}
