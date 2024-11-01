#include <bits/stdc++.h>
using namespace std;
int t,n,m,L,V,s[1000005],d[100005],v[100005],a[100005],cnt,lst,tp,ans,tmp;
pair<int,int> c[100005],pp;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--){
        cnt = ans = 0,lst = -1;
        cin >> n >> m >> L >> V;
        //if(t==19)cout << n << ' ' << m << ' ' << L << ' ' << V << '\n';
        for(int i = 0;i <= L;i++) s[i] = -0x3f3f3f3f;
        for(int i = 1;i <= n;i++) cin >> d[i] >> v[i] >> a[i];
        //if(t==19)for(int i = 1;i <= n;i++) cout << d[i] << ' ' << v[i] << ' ' << a[i] << '\n';
        for(int i = 1;i <= m;i++) cin >> tp,s[tp] = tp;//if(t == 19)cout << tp << ' ';}
        for(int i = 1;i <= L;i++) if(s[i] == -0x3f3f3f3f) s[i] = s[i - 1];
        for(int i = 1;i <= n;i++){
            if(a[i] == 0){
                if(v[i] > V){
                    pp.first = s[L];
                    pp.second = d[i];
                }else continue;
            }else if(a[i] > 0){
                pp.first = s[L];
                tmp = (V * V - v[i] * v[i]) / a[i] / 2;
                if(tmp < 0) pp.second = d[i];
                else pp.second = tmp + 1 + d[i];
            }else{
                if(v[i] <= V) continue;
                tmp = (V * V - v[i] * v[i]) / a[i] / 2;
                if(tmp * a[i] * 2 == V * V - v[i] * v[i]) tmp--;
                pp.first = s[min(tmp + d[i],L)];
                pp.second = d[i];
            }
            //cout << pp.first << '*' << pp.second << ' ';
            if(pp.first >= pp.second) c[++cnt] = pp;
        }
        cout << cnt << ' ';
        sort(c + 1,c + cnt + 1);
        for(int i = 1;i <= cnt;i++){
            if(c[i].second <= lst) continue;
            //cout << i << '/' << c[i].first << '/' << c[i].second << ' ';
            ans++;
            lst = c[i].first;
        }
        cout << m - ans << '\n';
    }
    return 0;
}
