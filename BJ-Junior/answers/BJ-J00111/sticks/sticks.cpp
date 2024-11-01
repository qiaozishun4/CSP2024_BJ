#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n,a[10]={6,2,5,5,4,5,6,3,7,6};
    bool b;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        b=true;
        cin>>n;
        if(n<2)
        {
            cout<<"-1"<<endl;
            continue;
        }
        if(n<8)
        {
            for(int i=1;i<10;i++)
            {
                if(a[i]==n)
                {
                    cout<<i<<endl;
                    b=false;
                    break;
                }
            }
        }
        if(n%7==0&&b)
        {
            for(int i=0;i<n/7;i++)cout<<"8";
            cout<<endl;
            continue;
        }
        if(n%7==1&&b)
        {
            cout<<"10";
            for(int i=1;i<n/7;i++)cout<<"8";
            cout<<endl;
            continue;
        }
        if(b)
        {
            int s;
            for(int j=pow(10,n/7);j<pow(10,n/7+1);j++)
            {
                s=0;
                int ii=j;
                while(ii!=0)
                {
                    s+=a[ii%10];
                    ii/=10;
                }
                if(s==n)
                {
                    cout<<j<<endl;
                    b=false;
                    break;
                }
                if(j==208)cout<<s<<endl;
            }
        }
        if(b)cout<<"-1"<<endl;
    }
    return 0;
}
