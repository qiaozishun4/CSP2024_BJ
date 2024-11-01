#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
long long int a[200010]={0};
long long int c[200010]={0};
long long int r[200010]={0};
long long int kkkkk=-1e18;
long long int max1=kkkkk;
long long int n=0;
void ooo1(long long int f)
{
    if(f>n)
    {
        long long int sum=0;
        for(long long int j1=1;j1<=n;j1++)
        {
            c[j1]=0;
            for(long long int j2=j1-1;j2>=1;j2--)
            {
                if(r[j1]==r[j2])
                {
                    if(a[j1]==a[j2])
                    {
                        c[j1]=a[j1];
                        break;
                    }
                    else
                    {
                        c[j1]=0;
                        break;
                    }
                }
            }
            sum+=c[j1];
        }
        max1=max(max1,sum);
    }
    else
    {
        r[f]=0;//red
        ooo1(f+1);
        r[f]=1;//blue
        ooo1(f+1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    long long int t=0;
    cin>>t;
    for(long long int j0=1;j0<=t;j0++)
    {
        cin>>n;
        for(long long int j1=1;j1<=n;j1++)
        {
            cin>>a[j1];
        }
        max1=kkkkk;
        ooo1(1);
        cout<<max1<<endl;
    }
    return 0;
}


