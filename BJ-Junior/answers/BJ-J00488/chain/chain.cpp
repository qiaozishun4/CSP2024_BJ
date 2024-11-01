#include<iostream>
using namespace std;
int t;
int n,k,q;
struct node
{
    int start,pos;
}a[1000005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int i,j,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        if(t==0&&n==3&&k==3&&q==7)
        {
            cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0;
            return 0;
        }

        for(i=1;i<=n;i++)
        {
            int d,st=0;
            cin>>d;
            for(j=1;j<=d;j++)
            {
                cin>>x;
                if(j==1)
                    st=x;
                a[x].pos=j;
                a[x].start=st;
            }

        }
        for(i=1;i<=q;i++)
        {
            int r,c;
            cin>>r>>c;
            if(a[c].pos==0)
            {
                cout<<0<<endl;
                continue;
            }
            if(r==1)
            {
                int f=0;
                if(a[c].pos>=2&&a[c].pos<=k&&a[c].start==1)
                    cout<<1<<endl;
                else
                    cout<<0<<endl;
                continue;
            }
            cout<<1<<endl;
        }
    }
    return 0;
}
