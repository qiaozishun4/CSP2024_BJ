#include<bits/stdc++.h>
using namespace std;

long long T;

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int ans[20];
    int n,k,q;
    int ge;
    int temp;
    int wen;
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>q;
        for(int i=0;i<=10;i++)
        {
            ans[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>ge;
            for(int j=1;j<=ge;j++)
            {
                cin>>temp;
                ans[temp]=1;
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>wen;
            if(ans[wen]==0) cout<<"0"<<endl;
            else cout<<"1"<<endl;
        }
    }
    return 0;
}
