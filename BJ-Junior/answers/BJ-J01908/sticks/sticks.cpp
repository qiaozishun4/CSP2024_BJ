#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin>>n;
        int cnt_8=n/7;
        int l=n%7;
        if(l==0)
        {
            for(int i=1;i<=cnt_8;i++)
            {
                cout<< 8;
            }
        }
        else if(l==1 && cnt_8>0)
        {
            cout<<10;
            for(int i=1;i<cnt_8;i++)
            {
                cout<<8;
            }
        }
        else if(l==2)
        {
            cout<<1;
            for(int i=1;i<=cnt_8;i++)
            {
                cout<<8;
            }
        }
        else if(l==3)
        {
            if(cnt_8==0)cout<< 7;
            else
            {
                cout << 22;
                for(int i=1;i<cnt_8;i++)
                {
                    cout <<8;
                }
            }
        }
        else if(l==4)
        {
            if(cnt_8==0)cout<< 4;
            else
            {
                cout<< 20;
                for(int i=1;i<cnt_8;i++)
                {
                    cout<<8;
                }
            }
        }
        else if(l==5)
        {
            cout << 2;
            for(int i=1;i<=cnt_8;i++)
            {
                cout<< 8;
            }
        }
        else if(l==6)
        {
            cout<<6;
            for(int i=1;i<=cnt_8;i++)
            {
                cout <<8;
            }
        }
        else
        {
            cout<< -1;
        }
        cout<< endl;
    }
    return 0;
}