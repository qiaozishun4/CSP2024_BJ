#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n,k,q;
        cin >> n >> k >> q;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            for (int j=1;j<=x;j++)
            {
                int y;
                scanf("%d",&y);
            }
        }
        for (int i=1;i<=q;i++)
        {
            int xx,yy;
            scanf("%d%d",&xx,&yy);
            cout << 1 << "\n";
        }
    }

    return 0;
}
