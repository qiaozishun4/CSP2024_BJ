#include<bits/stdc++.h>
using namespace std;
const int C = 0;
const int S = 13;
const int D = 26;
const int H = 39;
bool flag[60];

struct pok{
    char hs, numb;
} a[60];

int main(){
    memset(flag, false, sizeof(flag));
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].hs >> a[i].numb;
        int tmp = 0;
        if (a[i].numb == 'A')
            tmp = 1;
        if ((a[i].numb >= '2') && (a[i].numb <= '9'))
            tmp = a[i].numb - '0';
        if (a[i].numb == 'T')
            tmp = 10;
        if (a[i].numb == 'J')
            tmp = 11;
        if (a[i].numb == 'Q')
            tmp = 12;
        if (a[i].numb == 'K')
            tmp = 13;
        if (a[i].hs == 'C')
            tmp += C;
        if (a[i].hs == 'S')
            tmp += S;
        if (a[i].hs == 'D')
            tmp += D;
        if (a[i].hs == 'H')
            tmp += H;
        flag[tmp] = true;
    }
    int ans = 0;
    for (int i = 1; i <= 52; i++)
        if (!flag[i])
            ans++;
    cout << ans;

    return 0;
}