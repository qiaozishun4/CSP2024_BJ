#include<bits/stdc++.h>
//#define int long long
using namespace std;

int n,m,t;
int a[100010],c[100010],b[100010];
string ss[20];

int solve(int k,int dep,vector<int> now){
    if(dep>log2(c[k])){
        return now[1];
    }
    vector<int> newv(n);
    for(int i=2;i<=c[k];i+=2){
        if(ss[dep][i/2-1]=='0'){
            if(b[now[i-1]]>=i/2){
                newv[i/2]=now[i-1];
            }
            else{
                newv[i/2]=now[i];
            }
        }
        else{
            if(b[now[i]]>=i/2){
                newv[i/2]=now[i];
            }
            else{
                newv[i/2]=now[i-1];
            }
        }
    }
    return solve(k,dep+1,newv);
}

signed main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    int lg2=log2(n);
    if(pow(2,lg2)==n){
        for(int i=1;i<=lg2;i++){
            cin>>ss[i];
        }
    }
    else{
        for(int i=1;i<=lg2+1;i++){
            cin>>ss[i];
        }
    }
    cin>>t;
    for(int i=1;i<=t;i++){
        int x[4];
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int j=1;j<=n;j++){
            b[j]=a[j]^x[i%4];
        }
        int ans=0;
        for(int k=1;k<=m;k++){
            vector<int> vct(c[k]+1);
            for(int i=1;i<=c[k];i++){
                vct[i]=i;
            }
            ans^=(k*solve(k,1,vct));
        }
        cout<<ans<<'\n';
    }

    return 0;
}
