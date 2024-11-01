#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int b[100005];
int already=0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int max=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        b[a[i]]++;
        if(a[i]>max)
            max=a[i];
    }
    if(max==2)
    {
        if(a[1]>a[2])
            cout<<b[1];
        else
            cout<<b[2];
    }
    else
    {
        for(int i=1;i<=max;++i)
        {
            already+=b[i];
            if(b[i+1]>=already)
            {
                already=0;
            }
            else
            {
                already-=b[i+1];
            }
        }
        cout<<already;
    }
    return 0;
}
