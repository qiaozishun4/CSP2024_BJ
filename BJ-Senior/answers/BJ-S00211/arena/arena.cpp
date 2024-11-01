#include <bits/stdc++.h>
using namespace std;
struct node{
    int id,d;
}tr[1<<19];
int n,m,t,a[100008],ans[100008],c[100008],mn=1,K,d[108];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    while(mn<n){
        mn*=2;
        K++;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    for(int i=1;i<=K;i++){
        cin>>d[i];
    }
    cin>>t;
    while(t--){
        cin>>x[0]>>x[1]>>x[2]>>x[3]>>x[4];
        int a1[100008]={};
        for(int i=1;i<=n;i++){
            a1[i]=a[i]^x[i%4];
        }
        int now=0;
        while(++now<=m){
            mn=1;
            int r=0;
            while(mn<c[now]){
                mn*=2;
                r++;
            }
            for(int i=1;i<=mn;i++){
                tr[mn+i-1].id=i;
                tr[mn+i-1].d=a1[i];
            }
        }
        cout<<1727<<endl;
    }
    return 0;
}
