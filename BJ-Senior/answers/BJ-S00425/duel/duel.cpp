#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("duel.in");
ofstream cout("duel.out");
int n;
int a[100001];

int main()
{
    cin >> n;
    int minn = 1e9;
    for (int i = 1; i <= n; i++)
        cin >> a[i], minn = min(minn, a[i]);
    sort(a+1, a+n+1);
    int cnt = n, pos = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == minn) continue;
        if (a[i] > a[pos]) 
        {
            cnt--;
            pos++;
        }
    }
    cout << cnt << endl;
    return 0;
}