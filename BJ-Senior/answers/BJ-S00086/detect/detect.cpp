#include<bits/stdc++.h>
using namespace std;
double T, n, m, l, V, ans1, ans2, d[10005], a[10005], v[10005], p[10005], lp;
int usep[10005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> T;
    while(T--){
        ans1=0;
        ans2=0;
        memset(usep,0,sizeof(usep));
        cin >> n >> m >> l >> V;
        for(int i=1;i<=n;i++){
            cin >> d[i] >> v[i] >> a[i];
        }
        for(int i=1;i<=m;i++){
            cin >> p[i];
        }
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(v[i]>=V){
                    ans1++;
                    ans2=1.0;
                }
            }
        }
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}