# include <iostream>
using namespace std;
int g[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int c[66] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888};
int cnt;
string f[100005] = {"-1", "-1", "1", "7", "4", "2", "6", "8", "10", "18", "22", "20", "28", "68", "88", "108", "188", "200", "208", "288", "688", "888"};
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    for (int i = 22; i <= 100000; i ++)
    {
        f[i] = f[i - 7] + "8";
    }
    int T, n = 1;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}
