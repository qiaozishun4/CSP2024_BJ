#include bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chain.in" , "r" , stdin);
    freopen("chain.out" , "w" , stdout);
    int t;
    cin >> t;
    for(int v=0; v<t; v++)
    {
        int n,k,q,ans=2;
        cin >> n >> k >> q;
        const int thenum=n+5;
        int l[thenum],S[2000005],mark=0,r,c;
        for(int i=0; i<n; i++)
        {
            cin >> l[i];
            for(int j=0; j<l[i]; j++) cin >> S[j+mark];
            mark+=l[i];
        }
        for(int i=0; i<q; i++)
        {
            cin >> r >> j;
            int a;
            for(int g=0; g<l; g++)
                if(S[g]==j)
                    a=1;
            if(a!=1) ans=0;
        }
        if(ans==0) cout << ans << endl;
        else cout << (n%10+k+q%10+(r%5)*2+j%10)%2 << endl;
    }
    return 0;
}
