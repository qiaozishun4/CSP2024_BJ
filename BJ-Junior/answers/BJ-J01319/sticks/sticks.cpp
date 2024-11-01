#include<bits/stdc++.h>
using namespace std;
int a[10] = {6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        cin>>n;
        int cnt = n / 7,sum = n - cnt * 7,t;
        if(sum == 1)
        {
            if(cnt > 0)
            {
                cnt--;
                cout<<10;
                for(int i = 1;i <= cnt;i++)
                    cout<<8;
            }
            else
                cout<<-1;
        }
        else if(sum == 0)
        {
            for(int i = 1;i <= cnt;i++)
                cout<<8;
        }
        else
        {
            for(int i = 1;i <= 9;i++)
            {
                if(a[i] == sum)
                {
                    t = i;
                    break;
                }
            }
            for(int i = 1;i <= t;i++)
            {
                if(sum < a[i] && a[i] - sum <= cnt * 5)
                {
                    t = i;
                    sum = a[i] - sum;
                    break;
                }
            }
            cout<<t;
            while(cnt != 0)
            {
                if((cnt - 1) * 5 < sum - 1)
                {
                    for(int i = 0;i <= 9;i++)
                    {
                        if((cnt - 1) * 5 < sum - a[i])
                        {
                            cout<<i;
                            sum -= a[i];
                            break;
                        }
                    }
                    cnt--;
                }
                else if(sum != 0)
                {
                    cout<<0;
                    cnt--;
                    sum--;
                }
                else
                {
                    cout<<8;
                    cnt--;
                }
            }
        }
        cout<<endl;
    }
}
