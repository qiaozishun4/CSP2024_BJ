#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n=5,a[100005] = {},ans=1,s=0,k;
    cin >> n;
    for(int i = 1;i<= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = n;i>0;i--)
    {
         k = 1;
        while(a[i]==a[i-1])
        {
            k++;
            i--;
        }
        if(s<k-1)
        {
            ans+=k-1-s;
            s+=k-1;
        }
    }
    cout << ans;
    return 0;
}
