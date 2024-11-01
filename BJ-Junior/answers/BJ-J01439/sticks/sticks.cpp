#include<bits/stdc++.h>
using namespace std;
int dis[100] = {6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,a[100005];
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
        if(a[i] < 2)
        {
            cout<<-1<<endl;
        }
        else if(a[i] % 7 == 0)
        {
            for(int j = 1;j <= a[i]/7;j++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        else if(a[i] % 7 == 1 && a[i])
        {
            cout<<10;
            for(int j = 1;j < a[i]/7;j++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        else
        {
            bool flag = false;
            int o = ceil(a[i]*1.00/7.00);
            int l = o;
            //cout<<l<<endl;
            while(l--)
            {
                for(int j = 0;j < 10;j++)
                {
                    if(l == o-1 && j == 0) continue;
                    if(l == 0)
                    {
                        if(dis[j] == a[i])
                        {
                            cout<<j;
                            flag = true;
                            break;
                        }
                        continue;
                    }
                    if(a[i]-dis[j]-7*l <= 0)
                    {
                        cout<<j;
                        flag = true;
                        a[i]-=dis[j];
                        break;
                    }
                }
            }
            if(!flag) cout<<-1;
            cout<<endl;
        }
    }
}
