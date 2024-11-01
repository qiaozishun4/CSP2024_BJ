#include<bits/stdc++.h>
using namespace std;
const int N=1E5+1,oo=1E9+7;
int f[N],wh[N];
int P[7]={0,6,2,5,4,3,7},P1[7]={0,2,5,4,6,3,7};
vector<int> ans;
void Init(int x)
{
    f[0]=0;
    for(int i=1;i<=x;i++)
        f[i]=oo;
    memset(wh,0,sizeof(wh));
    ans.clear();
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n==2)
        {
            cout<<1<<endl;
            continue;
        }
        Init(n);
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=6;j++)
            {
                int w;
                if(w<=7)
                    w=P1[j];
                else
                    w=P[j];
                if(i-w<0)
                    continue;
                if(f[i-w]+1<f[i])
                {
                    f[i]=f[i-w]+1;
                    wh[i]=w;
                }
            }
        }
        if(f[n]==oo)
        {
            cout<<-1<<endl;
            continue;
        }
        int now=n;
        while(now>0)
        {
            ans.push_back(wh[now]);
            now-=wh[now];
        }
        int z=0;
        int flag=0;
        if(ans[z]==6)
           flag=1;
        for(int i:ans)
        {
            if(i==2)
                cout<<1;
            else if(i==3)
                cout<<7;
            else if(i==4)
                cout<<4;
            else if(i==5)
                cout<<2;
            else if(i==6 && !flag)
                cout<<0;
            else if(i==6 && flag)
                cout<<6;
            else if(i==7)
                cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
//0:6 1:2 2:5 3:5 4:4 5:5 6:6 7:3 8:7 9:6