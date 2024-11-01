#include<bits/stdc++.h>
using namespace std;
int s[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> s[i];
    }
    sort(s + 1,s + 1 + n);
    int flag = 0,st = 1,num = 0,ans = n;
    for(int i = 1;i <= n;i++){
        if(!flag) flag = s[i];
        if(flag != s[i]){
            int cnt = i - st;
            ans -= min(num,cnt);
            num = max(num,cnt);
            st = i;
            flag = s[i];
        }
    }
    int cnt = n - st + 1;
    ans -= min(num,cnt);
    cout << ans;
    /*m++;
    p[m] = n - st + 1;
    for(int i = 1;i < m;i++){
        n -= min(p[i],p[i + 1]);

    }*/
    return 0;
}
