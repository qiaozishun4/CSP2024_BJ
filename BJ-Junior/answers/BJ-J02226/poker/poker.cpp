#include <map>
#include <iostream>
using namespace std;

string a[105];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        string poker;
        cin >> poker;
        bool flag = true;
        for(int j = 1;j <= cnt;j++)
        {
            if(a[j] == poker)
            {
                flag = false;
                break;
            }
        }
        if(flag == true)
        {
            a[++cnt] = poker;
        }
    }
    cout << 52 - cnt << endl;
    return 0;
}
