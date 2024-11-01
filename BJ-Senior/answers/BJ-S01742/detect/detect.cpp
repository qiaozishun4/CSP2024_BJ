#include<bits/stdc++.h>
using namespace std;
int n,m,l,u;
int a[100001],p[100001],d[100001],v[100001];
int main(){
    int t;
    freopen("detect.in","r",stdin);
    freopen("detect.out","w".stdout);
    cin>>t;
    while(t--){
        int cnt=0,maxv,ans;
        cin>>n>>m>>l>>u;
        for (int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if (v[i]>u)cnt++;
            maxv=max(d[i],maxv);
        }
        int maxn=0;
        for (int i=1;i<=m;i++){
            cin>>p[i];
            maxn=max(maxn,p[i]);
        }
        cout<<cnt<<" ";
        cout<<m-1<<endl;
    }
    return 0;
}
