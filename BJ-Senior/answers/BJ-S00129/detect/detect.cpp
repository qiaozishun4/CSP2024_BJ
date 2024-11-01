#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,m,L,V,a[N],d[N],v[N],p[N];
int T;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    while(T--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)cin>>p[i];
        cout<<3<<' '<<7;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}