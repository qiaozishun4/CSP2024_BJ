#include<bits/stdc++.h>
using namespace std;
char a[60],b[60];
int n,sum;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    //freopen("poker.in","w",stdout);
    cin>>n;
    sum=52-n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]==a[j]&&b[i]==b[j])
            {
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
/*
4
DQ
H3
DQ
DT
*/
