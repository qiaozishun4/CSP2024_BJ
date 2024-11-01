#include<bits/stdc++.h>
using namespace std;
int s[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out"."w",stdout);
        int t;
        cin>>t;
        for(int i=1; i<=t; i++)
        {
            int a;
            cin>>a;
            if(a%7==0)
            {
                for(int j=1; j<=a/7; j++)
                {
                    cout<<'8';
                }
                cout<<endl;
            }
            if(a%7==1)
            {
                if(a==13)
                    {
                        cout<<"28"<<endl;
                        break;
                    }
                    cout<<'6';
                for(int i=1;i<=a/7; i++)
                {
                    cout<<'8';
                }
            }
        }
    return 0;
}
