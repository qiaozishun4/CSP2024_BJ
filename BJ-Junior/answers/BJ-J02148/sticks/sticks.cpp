#include <bits/stdc++.h>
using namespace std;
int s[15]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x=n;
        bool flag=0;
        if(n<2)
        {
            cout<<"-1"<<endl;
        }
        else if(n<=7)
        {
            for (int i=0;i<=9;i++)
            {
                if(s[i]==n) cout<<i<<endl;
            }
        }
        else if(n%7==0)
        {
            for (int i=1;i<=n/7;i++) cout<<7;
            cout<<endl;
        }
        else{
            for (int i=1;i<=9;i++)
            {

                for (int j=0;j<=9;j++)
                {
                    for (int k=0;k<=9;k++)
                    if(s[i]+s[j]+s[k]==n && flag==0)
                    {
                        cout<<i*100+j*10+k<<endl;
                        flag=1;
                    }
                }
            }
        }
    }
    return 0;
}
