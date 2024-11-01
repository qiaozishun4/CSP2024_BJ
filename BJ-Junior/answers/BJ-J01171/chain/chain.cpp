#include<bits/stdc++.h>
using namespace std;
int t,n,k,q;
vector<int>v[100005],c[100005],l[100005];
int p[200005],m[200005];
bool ans[105][200005];
signed main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int len;cin>>len;
            while(len--){
                int tmp;cin>>tmp;
                v[i].push_back(tmp);
                c[i].push_back(0);
                if(tmp!=1)l[i].push_back(0);
                else l[i].push_back(k);
            }
        }

        for(int r=0;r<=100;r++){
            for(int i=1;i<=n;i++){
                for(int j=0;j<v[i].size();j++){
                    if(c[i][j])p[v[i][j]]++;
                }
            }
            for(int i=1;i<=200000;i++){
                ans[r][i]=!!p[i];
            }
            for(int i=1;i<=n;i++){
                for(int j=0;j<v[i].size();j++){
                    m[v[i][j]]+=c[i][j];
                }
                for(int j=0;j<v[i].size();j++){
                    if(p[v[i][j]]-m[v[i][j]]){
                        l[i][j]=k;
                    }
                }
                for(int j=0;j<v[i].size();j++){
                    if(c[i][j]==1){
                        m[v[i][j]]--;
                    }
                }
                for(int j=0;j<v[i].size();j++){
                    if(j==0){
                        if(l[i][j]!=k&&l[i][j]>0)c[i][j]=1;
                        else c[i][j]=0;
                        continue;
                    }
                    l[i][j]=max(l[i][j],l[i][j-1]-1);
                    if((l[i][j]!=k&&l[i][j]>0)||l[i][j-1]>1)c[i][j]=1;
                    else c[i][j]=0;
                }
                for(int j=0;j<v[i].size();j++){
                    l[i][j]=0;
                }
            }
            memset(p,0,sizeof(p));
        }
        while(q--){
            int tmp1,tmp2;cin>>tmp1>>tmp2;
            cout<<ans[tmp1][tmp2]<<'\n';
        }
        for(int i=1;i<=n;i++){
            while(v[i].size())v[i].pop_back(),c[i].pop_back(),l[i].pop_back();
        }
    }
    return 0;
}
