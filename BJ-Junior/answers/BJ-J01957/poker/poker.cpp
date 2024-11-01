#include<iostream>
#include<string>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0,m;
    cin>>n;
    string a[n];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        m=1;
        for(int j=1;j<i;j++)
        {
            if(a[j]==a[i]) m=0;
        }
        cnt=cnt+m;
    }
    cout<<cnt;
}
