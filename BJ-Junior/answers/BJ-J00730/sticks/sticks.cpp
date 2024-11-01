#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,d[15]={6,2,5,5,4,5,6,3,7,6};
string ans;
bool f;
bool cmin (string t1,string t2)
{
    if (t1.size ()<t2.size ())
    {
        return 1;
    }
    if (t1.size ()==t2.size ())
    {
        for (int i=0;i<t1.size ();i++)
        {
            if (t1[i]<t2[i])
            {
                return 1;
            }
            if (t2[i]<t1[i])
            {
                return 0;
            }
        }
    }
    return 0;
}
void dfs (int x,string num)
{
    if (x<0)
    {
        return;
    }
    if (cmin (ans,num))
    {
        return;
    }
    if (!x)
    {
        f=1;
        if (cmin (num,ans))
        {
            ans=num;
        }
        return;
    }
    if (x==n)
    {
        for (int i=1;i<=9;i++)
        {
            dfs (x-d[i],num+(char)(i+'0'));
        }
        return;
    }
    for (int i=0;i<=9;i++)
    {
        dfs (x-d[i],num+(char)(i+'0'));
    }
}
signed main()
{
	freopen ("sticks.in","r",stdin);
	freopen ("sticks.out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=0;i<1e5;i++)
        {
            ans=ans+"1";
        }
        dfs (n,"");
        if (!f)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<ans<<endl;
        f=0;
    }
	return 0;
}
