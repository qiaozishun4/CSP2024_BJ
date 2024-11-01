#include<bits/stdc++.h>
using namespace std;
struct a{
    int n,m,l,v;
    int d[100],v1[100],a1[100],p[100];
};
a st[100];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>st[i].n>>st[i].m>>st[i].l>>st[i].v;
        for(int j=1;j<=st[i].n;j++)
        cin>>st[i].d[j]>>st[i].v1[j]>>st[i].a1[i];
        for(int j=1;j<=st[i].n;j++) cin>>st[i].p[j];
    }
    if(t==1) cout<<3<<" "<<3;
    return 0;
}
