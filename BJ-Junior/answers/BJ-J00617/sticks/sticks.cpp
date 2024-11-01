#include <bits/stdc++.h>
using namespace std;
int biao[] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888, 1088, 1888, 2008, 2088, 2888, 6888, 8888, 10888, 18888, 20088, 20888, 28888, 68888, 88888, 108888, 188888, 200888, 208888, 288888, 688888, 888888, 1088888, 1888888, 2008888, 2088888, 2888888, 6888888, 8888888, 10888888, 18888888, 20088888, 20888888, 28888888, 68888888, 88888888, 108888888, 188888888, 200888888, 208888888};
int fbiao[] = { 2,6,8,10,18,200,20,28,68,88,108,188,200,208};
void output(int n) {
    string eight = "8";
    int i = (n-61)%14;
    int j = (((n-61)/14)*2)+8;
    if (i == 5) j--;
    cout << fbiao[i];
    for (int i = 0; i < j; i++) cout << eight;
    cout << '\n';
}
int T, n;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    cin >> T;
    while (T--) {
        cin >> n;
        if (n <= 60) cout << biao[n] << '\n';
        else output(n);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
