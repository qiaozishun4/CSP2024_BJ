#include <bits/stdc++.h>
using namespace std;

int d[100010], vi[100010], p[100010], a[100010];

double ct(int i,int m){
    return sqrt((p[m]-d[i])*2*a[i]+pow(vi[i],2));
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n, m, l, v, ans = 0;
        cin >> n >> m >> l >> v;
        for(int i = 1;i <= n;i++){
            cin >> d[i];
            cin >> vi[i];
            cin >> a[i];
        }
        for(int i = 1;i <= m;i++){
            cin >> p[i];
        }
        for(int i = 1;i <= n;i++){
            if(a[i]==0){
                if(d[i]<=p[m]&&vi[i]>v){
                    ans++;
                }
            }
            else if(a[i]>0){
                if(d[i]<=p[m]&&ct(i,m)>v){
                    ans++;
                }
            }
        }
        if(ans==0)cout << ans << " " << m << "\n";
        else cout << ans << " " << m-1 << "\n";
    }
    return 0;
}