#include<iostream>
using namespace std;
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
        int x = n/7;
        if(n<=7)
        {
            if(n == 0||n == 1)cout<<"-1"<<endl;
            else if(n == 2)cout<<"1"<<endl;
            else if(n == 3)cout<<"7"<<endl;
            else if(n == 4)cout<<"4"<<endl;
            else if(n == 5)cout<<"2"<<endl;
            else if(n == 6)cout<<"6"<<endl;
            else if(n == 7)cout<<"8"<<endl;
        }
        else if(n%7 == 0)
        {
            for(int i = 1;i<=x;i++)cout<<"8";
            cout<<endl;
        }
        else if(n%7 == 1)
        {
            cout<<"10";
            for(int i = 1;i<=x-1;i++)cout<<"8";
            cout<<endl;
        }
        else if(n%7 == 2)
        {
            cout<<"1";
            for(int i = 1;i<=x;i++)cout<<"8";
        }
        else if(n%7 == 3)
        {
            cout<<"22";
            for(int i = 1;i<=x-1;i++)cout<<"8";
        }
        else if(n%7 == 4)
        {
            cout<<"20";
            for(int i =1;i<=x-1;i++)cout<<"8";
            cout<<endl;
        }
        else if(n%7 == 5)
        {
            cout<<"2";
            for(int i = 1;i<=x;i++)cout<<"8";
            cout<<endl;
        }
        else if(n%7 == 6)
        {
            cout<<"6";
            for(int i = 1;i<=x;i++)cout<<"8";
            cout<<endl;
        }
        else cout<<"-1"<<endl;
    }
    return 0;
}
