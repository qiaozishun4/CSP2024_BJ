#include<bits/stdc++.h>
using namespace std;
const int N=2E5+1;
int a[N];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    srand(time(NULL));
    int T;
    cin>>T;
    while(T--)
    {
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            int len;
            cin>>len;
            for(int j=1;j<=len;j++)
            {
                int ls;
                cin>>ls;
                a[ls]++;
            }
        }
        while(q--)
        {
            int r,c;
            cin>>r>>c;
            if(r==1 && a[c])
                cout<<1<<endl;
            else if(a[c]>=2)
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
    }
    return 0;
}