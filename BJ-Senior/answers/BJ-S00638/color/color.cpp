#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int n;
        cin>>n;
        long long a[200005]={0};
        int t=1;
        double co[200005]={'0'};
        for(int j=0;j<n;j++)
        {
           cin>>a[j];
        }
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {

                if(a[k]==a[j])
                {
                    t++;
                    if(t%2==0)
                    {
                        co[j]='r';
                        co[k]='r';
                    }
                    else
                    {
                        co[j]='b';
                        co[k]='b';
                    }
                }

            }
        }
        int cnt=0;
        for(int j=n-1;j>=1;j--)
        {
            for(int k=j-1;k>=0;k--)
            {
                if(co[k]==co[j]&&co[k]!=0)
                {
                    cnt+=a[j];
                }
            }
        }

        cout<<cnt<<endl;
        cnt=0;
    }
    return 0;
}
