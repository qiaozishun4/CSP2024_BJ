#include<bits/stdc++.h>
using namespace std;
int n,m,T,K;
long long a[100001],b[100001];
int q[100001];
int len[100001];
bool d[20][50001];
long long ans[20][100001],an;
vector<int>v[20][100001];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=m;++i) cin>>q[i];
    for(int i=2;i<=n;++i) len[i]=len[i/2]+1;
    K=len[n];
    for(int i=1;i<=K;++i){
        int u=pow(2,K-i);
        for(int j=1;j<=u;++j) cin>>d[i][j];
    }
    cin>>T;
    while(T--){
        int x[4];
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;++i){
            b[i]=a[i]^x[i%4];
            ans[0][i]=b[i];
            v[0][i].push_back(b[i]);
        }
        for(int i=1;i<=K;++i){
            int u=pow(2,K-i);
            for(int j=1;j<=u;++j){
                int l=u*2,r=u*2+1,z=i-1;
                sort(v[z][l].begin(),v[z][l].end());
                sort(v[z][r].begin(),v[z][r].end());
                if(d[i][j]==0){
                    int tmp=v[z][l][0];
                    int len=v[z][r].size();
                    if(tmp<i)
                    for(int u=len;u>=0;--u){
                        if(v[z][r][u]<tmp) break;
                        ans[i][j]+=v[z][r][u];
                        v[i][j].push_back(v[z][r][u]);
                    }
                    tmp=v[z][r][0];
                    len=v[z][l].size();
                    if(tmp<i)
                    for(int u=len;u>=0;--u){
                        if(v[z][l][u]<tmp) break;
                        ans[i][j]+=v[z][l][u];
                        v[i][j].push_back(v[z][l][u]);
                    }
                    vector<int>().swap(v[z][l]);
                    vector<int>().swap(v[z][r]);
                }
                else{
                    int t=lower_bound(v[z][l].begin(),v[z][l].end(),i)-v[z][l].begin();
                    int len=v[z][r].size(),tmp;
                    bool f=1;
                    if(v[z][l][t]>=r){
                        if(t==0||v[z][l][t-1]>=r) f=0;
                        else tmp=v[z][l][t-1];
                    }
                    else tmp=v[z][l][t];
                    if(f)
                    for(int u=len;u>=0;--u){
                        if(v[z][r][u]>tmp) break;
                        ans[i][j]+=v[z][r][u];
                        v[i][j].push_back(v[z][r][u]);
                    }
                    t=lower_bound(v[z][r].begin(),v[z][r].end(),i)-v[z][r].begin();
                    len=v[z][l].size();
                    f=1;
                    if(v[z][r][t]>=r){
                        if(t==0||v[z][l][t-1]>=r) f=0;
                        else tmp=v[z][r][t-1];
                    }
                    else tmp=v[z][r][t];
                    if(f)
                    for(int u=len;u>=0;--u){
                        if(v[z][l][u]>tmp) break;
                        ans[i][j]+=v[z][l][u];
                        v[i][j].push_back(v[z][l][u]);
                    }
                    vector<int>().swap(v[z][l]);
                    vector<int>().swap(v[z][r]);
                }
            }
        }
        vector<int>().swap(v[K][1]);
        for(int i=1;i<=m;++i){
            int c=q[i];
            an^=ans[len[c]][1];
        }
        cout<<an<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
