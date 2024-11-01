#include<bits/stdc++.h>
using namespace std;
int a[12]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int i=1;

        if(n==1)
        {
            cout<<-1;
            cout<<endl;
        }
        else if(n%7==0&&n>=100)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==1)
        {
            cout<<10;
            for(int i=1;i<=n/7-1;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        else if(n<=51)
        {
            if(n>=40) i=288888;

            //cout<<"&"<<n<<endl;
            while(1)
            {
                //cout<<123<<endl;
                int x=i,cnt=0;
                while(x)
                {
                    cnt+=a[x%10];
                    x/=10;
                }
                if(cnt==n)
                {
                    cout<<i<<endl;
                    break;
                }
                i++;
            }
        }


    }
    return 0;
}
