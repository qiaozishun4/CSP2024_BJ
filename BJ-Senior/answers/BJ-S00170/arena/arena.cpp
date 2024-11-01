#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,m;
int aa[MAXN],a[MAXN];
int c[MAXN];
bool acc[20][MAXN];
int K;
vector<int> lef;
int cal(int now){
    if(lef.size() == 1) return lef[0];
    vector<int> lef2;
    for(int i = 0; i < lef.size(); i += 2){
        int tmp,lei,norlei;
        if(acc[now][i/2+1] == 0) tmp = a[lef[i]],lei = lef[i],norlei = lef[i+1];
        else tmp = a[lef[i+1]],lei = lef[i+1],norlei = lef[i];
        if(tmp >= now) lef2.emplace_back(lei);
        else lef2.emplace_back(norlei);
    }
    lef.clear();
    for(int v : lef2) lef.emplace_back(v);
    return cal(now+1);
}

void solve2(){
    map<int,long long> ans;
    for(int i = 1; i <= n; i *= 2){
        lef.clear();
        for(int j = 1; j <= i; j++) lef.emplace_back(j);
        int winner = cal(1);
        ans[i] = winner;
    }
    long long lstans = 0;
    for(int i = 1; i <= m; i++){
        long long tmp = ans[c[i]] * i;
        lstans = lstans ^ tmp;
    }
    printf("%lld\n",lstans);
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) scanf("%d",&aa[i]);
    for(int i = 1; i <= m; i++) scanf("%d",&c[i]);
    K = log2(n) + 1;
    for(int i = 1; i <= K; i++){
        for(int j = 1; j <= pow(2,K-i); j++){
            char tmp; cin >> tmp;
            if(tmp == '0') acc[i][j] = 0;
            else acc[i][j] = 1;
        }
    }
    int t; scanf("%d",&t);
        int x0,x1,x2,x3;
        scanf("%d%d%d%d",&x0,&x1,&x2,&x3);
        for(int i = 1; i <= n; i++){
            if(i % 4 == 1) a[i] = (aa[i] ^ x1);
            if(i % 4 == 2) a[i] = (aa[i] ^ x2);
            if(i % 4 == 3) a[i] = (aa[i] ^ x3);
            if(i % 4 == 0) a[i] = (aa[i] ^ x0);
        }
        solve2();
    return 0;
}
