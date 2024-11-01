#include <bits/stdc++.h>
using namespace sdt;
int s[100010];
int main()
{
    //freopen("chain.in","r",stdin);
    //freopen("chain.out","r",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(s,0,sizeof(s));
        int n,k,q;
        cin >> n >> k >> q;
        int l;
        cin >> l;
        for(int i=0;i<l;i++)cin >> s[i];
        while(q--)
        {
            string r;
            int c;
            cin >> r >> c;
            for(int i=c;i>=0;i--)
            {
                if(s[i].find(r))
                {
                    cout << "0";
                    break;
                }
            }
        }
    }
    return 0;
}
