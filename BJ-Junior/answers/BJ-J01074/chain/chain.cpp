#include<bits/stdc++.h>
using namespace std;
int t,n,k,q;
int words[1005][1005];
int l[1005];
bool ans=0;

void reset()
{
    for(int i=0;i<1005;i++)
    {
        for(int j=0;j<1005;j++)
        {
            words[i][j]=0;
        }
        l[i]=0;
    }
}

bool can(int r,int c)
{
    if(r==c)
    {
        return r%2==0;
    }
    else if(r<c)
    {
        return r-c%2==0;
    }
}

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        reset();
        cin>>n>>k>>q;
        for(int i=0;i<n;i++)
        {
            cin>>l[i];
            for(int j=0;j<l[i];j++)
            {
                cin>>words[i][j];
            }
        }
        while(q--)
        {
            int r,c;
            cin>>r>>c;
            if(can(r,c))
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
        }
    }
    return 0;
}
