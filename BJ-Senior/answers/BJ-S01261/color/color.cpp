#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+10;
const int M = 1e6+10;

bool cmp(int a,int b){return a>b;}


int t;
int a[N];
int b[N];   // 0 red    1 blue

int maxn = -1;


void dfs(int now,int n) {
    int ans = 0;
    int red_l=0, blue_l=0;
    a[0] = -10000;
    if (now == n+1) {

        for (int i=1;i<=n;i++) {
            if (b[i] == 0)
            {
                if (a[i]==a[red_l])ans+=a[i];
                red_l = i;
            }
            if (b[i] == 1)
            {
                if (a[i]==a[blue_l])ans+=a[i];
                blue_l = i;
            }

        }
        maxn = max(maxn, ans);
        return ;
    }
    for (int i=0;i<=1;i++) {
        b[now] = i;
        dfs(now+1, n);
    }


}


void work() {
    maxn = -1;
    int n;
    scanf("%d", &n);

    for (int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
    }



    dfs(1, n);
    cout << maxn << endl;

}


int main() {

    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    scanf("%d", &t);
    while (t--) {
        work();
    }



    return 0;
}
