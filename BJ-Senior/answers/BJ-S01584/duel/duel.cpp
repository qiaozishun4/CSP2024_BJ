#include<bits/stdc++.h>
using namespace std;
const int NR = 1e5;
int a[NR + 10];
int cnt[NR + 10];

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int Max = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        Max = max(Max, a[i]);
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1;i <= Max;i++){
        // printf("cnt[%d]=%d\n", i, cnt[i]);
        if(cnt[i] && cnt[i - 1]){
            cnt[i - 1] = max(0, cnt[i - 1] - cnt[i]);
        }
        cnt[i] += cnt[i - 1];
    }
    printf("%d\n", cnt[Max]);
    return 0;
}
/*
cd ~/GJH/duel && g++ duel.cpp && ./a.out

14
1 1 1 1 1 1 1 1 1 1 1 1 1 5


5
1 2 3 1 2

10
136 136 136 2417 136 136 2417 136 136 136
*/