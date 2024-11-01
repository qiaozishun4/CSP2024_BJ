#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100010], cnt[100010], can_use[100010], nextnum[100010];
bool cmp(int x, int y){
    return x <y;
}
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    int maxn = 0, minn = 10000000;
    for(int i = 1; i <= n; i++){
        cin >>a[i];
        cnt[a[i]]++;
        can_use[a[i]] ++;
        maxn = max(a[i], maxn);
        minn = min(a[i], minn);
    }

    sort(a + 1, a + n + 1, cmp);
    bool flag = false;
    for(int i = minn; i <= maxn; i = nextnum[i]){
            if(cnt[i] == 0){
                continue;
            }
        if(i == maxn){
            break;
        }
        for(int j = i + 1; j <= maxn; j++){
            if(cnt[j] != 0){
                nextnum[i] = j;

                flag = true;
                break;
            }
        }

    }
    int sum = cnt[minn];

    for(int i = nextnum[minn]; i <= maxn; i = nextnum[i]){
        sum = max(cnt[i], sum);
    }
    cout << sum << endl;
    return 0;
}
