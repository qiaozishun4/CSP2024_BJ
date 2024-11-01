#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        map<int,int> mp[10];
        int n,m,k,x,y,d,s=1;
        cin>>n>>m>>k>>x>>y>>d;
        mp[t][x*10+y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        while(k--){
            int fx=x+dx[d];
            int fy=y+dy[d];
            if(fx>=1 and fx<=n and fy>=1 and fy<=m and a[fx][fy]=='.'){
                x=fx;
                y=fy;
                if(!mp[t].count(x*10+y)){
                    mp[t][x*10+y]=1;
                    s++;
                }
            }else{
                d++;
                d=d%4;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}