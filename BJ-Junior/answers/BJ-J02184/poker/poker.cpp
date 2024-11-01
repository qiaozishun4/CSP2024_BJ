#include <bits/stdc++.h>
using namespace std;
int n;
map<char,int> m;
char S[18] = {'D','C','H','S','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int Sum[5][14];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 0;i < 4;i++)
    {
        m[S[i]] = i + 1;
    }
    for(int i = 4;i < 17;i++)
    {
        m[S[i]] = i - 3;
    }
    for(int i = 1;i <= n;i++)
    {
        char x[2];
        cin >> x;
        int a = m[x[0]],b = m[x[1]];
        Sum[a][b]++;
    }
    int ans = 0;
    for(int i = 1;i <= 4;i++)
    {
        for(int j = 1;j <= 13;j++)
        {
            if(!Sum[i][j])
            {
                ans++;
            }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
