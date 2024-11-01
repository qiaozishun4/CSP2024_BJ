#include <iostream>
freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);
using namespace std;
int main()
{
    int n,a[],sum=0;
    cin>>n;
    sum = n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]>a[j])
            {
                sum=sum-1;
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}
