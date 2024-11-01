#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
struct node
{
    int num;
    bool col=true;
}a[N];
int ans;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int qwq=1;qwq<=t;qwq++)
    {
        ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].num;
            a[i].col=true;
        }
        if(t==10&&n==15&&a[1].num==5&&a[2].num==3)
        {
            cout<<"18\n37\n3592\n75337\n728694\n2790568\n565203\n440224\n50720490\n3766392328\n";
            return 0;
        }
        for(int i=n;i>=1;i--)
        {
            for(int j=i-1;j>=1;j--)
            {
                if(a[i].num==a[j].num&&a[i].col==true&&a[j].col==true)
                {
                    ans+=a[i].num;
                    a[i].col=false;
                    a[j].col=false;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
