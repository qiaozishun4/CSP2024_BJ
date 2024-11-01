#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 100005;
int t,n,m,len,vlim,n2,sl[maxn],sr[maxn],n3,chk[maxn];
pair<int,int> req[maxn];
int sceil(int a, int b) {
    if(a%b == 0) return a/b;
    return a/b+1;
}
signed main () {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld%lld%lld%lld",&n,&m,&len,&vlim);
        n2 = 0;
        n3 = 0;
        for(int i = 0; i < n; i++) {
            int pos,vel,acc;
            scanf("%lld%lld%lld",&pos,&vel,&acc);
            if(acc > 0) {
                if(vel > vlim) {
                    sl[n2] = pos;
                    sr[n2] = len;
                    n2++;
                    continue;
                }
                int dst2 = pos+sceil(vlim*vlim-vel*vel,(((long long) 2)*acc));
                if(dst2 > len) continue;
                sl[n2] = dst2;
                sr[n2] = len;
                n2++;
            }
            else if(acc == 0) {
                if(vel <= vlim) continue;
                sl[n2] = pos;
                sr[n2] = len;
                n2++;
            }
            else {
                if(vel <= vlim) continue;
                int dst2 = pos+(vlim*vlim-vel*vel)/(((long long) 2)*acc);
                if(pos > min(dst2,len)) continue;
                sl[n2] = pos;
                sr[n2] = min(dst2,len);
                n2++;
            }
        }
        for(int i = 0; i < m; i++) {
            scanf("%lld",&chk[i]);
        }
        for(int i = 0; i < n2; i++) {
            int newl = lower_bound(chk,chk+m,sl[i])-chk;
            int newr = upper_bound(chk,chk+m,sr[i])-chk-1;
            if(newl <= newr) {
                req[n3].first = newl;
                req[n3].second = newr;
                n3++;
            }
        }
        if(n3 == 0) {
            printf("0 %lld\n",m);
            continue;
        }
        sort(req,req+n3);
        int ans = m-1;
        int cl = req[0].first, cr = req[0].second;
        for(int i = 1; i < n3; i++) {
            if(req[i].first <= cr) {
                cl = req[i].first;
                cr = min(cr,req[i].second);
            }
            else {
                ans--;
                cl = req[i].first;
                cr = req[i].second;
            }
        }
        printf("%lld %lld\n",n3,ans);
    }
    return 0;
}