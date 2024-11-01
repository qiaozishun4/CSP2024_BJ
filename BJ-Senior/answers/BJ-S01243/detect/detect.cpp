#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int t, n, m, l, vv, ans;
int p[3005], a[3005];
int d[3005], v[3005];

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin>>t;
    for(int h=1;h<=t;h++){
        cin>>n>>m>>l>>vv;
        for(int i=1;i<=n;i++)
            cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)
            cin>>p[i];
        sort(p+1, p+m+1); ans=0;
        for(int i=1;i<=n;i++)
            if(v[i]>vv){
                int q=lower_bound(p+1, p+m+1, d[i])-p;
                if(q!=m+1) ans++;
            }
        cout<<ans<<' '<<m-1<<endl;
    }
    return 0;
}
