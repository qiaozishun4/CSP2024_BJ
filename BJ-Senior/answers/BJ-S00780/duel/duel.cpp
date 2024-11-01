#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010;
int n, cnt[N];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    int Max = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        cnt[tmp]++;
        if(cnt[tmp] > Max)
            Max = cnt[tmp];
    }
    printf("%d\n", Max);
    return 0;
}