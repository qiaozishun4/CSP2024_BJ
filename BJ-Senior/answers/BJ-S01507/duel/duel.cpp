#include <bits/stdc++.h>
using namespace std;

struct node
{
    int v;
    bool used=0;
}a[200005];

int n;

bool cmp(node x,node y)
{
	return x.v<y.v;
}

int my_upperbound(int q)
{
    for(int i=q;i<=n;i++)
    {
        if(a[i].v>a[q].v && !a[i].used) return i;
    }
    return -1;
}

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].v;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        int s=my_upperbound(i);
        if(s>0)
        {
            a[s].used=1;
            a[i].v=-1;
        }
        else 
        {
			cout<<n-i+1;
			return 0;
		}
    }
    return 0;
}

