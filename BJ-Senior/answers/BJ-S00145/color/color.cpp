#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, a[200010];
ll cnt[1000010];
bool color[200010];
ll lstpos[1000010];
ll ans;

ll calc() {
    ll result = 0;
    ll lstr=-1, lstb=-1;
    for(int i=1;i<=n;i++) {
        if(color[i]&&lstr==a[i]) result+=a[i];
        if(!color[i]&&lstb==a[i]) result+=a[i];
        if(color[i]) lstr=a[i];
        else lstb=a[i];
    }
    return result;
}

void bruteforce_O_2_pow_n(ll i) {
    if(i==n+1) {
        ans = max(ans, calc());
        return;
    }
    color[i]=1;
    bruteforce_O_2_pow_n(i+1);
    color[i]=0;
    bruteforce_O_2_pow_n(i+1);
}

ll prankpts1() {
    if(n>2000) return 0;
    ll res = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(color, 0, sizeof(color));
    for(int i=1;i<=n;i++) {
        cnt[a[i]]++;
    }
    for(int i=2000;i>=1;i--) {
        for(int j=1;j<=n;j++) {
            if(a[j]==i) color[j]=1;
        }
        res = max(res, calc());
        for(int j=1;j<=n;j++) {
            if(a[j]==i) color[j]=0;
        }
    }
    return res;
}

ll prankpts2() {
    memset(lstpos, 0, sizeof(lstpos));
    memset(color, 0, sizeof(color));
    ll l=1,r=2;
    bool nowcolor=0;
    lstpos[a[1]]=1;
    while(l<=r&&r<=n) {
        if(lstpos[a[r]] && ((lstpos[a[r]]<l && color[lstpos[a[r]]] != nowcolor) || (lstpos[a[r]]>=l && color[lstpos[a[r]]] == nowcolor))) {
            color[lstpos[a[r]]] = !nowcolor;
            color[r] = !nowcolor;
            l = r+1;
            nowcolor=!nowcolor;
        }
        else color[r] = nowcolor;
        lstpos[a[r]]=r;
        r++;
    }
    return calc();
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        ans = 0;
        if(n<=15) {
            
            bruteforce_O_2_pow_n(1);
            cout<<ans<<endl;
        }
        else {
            cout<<max(prankpts1(),prankpts2())<<endl;
        }
    }
    return 0;
}

// Last Updated UTC+8 2024/10/26 SAT 18:08
// 20pts+?pts O(2^n)