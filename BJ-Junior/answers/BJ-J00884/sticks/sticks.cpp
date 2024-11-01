#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int l=1;l<=T;l++)
    {
        int n;
        cin>>n;
        if(n<=7)
        {
            if(n==1)
            {
                cout<<"-1"<<endl;
            }
            else if(n==2)
            {
                cout<<"1"<<endl;
            }
            else if(n==3)
            {
                cout<<"7"<<endl;
            }
            else if(n==4)
            {
                cout<<"4"<<endl;
            }
            else if(n==5)
            {
                cout<<"2"<<endl;
            }
            else if(n==6)
            {
                cout<<"6"<<endl;
            }
            else if(n==7)
            {
                cout<<"8"<<endl;
            }
        }
        else
        {
            int cnt=(n/7)-1,s=n-(n/7)*7+7;
            if(s==7)
            {
                cout<<"8";
            }
            else if(s==8)
            {
                cout<<"10";
            }
            else if(s==9)
            {
                cout<<"18";
            }
            else if(s==10)
            {
                cout<<"22";
            }
            else if(s==11)
            {
                cout<<"20";
            }
            else if(s==12)
            {
                cout<<"28";
            }
            else if(s==13)
            {
                cout<<"68";
            }
            for(int i=1;i<=cnt;i++)
            {
                cout<<"8";
            }
            cout<<endl;
        }

    }
    return 0;
}

