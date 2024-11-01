#include<bits/stdc++.h>
using namespace std;
char nmmap[1011][1011]={};
int dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}},d=0;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int iii=0;iii<t;iii++){
        int n,m,k;
        unordered_set<int> step;
        cin>>n>>m>>k;
        int x,y;
        cin>>x>>y>>d;
        --x;
        --y;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>nmmap[i][j];
            }
        }
        step.insert(x*n+y);
        for(int s=0;s<k;s++){
            int nx=x+dis[d][0],ny=y+dis[d][1];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&nmmap[nx][ny]=='.'){
                x=nx;
                y=ny;
                step.insert(x*n+y);
            }
            else{
                d=(d+1)%4;
            }
        }
        cout<<step.size();
        if(iii<t-1) cout<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
