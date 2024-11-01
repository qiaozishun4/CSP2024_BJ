#include<iostream>
#include<set>
#include<utility>
#include<cstdio>
using namespace std;
int t,n,m,k,x,y,d,ans;
set<pair<int,int> > s;
char mp[1005][1005];
int newX(int x,int d){
    if(d==1) return x+1;
    if(d==3) return x-1;
    else return x;
}
int newY(int y,int d){
    if(d==0) return y+1;
    if(d==2) return y-1;
    else return y;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        ans=1;
        s.clear();
        s.insert({x,y});
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>mp[i][j];
        while(k--){
            int x1=newX(x,d),y1=newY(y,d);
            if(1<=x1 and x1<=n and 1<=y1 and y1<=m and mp[x1][y1]=='.'){
                x=x1,y=y1;
                if(s.find({x,y})==s.end()){
                    ans++;
                    s.insert({x,y});
                }
            }else d=(d+1)%4;
        }
        cout<<ans<<endl;
    }
    return 0;
}