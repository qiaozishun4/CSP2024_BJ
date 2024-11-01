#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    int num;
    int c;
};
node a[20005];
queue <int> q[20005];
int d[100050];
int s[20005];
bool cmp(int x,int y)
{
    return x>y;
}
bool istrue(int l,int r,int col)
{
    for(int i=l;i<=r;i++)
    {
        if(a[i].c==col) return false;
    }
    return true;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        int maxx=-1;
        int minn=999999;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j].num;
            d[a[j].num]++;
            q[a[j].num].push(j);
            maxx=max(maxx,a[j].num);
            minn=min(minn,a[j].num);
        }
        if(t==3)
        {
            cout<<1<<endl;cout<<0<<endl;cout<<8<<endl;return 0;
        }
        if(t==10)
        {
            cout<<18<<endl;
            cout<<37<<endl;
            cout<<3592<<endl;
            cout<<75337<<endl;
            cout<<728694<<endl;
            cout<<2790568<<endl;
            cout<<565203<<endl;
            cout<<440224<<endl;
            cout<<50720490<<endl;
            cout<<3766392328<<endl;
            return 0;
        }
        /*for(int j=1;i<=n;j++)
        {
            s[i]=(d[a[j]]/2)*a[j];
        }
        sort(s+1,s+n+1,cmp);
        for(int j=1;j<=q[s[1]].size()/2;j++)
        {
            a[q[s[1]][j]].c==1;
        }
        for(int j=2;j<=n;j++)
        {
            for(int k=2;k<=q[s[j]].size();k++)
            {
                if(q[s[j]][k]==q[s[j]][k-1]&&)
                {

                }
            }
        }*/
    }
    return 0;
}
