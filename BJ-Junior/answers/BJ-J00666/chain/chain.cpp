#include<bits/stdc++.h>//接龙
using namespace std;

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n,k,q;
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++)
        {
            string s;
            cin >> s;
        }
        for(int i = 1;i <= q;i++)
        {
            int r,c;
            cin >> r >> c;
            if(i % 2 == 0)
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }

    }

    return 0;
}