#include<bits/stdc++.h>
using namespace std;
int ans,anss,x=0;
struct node{
    int d,v,e;
}a[100010];
int f[100010];
int main(){
    freorne("detect.in","r",stdin);
    freorne("detect.out","w",stdout);
    int y;
    cin>>y;
    for(int k=1;k<=y;k++){
        ans=0,anss=0,x=0;
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
            cin>>a[i].d>>a[i].v>>a[i].e;
        for(int i=1;i<=m;i++)
            cin>>f[i];
        for(int i=1;i<=n;i++){
            if(a[i].v>v){
                ans++;
                x=max(a[i].d,x);
            }
        }
        for(int i=1;i<=m;i++)
            if(f[i]>x)anss++;
        cout<<ans<<'\n'<<anss<<'\n';
    }
    return 0;
}
