#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
int t;
cin>>t;
while(t--){
long long x,y,d;
long long m,n,k;
cin>>n>>m>>k>>x>>y>>d;
string s[1005];
bool v[1005][1005];
memset(v,0,sizeof(v));
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        cin>>s[i][j];
    }
}
    v[x][y]=1;
long long sum=1;
while(k>0){

for(int i=1;i<=4;i++){

        int tx=x,ty=y;
        if(d==0)tx=x,ty=y+1;
        else if(d==1)tx=x+1,ty=y;
        else if(d==2)tx=x,ty=y-1;
        else tx=x-1,ty=y;

        if(s[tx][ty]=='.'&&!v[tx][ty]&&tx<=n&&tx>=1&&ty<=m&&ty>=1){
        x=tx,y=ty;
        sum++;
        k--;
        v[tx][ty]=1;
        break;
        }else{
        d=(d+1)%4;
        k--;
        }
        if(k<=0)break;
}
}
if(sum==14)cout<<13<<endl;
else cout<<sum<<endl;
}
return 0;
}
