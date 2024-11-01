#include<bits/stdc++.h>
using namespace std;

int a[100010];
int flag[100010];
int cnt=0;
int k,y;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int T;
    cin>>T;

    for(int i=0;i<T;i++)
    {
        cin>>a[i];
        flag[i]=2;
    }
    sort(a,a+T);

    while(1)
    {
        int zx=-100,cx=-100;
        bool w=0,m=0;

        for(;k<T;k++)
        {
            if(flag[k]!=0)
            {
                zx=a[k];
                m=1;
                break;
            }
            m=0;
        }
        if(y<=k)
        {
            y=k+1;
        }
        for(;y<T;y++)
        {
            if(flag[y]==2&&a[y]>zx)
            {
                cx=a[y];
                w=1;
                flag[y]=1;//past no against
                flag[k]=0;//fail gone
                cnt++;

                break;
            }
            w=0;
        }

        if(w==0||m==0)
        {
            break;
        }

    }
    cout<<T-cnt;
    return 0;
}
