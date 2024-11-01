#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+5;
int n,m,k;
int a[N],c[N];
string s[205];
int T;
int x[4];

vector<int> v[N];

ll ans[N];
void dfs(int l,int r,int cur,int id){
    //cout<<l<<' '<<r<<endl;
    if(l==r){
        ll sum=0;
        for(int i=0;i<v[1].size();i++){
            sum+=v[1][i];
        }
        ans[id]=sum;
        return ;
    }
    for(int i=1;i<=r/2;i++){
        int d=s[cur][i]-'0';
        if(d==0){
            vector<int> vec;
            bool flag=0;
            for(int j=0;j<v[(i-1)*2+1].size();j++){
                if(v[(i-1)*2+1][j]>c[id]){
                    vec.push_back(v[(i-1)*2+1][j]);
                    flag=1;
                }
                else if(a[v[(i-1)*2+1][j]]>=cur){
                    vec.push_back(v[(i-1)*2+1][j]);
                }
                else if(a[v[(i-1)*2+1][j]]<cur) flag=1;
            }
            if(flag==1){
                for(int j=0;j<v[i*2].size();j++){
                    vec.push_back(v[i*2][j]);
                }
            }
            v[i]=vec;
        }
        else{
            vector<int> vec;
            bool flag=0;
            for(int j=0;j<v[i*2].size();j++){
                if(v[i*2][j]>c[id]){
                    vec.push_back(v[i*2][j]);
                    flag=1;
                }
                else if(a[v[i*2][j]]>=cur){
                    vec.push_back(v[i*2][j]);
                }
                else if(a[v[i*2][j]]<cur) flag=1;
            }
            if(flag==1){
                for(int j=0;j<v[(i-1)*2+1].size();j++){
                    vec.push_back(v[(i-1)*2+1][j]);
                }
            }
            v[i]=vec;
        }
    }
    dfs(l,r/2,cur+1,id);
}

int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    k=log2(n);
    if((1<<k)<n) k++;
    for(int i=1;i<=k;i++) cin>>s[i];
    for(int i=1;i<=k;i++) s[i]='&'+s[i];
    cin>>T;
    while(T--){
        for(int i=0;i<4;i++) cin>>x[i];
        for(int i=1;i<=n;i++){
            a[i]=a[i]^x[i%4];
        }
        for(int i=1;i<=m;i++){
            if(c[i]==1){
                ans[i]=1;
                continue;
            }
            k=log2(c[i]);
            if((1<<k)<c[i]) k++;
            for(int i=1;i<=(1<<k);i++){
                v[i].clear();
                v[i].push_back(i);
            }
            dfs(1,(1<<k),1,i);
        }
        ll ANS=0;
        for(int i=1;i<=m;i++){
            ANS=ANS^(ll)((ll)i*ans[i]);
        }
        cout<<ANS<<endl;
        for(int i=1;i<=n;i++){
            a[i]=a[i]^x[i%4];
        }
    }
    return 0;
}