#include<bits/stdc++.h>
using namespace std;
int a[100010],use[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int last=0;
    for(int i=1; i<=n; i++)
    {
        bool flag=1;
        //cout<<last<<endl;
        if(a[i]!=a[i-1]||i==1)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(a[i]<a[j]&&!use[j])
                {
                    flag=0;
                    use[j]=1;
                    last=j;
                    break;
                }
            }
        }
        else
        {
            last++;
            if(last<=n)
            {
                flag=0;
                use[last]=1;
            }
        }
        if(flag)
        {
            cout<<n-i+1<<endl;
            return 0;
        }
    }
}
