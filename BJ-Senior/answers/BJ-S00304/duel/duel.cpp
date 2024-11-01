#include <iostream>
using namespace std;
int a[100005],b[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,i;
    bool w=1;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>2)w=0;
        b[a[i]]++;
    }
    if(w)
    {
        cout<<max(b[1],b[2]);
        return 0;
    }
    return 0;
}