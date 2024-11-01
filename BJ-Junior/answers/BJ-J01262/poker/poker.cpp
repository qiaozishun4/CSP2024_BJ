#include<bits/stdc++.h>
using namespace std;
int main()
{
     freopen("poker.in","r",stdin);
     freopen("poker.out","w",stdout);

     int n;
  
     char a[100];
    cin>>n;

    for(int  i=1;i<=n;i++)
    {
          cin>>a[i];
          
    }
    cout<<52-n;
}
