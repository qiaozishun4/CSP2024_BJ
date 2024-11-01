#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int r;
    cin>>r;
    for(int i=0;i<r;i++)
    {
        int s;
        cin>>s;
        if(s==1)
        {
            cout<<"-1";
        }
        else if(s==2)
            cout<<"1"<<endl;
        else if(s==3)
            cout<<"7"<<endl;
        else if(s==4)
            cout<<"4"<<endl;
        else if(s==5)
            cout<<"5"<<endl;
        else if(s==6)
            cout<<"6"<<endl;
        else if(s==7)
            cout<<"8"<<endl;
        else if(s==8)
            cout<<"10"<<endl;
        else if(s>8)
        {
            if(s%7==0)
            {
                for(int f=0;f<s/7;s++)
                {
                    cout<<"8";
                }
                cout<<endl;
            }
            else if(s%7==1)
            {
                cout<<"10";
                for(int f=0;f<(s-8)/7;s++)
                {
                    cout<<"8";
                }
                cout<<endl;
            }
            else if(s%7==2)
            {
                cout<<"1";
                for(int f=0;f<(s-2)/7;s++)
                {
                    cout<<"8";
                }
                cout<<endl;
            }
            else if(s%7==3)
            {
                cout<<"20";
                for(int f=0;f<(s-10)/7;s++)
                {
                    cout<<"8";
                }
                cout<<endl;
            }
            else if(s%7==4)
            {
                cout<<"11";
                for(int f=0;f<(s-4)/7;s++)
                {
                    cout<<"8";
                }
                cout<<endl;
            }
            else if(s%7==5)
            {
                cout<<"2";
                for(int f=0;f<(s-5)/7;s++)
                {
                    cout<<"8";
                }
                cout<<endl;
            }
            else if(s%7==6)
            {
                cout<<"6";
                for(int f=0;f<(s-6)/7;s++)
                {
                    cout<<"8";
                }
                cout<<endl;
            }
        }

    }
    return 0;
}
