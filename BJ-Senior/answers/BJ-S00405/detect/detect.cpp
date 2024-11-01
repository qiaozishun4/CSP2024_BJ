#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,V;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int cnt = 0,d[100005],v[100005],a[100005],p[100005];
        scanf("%d",&n);
        scanf("%d",&m);
        scanf("%d",&l);
        scanf("%d",&V);
        for(int i = 1;i <= n;i++){
            scanf("%d",&d[i]);
            scanf("%d",&v[i]);
            scanf("%d",&a[i]);
        }
        for(int i = 1;i <= m;i++){
            scanf("%d",&p[i]);
        }
        for(int i = 1;i <= n;i++){
            if(v[i] > V && p[m] > d[i]){
                cnt++;
            }
        }
        cout << cnt << " " << m - 1 << "\n";
    }
    return 0;
}