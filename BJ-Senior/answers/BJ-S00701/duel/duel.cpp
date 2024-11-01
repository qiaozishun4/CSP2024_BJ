#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[100005],t[100005],r[100005],s;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int i,j,ct=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        int x;cin>>x;
        if(t[x]==0)
            a[++ct]=x;
        t[x]++;
    }
    sort(a+1,a+ct+1);
    for(i=1;i<=ct;i++)
        r[i]=t[a[i]];
    for(i=2;i<=ct;i++)
    {
        j=1;
        int rt=r[i];
        while(i-j>0&&rt>0)
        {
            while(r[i-j]>0&&rt>0)
            {
                rt--;r[i-j]--;s++;
            }
            j++;
        }
    }
    cout<<n-s;
    return 0;
}
