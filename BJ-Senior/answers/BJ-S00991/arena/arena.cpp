#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
int p=1,k=2;
int aa[10];
int a[10];
int q[10];
string s[10];
int x[5];
int ans=0;
/*struct node{
    int i;
    int nl;
}pw[10];*/
int pw[10];
int idx;
int ss;
bool zzz[20];
void jisuan(int i){
    int pp=0;
    if(i==p){
        if(!zzz[pw[1]]){
            //cout<<pw[1]<<" ";
            ss+=pw[1];
            zzz[pw[1]]=1;
        }
        return;
    }
    for(int i=1;i<=idx;i+=2){
        int c=(i+1)/2;
        int aa1=a[pw[i]],bb1=a[pw[i+1]];
        if(s[i][c]=='0'){
            if(aa1>=i) pw[++pp]=pw[i];
            else pw[++pp]=pw[i+1];
        }
        else{
            if(bb1>=i) pw[++pp]=pw[i+1];
            else pw[++pp]=pw[i];
        }
    }
    idx=pp;
    jisuan(i+1);
}
void dfs(int i){
    if(i==k+1){
        for(int i=1;i<=k;i++) pw[i]=i;
        idx=k;
        jisuan(1);
        return;
    }
    for(int j=0;j<=5;j++){
        a[i]=j;
        dfs(i+1);
        //if(pw[1]!=0) return ;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>aa[i];
    for(int i=1;i<=m;i++) cin>>q[i];
    while(k<n){
        k*=2;
        p++;
    }
    for(int i=1;i<=p;i++){
        //cout<<i<<" ";
        cin>>s[i];
        s[i]=' '+s[i];
    }
    cin>>t;
    while(t--){
        for(int i=1;i<=4;i++) cin>>x[i];
        for(int i=1;i<=n;i++){
            a[i]=aa[i]^x[i%4];
        }
        for(int i=1;i<=m;i++){
            memset(zzz,0,sizeof zzz);
            ss=0;
            dfs(q[i]+1);
            ans^=(i*ss);
            //cout<<i<<" "<<ss<<endl;
        }
        cout<<ans<<endl;
    }
    cout.flush();
    return 0;
}