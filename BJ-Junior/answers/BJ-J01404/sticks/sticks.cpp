#include<iostream>
#include<vector>
using namespace std;

int main()
{
  freopen("sticks.in","r",stdin);
  freopen("sticks.out","w",stdout);
  int t;
  cin>>t;
  for(int ii=0;ii<t;ii++)
  {
    int n,min;
    cin>>n;
    if(n==1)
    {
      cout<<"-1"<<endl;
      continue;
    }
    if(n%7==0)
    {
      for(int i=0;i<n/7;i++)
        cout<<8;
      return 0;
    }
    else
      min=n/7+1;
    vector<int>a(min);
    
    for(int j=1;j<=min;j++)
    {
      for(int i=2;i<=7;)
      {
       if(n-i<=(min-j)*7)
       {
         a[j-1]=i;
         n-=i;
         break;
       }
       if(i==2)
         i=5;
       if(i==5)
         i=4;
       if(i==4)
         i=6;
       if(i==6)
         i=3;
       if(i==3)
         i=7;
      }
    }
    
    for(int i=0;i<min;i++)
    {
      if(a[i]==2)
        cout<<1;
      else if(a[i]==3)
        cout<<7;
      else if(a[i]==4)
        cout<<4;
      else if(a[i]==5)
        cout<<2;
      else if(a[i]==6&&i!=0)
        cout<<0;
      else if(a[i]==6&&i==0)
        cout<<6;
      else if(a[i]==7)
        cout<<8;
    }
    cout<<endl;
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}