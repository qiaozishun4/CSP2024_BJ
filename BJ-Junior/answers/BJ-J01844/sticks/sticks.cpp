#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
  freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
        }
        else if(n%7==0)
        {
             for(int i=1;i<=n/7;i++)
                cout<<8;
             cout<<endl;
        }
        else
        {
            int ans=-1;
            for(int i=1;i<=1e10;i++)
            {
                long long cnt=0;
                int temp=i;
                while(temp)
                {
                    int t1=temp%10;
                    temp/=10;
                    if(t1==0||t1==6||t1==9)
                        cnt+=6;
                    if(t1==1)
                        cnt+=2;
                    if(t1==7)
                        cnt+=3;
                    if(t1==4)
                        cnt+=4;
                    if(t1==2||t1==3||t1==5)
                        cnt+=5;
                    if(t1==8)
                        cnt+=7;
                }
                if(cnt==n)
                {
                    ans=i;
                    break;
                }
            }
            cout<<ans<<endl;
        }
    }

}

