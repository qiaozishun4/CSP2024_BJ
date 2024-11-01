#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n,k,q;
        cin>>n>>k>>q;

        int t=n;
        int s[n][];
        while(t--)
        {
            int l;
            cin>>l;
            for(int i=0;i<l;i++)
            {
                cin>>s[n-t][i];
            }
        }

        int ans=0;
        while(q--)
        {

        }

        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
