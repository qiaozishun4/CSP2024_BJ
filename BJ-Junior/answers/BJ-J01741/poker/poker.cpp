#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string a[55];
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i ++)
    {
        cin>>a[i];
        for(int j = 1;j < i;j ++)
        {
            if(a[i]  == a[j])
            {
                ans--;
                break;
            }
        }
        ans ++;

    }
    cout<<52-ans;
    return 0;
}
