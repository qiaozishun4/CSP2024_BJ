#include <bits/stdc++.h>
using namespace std;
int n,ans,t,x,y,z,m,k,wei;
char c;
bool bol;
int main()
{

    freopen("sticks.in","r",stdin);


    freopen("sticks.out","w",stdout);
    cin>>z;

    while(z--)
    {
        cin>>n;
        if(n<=1)
        {
            cout<<"-1";
        }
        else
        {
            t=n;


            wei=0;
            while(t>7)
            {


                    t-=7;
                wei++;
            }

            wei++;
            x=n%7;
            if(x==0)


            {
                for(int i=1;i<=wei;i++)
                {
                    cout<<"8";
                }
            }
            if(x==1)
            {
                cout<<"10";

                for(int i=1;i<=wei-2;i++)
                {
                    cout<<"8";
                }
            }

            if(x==2)

            {
                cout<<"1";

                for(int i=1;i<=wei-1;i++)
                {
                    cout<<"8";
                }
            }

            if(x==3)

            {
                  cout<<"7";

                for(int i=1;i<=wei-1;i++)
                {
                    cout<<"8";
                }
            }

            if(x==4)
            {
                  cout<<"20";

                for(int i=1;i<=wei-2;i++)
                {
                    cout<<"8";
                }
            }
            if(x==5)

            {
                  cout<<"2";

                for(int i=1;i<=wei-1;i++)
                {
                    cout<<"8";
                }
            }
            if(x==6)

            {
                  cout<<"6";

                for(int i=1;i<=wei-1;i++)
                {
                    cout<<"8";
                }
            }
        }

        cout<<endl;
    }


    return 0;
}

