#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("duel.in","w",stdin);
    freopen("duel.out","r",stdout);
    int n;
    cin>>n;
    int l=n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {

        for(int j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
            {
                a[i]=0;
                a[j]=0;
                l--;
                cout<<l<<" ";
                break;
            }
        }
    }
    cout<<l;
    return 0;
}
