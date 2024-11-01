#include<bits/stdc++.h>
using namespace std;
int n,t,k,p,x,y,f[111][200005],l;
map<int,int>m;
vector<int>v[100005];
int dfs(int x,int l,int b){
    if(!x)return l==y;
    for(int i=0;i<n;i++){
        if(i==b)continue;
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]-x)continue;
            for(int p=1;p<=k;p++){
                if(f[x][v[i][j+p+1]])continue;
                f[x][v[i][j+p+1]]=!(dfs(x-1,v[i][j+p+1],i));
                if(!f[x][v[i][j+p+1]])return 1;
            }
        }
    }
    return 0;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>p;
        for(int i=0;i<n;i++){
            v[i].clear();
            cin>>l;
            while(l--){
                cin>>x;
                v[i].push_back(x);
                m[x]=1;
            }
        }
        while(p--){
            cin>>x>>y;
            memset(f,0,sizeof f);
            if(!m[y]){
                cout<<0<<'\n';
                continue;
            }
            cout<<!dfs(x,1,n)<<'\n';
        }
    }
    return 0;
}