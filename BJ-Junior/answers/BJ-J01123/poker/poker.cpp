#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, len, ans = 52;
char ch[60][5],beUsed[60][5];
signed main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ch[i][0] >> ch[i][1];
    }
    for (int i = 0; i < n; i++)
    {
        bool flag = 0;
        for (int j = 0; j < len; j++)
        {
            if(ch[i][0] == beUsed[j][0] && ch[i][1] == beUsed[j][1])
            {
                //cout << beUsed[j][0] << endl <<beUsed[j][1] << endl;
                flag = 1;
            }
        }
        if (!flag)
        {
            ans--;
            beUsed[len][0] = ch[i][0];
            beUsed[len][1] = ch[i][1];
            len++;
        }
        //cout << ch[i][0]<<ch[i][1]<<endl;
    }
    cout << ans;
    return 0;
}
