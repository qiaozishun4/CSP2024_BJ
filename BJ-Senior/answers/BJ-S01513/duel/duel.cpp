#include<bits/stdc++.h>
using namespace std;

int n,c[100010],a[100010],ai,m,ans;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin >> n;
    
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        if(c[x] == 0){
            a[++ai] = x;
        }
        c[x]++;
    }

    sort(a + 1,a + 1 + ai);

    ans = n;

    for(int i = 1;i <= ai;i++){
        ans -= min(m,c[a[i]]);
        m -= min(m,c[a[i]]);
        m += c[a[i]];
    }

    cout << ans << endl;

    return 0;
}