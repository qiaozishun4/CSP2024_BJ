#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <bits/stdc++.h>
#include <set>

using namespace std;

multiset<int> Arr;

int Lowest(multiset<int> Arr) {
    int cnt = 0;
    for (int value : Arr) {
        return value;
    }
}

bool setFind(multiset<int> Arr, int value) {
    if (Arr.find(Lowest(Arr) + value) != Arr.end()) {
        return true;
    } else {
        return false;
    }
}

int Highest(multiset<int> Arr) {
    int cnt = 0, len = Arr.size();
    for (int value : Arr) {
        cnt++;
        if (cnt == len) {
            return value;
        }
    }
}


bool compare(int a, int b) {
    return a > b;
}

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        Arr.insert(temp);
    }

    for (int i = 0; i < n; i++) {
        int x = Highest(Arr);
        for (int j = 1; j <= x; j++) {
            if (setFind(Arr, j)) {
                Arr.erase(Lowest(Arr));
            }
        }
    }
    printf("%d", Arr.size() + 1);
    /*
    time_t *timer = new time_t;
    uint64_t rand = time(timer);
    rand %= n;
    printf("%d", rand);
    */
    return 0;
}
