#include <bits/stdc++.h>
using namespace std;
struct node
{
    char color,num;
} a[60];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].color>>a[i].num;
        for(int j=1;j<=i-1;j++)
        {
            if(a[i].color==a[j].color && a[i].num==a[j].num)
            {
                cnt++;
            }
        }
    }
    cout<<(52-n+cnt)<<endl;
    return 0;
}
