#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    cin>>n;
    while(n)
    {
        
        cin>>st;
        if(st<2) cout<<-1;
        else 
        {
            a[2]=1,a[3]=7,a[4]=4,a[5]=2,a[6]=0,a[7]=8;
            if(st<8) 
            {
                cout<<a[st]<<endl;
                continue;
            }
            else
            {
                if(st%7==0)
                {
                    for(int i=1;i<=st/7;i++)
                    {
                        cout<<8;
                    }
                    cout<<endl;
                }
                else cout<<208;
            }
        }
        n--;
    }
    return 0;
}
