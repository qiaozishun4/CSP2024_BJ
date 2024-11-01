#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int cnt[N];
int t[10]{6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ans[N];

void init(){
    for(int i=1;i<=N;i++){
        ans[i] = -1;
        int tmp = i;
        while(tmp){
            cnt[i] += t[tmp%10];
            tmp/=10;
        }
    }
    for(int i=1;i<=N;i++){
        if(cnt[i] > N) continue;
        if(ans[cnt[i]] == -1){
            ans[cnt[i]] = i;
        }
    }
    return;
}

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    init();
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }
    return 0;
}