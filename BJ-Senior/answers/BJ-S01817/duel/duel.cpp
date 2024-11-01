#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100009
using namespace std;
int n;
int a[N];
int b[N];
bool c[N];
bool d[N];
int tong[3];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    bool w=true;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]!=1 && a[i]!=2) w=false;
        else{
            tong[a[i]]++;
        }
    }
    if(w)
    {
        if(tong[1]>tong[2]) cout << n-tong[2] << endl;
        else cout<<tong[2]<<endl;
        return 0;
    }
    sort(a+1, a+n+1);

    int cnt=n;
    int cnt2=n;
    while(cnt2)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                 if(!c[i] && !b[j] && a[i]<a[j])
                {
                    c[i]=1;
                    b[j]=1;
                    d[i]=1;
                    d[j]=1;
                    if(!b[i]) cnt2-=2;
                    else cnt2--;
                    cnt--;
                    break;
                }
            }

        }
        bool status2=false;
        for(int i=1; i<n; i++)
        {
            if(!d[i] && !d[i+1] && a[i]!=a[i+1])
            {
                status2=true;
                break;
            }
        }
        if(status2==false)
        {
            break;
        }

    }
    cout<<cnt<<'\n';
    return 0;

}
