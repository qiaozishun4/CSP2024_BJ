#include <bits/stdc++.h>
using namespace std;
int a[100000][3], b[100000], c[100000][2], d[100000];
int get_int(double n){
    if (int(n) == n) return n;
    return n+1;
}
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    for (int i=0; i<T; ++i){
        int n, m, l, v, c_at=0, ans1=0;
        cin >> n >> m >> l >> v;
        for (int j=0; j<n; ++j)
            cin >> a[j][0] >> a[j][1] >> a[j][2];
        for (int j=0; j<m; ++j)
            cin >> b[j];
        for (int j=0; j<n; ++j)
            if (a[j][1] > v || (a[j][2]!=0 && sqrt(a[j][1]*a[j][1]+2*a[j][2]*(l-a[j][0])) > v)){
                if (a[j][2] > 0){
                    int start=get_int(double(a[j][1]*a[j][1]-v*v)/2*a[j][2])+a[j][0];
                    if (b[m-1] >= start){
                        ++ans1;
                        c[c_at][0] = start;
                        c[c_at][1] = l;
                        ++c_at;
                    }
                }
                if (a[j][2] == 0){
                    if (b[m-1]>a[j][0]){
                        ++ans1;
                        c[c_at][0] = a[j][0];
                        c[c_at][1] = l;
                        ++c_at;
                    }
                }
                if (a[j][2] < 0){
                    if (a[j][0] > b[m-1]) continue;
                    int end1=int(double(v*v-a[j][1]*a[j][1])/2*a[j][2])+a[j][0];
                    bool have=0;
                    int s=0, e=m;
                    while(s<e){
                        int mid=(s+e)/2;
                        if (mid==a[j][0]){
                            have = 1;
                            break;
                        }
                        if (mid<a[j][0])
                            s=mid+1;
                        if (mid>a[j][0])
                            e=mid-1;
                    }
                    if (have || end1<=b[e+1]){
                        ++ans1;
                        c[c_at][0] = a[j][0];
                        c[c_at][1] = end1;
                        ++c_at;
                    }
                }
            }
        cout << ans1 << ' ' << m/2 << endl;
    }
    return 0;
}
