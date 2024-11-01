#include<iostream>
#include<cstring>
using namespace std;
int t,n,k,q,l,x,s;
bool f,v[200005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        memset(v,0,sizeof(v));
        while(n--)
        {
            cin>>l;
            f=0;
            for(int i=1;i<=l;i++)
            {
                cin>>x;
                if(i>=s+k)
                {
                    f=0;
                }
                if(f)
                {
                    v[x]=1;
                }
                if(x==1)
                {
                    f=1;
                    s=i;
                }
            }
        }
        while(q--)
        {
            cin>>f>>x;
            cout<<v[x]<<"\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}