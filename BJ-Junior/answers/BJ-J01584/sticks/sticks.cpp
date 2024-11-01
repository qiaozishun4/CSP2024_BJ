#include <bits/stdc++.h>
using namespace std;
int m[11]={6,2,5,5,4,5,6,3,7,6};
int mm[8]={0,1,2,6,8};
int main()
{
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);
int t;
cin>>t;
for(int i=0;i<t;i++)
    {
    int n;
    cin>>n;
    if(n<2)
    {
        cout<<-1<<endl;
    }
    else
    {
        if(n<=7)
        {
            int j;
            for(int k=1;k<10;k++)
            {
                if(m[k]==n)
                {
                    j=k;
                    break;
                }
            }
            cout<<j<<endl;
        }
        else
        {
            int j=n/7;
          if(n%7==0)
          {
              for(int i=0;i<j;i++)
              {
                  cout<<8;
              }
          }
                    if(n%7==1)
          {
              cout<<16;
              for(int i=0;i<j-1;i++)
              {
                  cout<<8;
              }
          }
                              if(n%7==2)
          {
              cout<<18;
              for(int i=0;i<j-1;i++)
              {
                  cout<<8;
              }
          }
                              if(n%7==3)
          {
              cout<<22;
              for(int i=0;i<j-1;i++)
              {
                  cout<<8;
              }
          }
                                        if(n%7==4)
          {
              cout<<20;
              for(int i=0;i<j-1;i++)
              {
                  cout<<8;
              }
          }
                                        if(n%7==5)
          {
              cout<<28;
              for(int i=0;i<j-1;i++)
              {
                  cout<<8;
              }
          }
                                        if(n%7==6)
          {
              cout<<68;
              for(int i=0;i<j-1;i++)
              {
                  cout<<8;
              }
          }
          cout<<endl;
        }
        }
    }
    return 0;
}
