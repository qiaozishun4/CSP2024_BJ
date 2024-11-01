#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool isuse[N];
int a[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    memset(isuse,0,sizeof(isuse));
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    int live=0;
    for(int i = 1; i<=n; i++)
    {
        int p=upper_bound(a+1,a+n+1,a[i])-a;

        while(1)
        {
            if(isuse[p]==1) p++;
            else break;
        }
        if(p>n)
        {
            live++;
            //cout<<a[i]<<endl;
        }
        else
        {
            isuse[p]=1;
            //cout<<a[i]<<" "<<p<<endl;
        }
    }
    cout<<live<<endl;
    return 0;
}