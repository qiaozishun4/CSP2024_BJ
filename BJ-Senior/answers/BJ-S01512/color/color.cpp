#include<bits/stdc++.h>
#define ll long long
const int N = 1e5+10;

using namespace std;

int T;
map<ll, ll>mp;
bool p[1000010];
int a[1000010];

int main(){

    cin.tie(0), cout.tie(0);
    cin>>T;
    while(T--){
        int n;
        ll ans = 0ll;
        scanf("%d", &n);
        mp.clear();
        int cnt = 0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(!mp[a[i]]){
                mp[a[i]] = 1-cnt;
                cnt = 1-cnt;
            }
            p[i] = mp[p[a[i]]];
            for(int j=i-1;j>=1;j--){
                if(p[j] == p[i] && a[i] == a[j])ans += a[i];
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
