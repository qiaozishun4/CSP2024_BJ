#include<bits/stdc++.h>
using namespace std;
int a[210101];
struct node{
    int x,y;
};
int l,n,k,q;
vector<node> ve[210005];
bool flag;
map<int,bool> mp[210005];
void dfs(int r,int c,int fa){
    //cout<<r<<" "<<c<<" "<<fa<<endl;
    if(r==1){
        for(int j=1;j<=n;j++){
            if(j==fa)continue;
            if(mp[j][c]==1){
                flag=1;
                break;
            }
        }
        return;
    }
    if(flag==1)return;
    //cout<<c<<" size():"<<ve[c].size()<<endl;
    for(int i=0;i<ve[c].size();i++){
        node t=ve[c][i];
        //cout<<"t.x:"<<t.x<<endl;
        if(t.x!=fa){
            dfs(r-1,t.y,t.x);
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        for(int i=1;i<=200005;i++)
        mp[i].clear();
        memset(ve,0,sizeof(ve));
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>a[j];
                for(int p=max(1,j-k+1);p<j;p++){
                    ve[a[j]].push_back(node{i,a[p]});
                }
            }
            for(int j=1;j<=l;j++){
                if(a[j]==1){
                    for(int p=min(j+1,l);p<min(j+k,l);p++){
                        mp[i][a[p]]=1;
                    }
                }
            }
        }
        while(q--){
            int r,c;
            cin>>r>>c;
            flag=0;
            dfs(r,c,0);
            if(flag==1){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
    return 0;
}
