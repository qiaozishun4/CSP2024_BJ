#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int d[100005],v[100005],a[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int ans=-0x3f3f3f3f;
        int cnt=0;
        int n,m,l,v1;
        cin >> n >> m >> l >> v1;
        for(int i=0;i<n;i++){
            cin >> d[i] >> v[i] >> a[i];
        }
        for(int i=0;i<m;i++){
            int p;
            cin >> p;
            ans=max(ans,p);
        }
        for(int i=0;i<n;i++){
            if(d[i]<=ans&&v[i]>v1){
                cnt++;
            }
        }
        cout << cnt << " " << m-1 << endl;
    }
    return 0;
}