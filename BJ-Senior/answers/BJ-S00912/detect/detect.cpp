#include<bits/stdc++.h>
using namespace std;
int t,n,m,L,V,d[100010],v[100010],a[100010],p[100010];
int su,jian;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    for(int l=1;l<=t;l++){
        cin >> n >> m >> L >> V;
        for(int i=1;i<=n;i++){
            cin >> d[i] >> v[i] >> a[i];
            if((L-d[i])*a[i]+v[i] > V){
                su++;
            }
        }
        for(int i=1;i<=m;i++){
            cin >> p[i];
            if((L-d[i])*a[i]+v[i] < p[i]){
                jian++;
            }
        }
        cout << su << " " << jian << endl;
        su = 0;
        jian = 0;
    }
    return 0;
}
