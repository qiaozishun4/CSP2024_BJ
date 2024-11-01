#include <bits/stdc++.h>
using namespace std;
string l[52],l1[52];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    cin>>n;
    for (int i = 0;i < n;i++)
    {
        cin>>l[i];
    }
    ans = 52-n;
    int cnt=0;
    for (int i = 0;i < n;i++)
    {
        bool flag = false;
        for (int j = 0;j < cnt;j++)
        {
            if (l1[j] == l[i])
            {
                flag = true;
            }
        }
        if (!flag)
        {
            l1[cnt] = l[i];
            cnt++;
        }
        else
        {
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
