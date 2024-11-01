#include<bits/stdc++.h>
using namespace std;
long long n,m,k,v;
struct node{
    long long d,a,v;
}s[100005];
int next_[1000005];
int p[1000005];
int check(long long d,long long v0,long long a,long long ed){
    long long sss = ed - d;
    if(sss < 0) return 1;
    long long v1 = v0 * v0 + 2 * a * sss;
    if(v1 <= v * v) return 1;
    return 0;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int ans1 = 0;
        cin >> n >> m >> k >> v;
        int ans2 = m;
        for(int i = 1;i <= n;i++){
            cin >> s[i].d >> s[i].v >> s[i].a;
        }
        for(int i = 1;i <= m;i++){
            cin >> p[i];
        }
        sort(p + 1,p + 1 + m);
        for(int i = 1;i <= k;i++){
            next_[i] = 1e7;
        }
        for(int i = 1;i <= m;i++){
            next_[p[i]] = i;
        }
        for(int i = k;i >= 1;i--){
            next_[i] = min(next_[i],next_[i + 1]);
        }
        for(int i = 1;i <= n;i++){
            if(next_[s[i].d] == 1e7) continue;
            int flag = check(s[i].d,s[i].v,s[i].a,p[m]);
            if(!flag) ans1++;
        }
        if(ans1) ans2--;
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
