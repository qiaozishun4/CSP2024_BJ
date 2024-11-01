#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128

const int N = 1e5 + 5;
int n, T, ok[N][2], d[10] = {0, 0, 1, 7, 4, 2, 6, 8, 0, 0};
vector < int > v[N][2];

bool cmp(vector < int > a, int x, vector < int > b, int y) {
    if(a.size() != b.size()) return a.size() < b.size();
    return x < y;
}

void print(vector < int > a) {
    for(int i = a.size()-1; i >= 0; i--) printf("%d", a[i]);
    printf("\n");
}

void dp(int a, int dep) { // 0 不是顶层 1 是顶层
    // 传参引用返回 当有a根火柴且 深度为dep时的最好方案vec
    if(a == 0) return;
    if(dep > 0 && ok[a][0] != 0) return;
    if(dep == 0 && ok[a][1] != 0) return;

    int se = (dep > 0 ? 0 : 1);
    int Num = 0; ok[a][se] = -1;
    for(int i = 2; i <= 7; i++) {           // 枚举选的数字的火柴数量
        int num = d[i];                     // 这个数量里面最小的数字
        if(dep > 0 && i == 6) num = 0;      // 没有前导0
        if(a < i)  break;                   // 拿不起
        dp(a-i, dep+1);                     //最优子结构
        if(ok[a-i][0] == -1) continue;         // 不行啊
        if((ok[a][se] == -1) || cmp(v[a-i][0], num, v[a][se], Num)) v[a][se] = v[a-i][0], ok[a][se] = i, Num = num;
//        printf("在%d里面，如果选了%d及以前根,则ok = %d , vec = ", a, i, ok[a]);
//        print(vec);
    }
    if(ok[a][se] > 0) v[a][se].push_back(Num);
//    printf("ok[%d] = %d, vec[%d] = ", a, ok[a], a);
//    print(vec);
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    scanf("%d", &T);
    while(T--) {
        ok[0][0] = 1;
        scanf("%d", &n);

        dp(n, 0);

        if(ok[n][1] == -1) printf("-1\n");
        else print(v[n][1]);
    }
    return 0;
}

