#include<bits/stdc++.h>
using namespace std;
int n,k,q,l[100005];
int r[100005],c[100005];
vector<int>S[100005];
int main()
{
    freopen("chain2.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;cin>>T;
    while(T)
    {
        cin>>n>>k>>q;
        for(int i=0;i<n;i++)
        {
            cin>>l[i];
            for(int j=0;j<l[i];j++)
            {
                int a;cin>>a;
                S[i].push_back(a);
            }
        }
        for(int i=0;i<q;i++)
        {
            cin>>r[i]>>c[i];
            if(r[i]==1)
            {
                bool flag=false;
                for(int m=0;m<n;m++)
                    for(int j=0;j<l[i];j++)
                        if(S[i][j]==1)
                            for(int p=1;p<=k;p++)
                                if(S[i][j+p]==c[i])
                                    flag=true;
                cout<<flag;
            }
        }
        T--;
    }
    return 0;
}