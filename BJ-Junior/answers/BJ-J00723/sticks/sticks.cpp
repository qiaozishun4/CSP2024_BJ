#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

//0,1,2,3,4,5,6,7,8,9
//6,2,5,5,4,5,6,3,7,6

const int NR = 1e5 + 10;
const int mxn = 1e5;
int mk[NR];
int d[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void init() {
    mk[0] = mk[1] = 0;
    mk[2] = mk[3] = mk[4] = mk[5] = mk[6] = mk[7] = 1;
    for(int i = 8; i <= mxn; i++) {
        mk[i] = (i + 7 - 1) / 7;
    }
}

void f(int x, int num, bool fr) {
    if(num <= 0) return;
    for(int i = 0; i <= 9; i++) {
        if(i == 0 && fr) continue;
        if(num == 1 && x - d[i] != 0 || mk[x - d[i]] > num - 1) continue;
        printf("%d", i);
        f(x - d[i], num - 1, 0);
        return;
    }
    //printf("ERROR");
    //exit(0);
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    init();
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        if(n < 2) {
            printf("-1\n");
            continue;
        }
        if(n % 7 == 0) {
            for(int i = 1; i <= n / 7; i++)
                printf("8");
            puts("");
            continue;
        }
        f(n, mk[n], 1);
        puts("");
    }
    return 0;
}
