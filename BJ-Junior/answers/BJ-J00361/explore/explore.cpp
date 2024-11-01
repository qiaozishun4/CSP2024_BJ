#include<bits/stdc++.h>
using namespace std;
vector<string> ma;
bool g[1010][1010]={};
bool check(int x,int y,int n,int m){
    if(ma[x][y]=='x'||y>=n||x>=m)
        return false;
    return true;
}
bool dfs(int n,int m,int k,int x,int y,int d){
    if(k==0){
        int cnt=0;
        for(int i=0;i<1010;i++)
            for(int j=0;j<1010;j++)
                cnt+=g[i][j];
        cout<<cnt;
        return false;
    }
    if(check(x,y,n,m)){
        g[x][y]==1;
        if(d==0)
            if(dfs(n,m,k-1,x,y+1,d))
                d++;
        if(d==1)
            if(dfs(n,m,k-1,x+1,y,d))
                d++;
        if(d==2)
            if(dfs(n,m,k-1,x,y-1,d))
                d++;
        if(d==3)
            if(dfs(n,m,k-1,x-1,y,d))
                d++;
        return 0;
    }
    else
        return true;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    int t;
    while(t--){
        while(ma.size()!=0)
            ma.pop_back();
        for(int i=0;i<1010;i++)
            for(int j=0;j<1010;j++)
                g[i][j]=false;
        int n,m,k,x,y,d;
        string temp;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=0;i<n;ma.push_back(temp),i++)
            cin>>temp;
        bool a=dfs(n-1,m-1,k,y-1,x-1,d);
    }
    return 0;
}
