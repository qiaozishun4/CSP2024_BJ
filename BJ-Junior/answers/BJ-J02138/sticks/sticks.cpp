#include<bits/stdc++.h>
using namespace std;

constexpr const char table[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
unsigned int maxdeep;
int ans, num;
vector<char> a;

static inline bool solve(int n, unsigned int d) noexcept {
    if (n==0) {
        if (a.front()==0) return false;
        int g = 1, x = 0;
        for (int i=a.size()-1;i>=0;--i) {
            x += a[i] * g;
            g *= 10;
        }
        ans = min(ans, x);
        maxdeep = min(d, maxdeep);
        return true;
    }
    if (d > maxdeep || n<2) { return false; }
    ++d;
    bool res = 0;
    for (char i=9;i>=0;--i) {
        a.emplace_back(i);
        res |= solve(n - table[i], d);
        a.pop_back();
    }
    return res;
}

int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    unsigned short T;
    scanf("%hd", &T);
    do{
        ans = (maxdeep = ~((int)0)) >> 1;
        scanf("%d", &num);
        printf("%d\n", solve(num, 0) ? ans : -1);
    }while(--T);
    fclose(stdin);
    fclose(stdout);
    return 0;
}