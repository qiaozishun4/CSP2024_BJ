#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdlib>
#define ll long long
#define o1 first
#define o2 second
#define omp make_pair
#define opb push_back
#define inf 3423423423423423422ll
#define MAX_N 522222

using namespace std;

ll read(){ll x = 0;char c = 0;bool v = 0;do{c = getchar();if(c == '-')v = 1;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');return v ? -x : x;}
char gtc(){char c = 0;while(c < 33 && c != EOF)c = getchar();return c;}

int n;
ll a[MAX_N];

void oM()
{
    n = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        int r = i;
        for(int j = i; j <= n && a[j] == a[i]; j++)
            r = j;
        int len = r - i + 1;
        i = r;
        cnt -= min(cnt, len);
        cnt += len;
    }
    printf("%d\n", cnt);
}

void oC()
{
    ;
}

void oE()
{
    ;
}

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    oE();
    int T = 1;
    while(T--)
        oM(), oC();
    return 0;
}
