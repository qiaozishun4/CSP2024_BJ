#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(ll x,ll y){
    return x < y;
}
ll dic[100002] = {};
ll mark[100002] = {0};
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ll n,ans = 0;
    cin >> n;
    for (int i = 0;i < n;i ++){
        cin >> dic[i];
    }    
    sort(dic,dic+n,cmp);
    while (1){
        bool flag = 1;
        for (int i = 1; i < n;i ++){
            for (int j = 0;j < i;j ++){
                if(flag == 1 && dic[i] != dic[j] && mark[i] != 1 && mark[i] != 2 && mark[j] != 1){
                    mark[i] = 2;
                    mark[j] = 1;
                    flag = 0;
                    cout << i << " " << j << endl;
                }
            }
        }
        if (flag == 1){
            break;
        }
    }
    for (int i = 0;i < n;i ++){
        if (mark[i] != 1){
            ans ++;
        }
    }
    cout << ans;
    return 0;
}