#include<iostream>
#include<algorithm>
using namespace std;
int a[100005],b[100005];
int main(int argc, char**argv)
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    int w;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    b[1]=a[1];
    w=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>b[w])
        {
            w++;
        }
        b[i]=a[i];
    }
    cout<<n-w+1<<endl;
    return 0;
}