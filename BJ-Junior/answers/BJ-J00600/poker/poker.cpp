#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("poker","r",stdin);
freopen("poker","w",stdout);
int n;
cin>>n;
char a[53],b[53];
for(int i=0;i<n;i++)
{
    cin>>a[i];
    cin>>b[i];
}
int y=n;
for(int i=0;i<n;i++)
{
    for(int j=i;j<n;j++)
    {
        if(a[i]==a[j]&&b[i]==b[j]&&a[i]!='0')
        {
            y--;
            a[j]='0';
        }
    }
}
cout<<y;
return 0;
}