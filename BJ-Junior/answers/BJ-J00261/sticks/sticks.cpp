#include <bits/stdc++.h>
using namespace std;
int ans;
int num[10] = {6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--)
    {
        ans = 0;
        cin>>n;
        for(int i = 1;i<=99999;i++)
        {
            int sum = 0;
            int f = i;
            while(f!=0)
            {
                sum += num[f%10];
                f /= 10;
            }
            if(sum == n)
            {
                ans = i;
                break;
            }
        }
        if(ans == 0)
            cout<<-1;
        else
            cout<<ans;
    }
    return 0;
}