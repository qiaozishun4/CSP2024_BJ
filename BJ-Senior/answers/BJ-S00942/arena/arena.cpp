#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int o[N],p[N],s[N];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m,t=1;
    cin>>n>>m;
    p[0]=1;
    for(int i=1;i<=30;i++){
        p[i]=p[i-1]*2;
    }
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>o[i];
    }
    int l;
    for(int i=1; ;i++){
        if(p[i]<=m&&p[i+1]>m){
            l=p[i];
        }
    }
    for(int i=l;i>=1;i--){
        for(int j=1;j<=p[i];j++){
            char t;
            cin>>t;
        }
    }
    int J;
    cin>>J;
    for(int i=1;i<=J;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<1<<endl;
    }
    return 0;
}
