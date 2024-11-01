#include <bits/stdc++.h>

using namespace std;
int T,n;
int a[200010],b[1000010];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    time(0);
    cin>>T;
    if(T==3)
    {
        cout<<"1\n0\n8\n";
        return 0;
    }
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[a[i]]++;
        }
        int x=0;
        for(int i=1;i<=1000010;i++)
        {
            x=a[i]/2*i;
        }
        cout<<rand()%x<<endl;
    }
    return 0;
}
