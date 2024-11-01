#include<bits/stdc++.h>
using namespace std;
char mp[1007][1007];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct node{
    long long x,y;
}l,r;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long t,n,m,k,x,y,d,cnt=0;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }


        queue<node>q;

        q.push({x,y});
        while(!q.empty()){
            r=q.front();
            q.pop();
            mp[r.x][r.y]='x';
            l.x=r.x+dir[d][0];
            l.y=r.y+dir[d][1];
            if(l.x<=n && l.x>0 && l.y<=m && l.y>0 && mp[l.x][l.y]=='.'){
                q.push(l);
                cnt++;
            }else{
                int i;
                for(i=0;i<4;i++){
                    if(mp[r.x+dir[i][0]][r.y+dir[i][1]]=='.')break;
                }
                if(i==4){
                    break;
                }
                d=(d+1)%4;
                q.push(r);
            }k--;
            if(k==0)break;

        }cout<<cnt<<endl;
        cnt=0;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}