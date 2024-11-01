#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,num;
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n<7)
        {
            if(n==2) cout<<1;
            else if(n==3) cout<<7;
            else if(n==4) cout<<4;
            else if(n==5) cout<<2;
            else if(n==6) cout<<6;
            cout<<endl;
            continue;
        }
        if(n%7==0)
        {
            num=n/7;
            for(int i=1;i<=num;i++)
                printf("8");
        }
        else
        {
            int temp=n%7,num=n/7;
            if(temp<=2)
            {
                cout<<1;
                if(temp==1)
                {
                    cout<<0;
                    num--;
                }
            }
            else if(temp<=5)
            {
                cout<<2;
                temp=5-temp;
                if(num>=temp)
                    num-=temp;
                for(int i=1;i<=temp;i++)
                    printf("0");
            }
            else cout<<6;
            for(int i=1;i<=num;i++)
                printf("8");
        }
        printf("\n");
    }
    return 0;
}
