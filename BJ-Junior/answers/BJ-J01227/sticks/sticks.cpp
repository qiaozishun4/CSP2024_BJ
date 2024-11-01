#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int T,n,ans;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--)
    {
        bool flag=false;
        cin>>n;
        if(n<=1)
            cout<<-1<<endl;
        else
        {
            for(int i=1;i<=10000;i++)
            {
                int sum=0,temp=i;
                while(temp)
                {
                    sum+=num[temp%10];
                    temp/=10;
                }
                if(sum==n)
                {
                    flag=true;
                    ans=i;
                    break;
                }
            }
            if(flag)
                cout<<ans<<endl;
            else
                cout<<-1<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
