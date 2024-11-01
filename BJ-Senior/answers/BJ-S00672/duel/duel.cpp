#include <iostream>

using namespace std;
int n;
int a[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[x]++;
    }
    x=0;
    int y=0;
    for(int i=100010;i>0;i--)
    {
        if(a[i])
        if(x<a[i])
        {
            y+=a[i]-x;
            x=a[i];
        }
    }
    cout<<y;
    return 0;
}
