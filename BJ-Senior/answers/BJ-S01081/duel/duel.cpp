#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100011], b[100011], c[100011];

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int x; scanf("%d", &x);
    int i, j;
    for(i = 1; i <= x; i++) {
            scanf("%d", a + i);
    }
    sort(a + 1, a + 1 + x, cmp); j = x;
    /*
    for(i = n; i >= 1; i--) {
        if(a[i] > j) {
            b[i] = j;
        } else {
            while(true) {
                j--;
                if(a[i] > a[j]) {
                    b[i] = j;
                    break;
                }
            }
        }
    }*/
    int sum = 0;
    for(i = x; i >= 1; i--) {
        if(a[i] > a[j]) {
            sum++;
            j--;
        }
        /*
        } else {
            while(true) {
                j--;
                if(a[i] > a[j]) {
                    sum++;
                    break;
                }
            }
        }
        */
    }
    cout <<x - sum <<endl;
    return 0;
}