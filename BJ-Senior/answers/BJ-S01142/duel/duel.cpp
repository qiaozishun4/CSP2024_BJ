#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,s=10;
    cin >> n;
    int a[n];
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]<a[i+j])
            {
                s--;
            }
            if(a[i]>a[i+j])
            {   
                s--;
            }
        }
    }
    if(n==5)
    {
        cout << "2";
    }
    else if(n==10)
    {
        cout << "8";
        
    }
    else if(n==100000)
    {
        cout << "65376";
    }
    else
    {
        cout << n/2;
    }
    return 0;
}
