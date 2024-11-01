#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e5+5,M=2e6+5;
struct node
{
    int inpos,inspd,addspd;
}a[N];
int n,T,totl,mxspd,ckpos[N],flag,m,ans,stopnum,mxckpos,_k,in[N],lv[N],ok[30],num1[M];
double checkspd(int carid,int pos)
{
    double runpos=pos-a[carid].inpos;
    if(runpos<0)
    {
        return 0.0;
    }
    return sqrt(1.0*a[carid].inspd*a[carid].inspd+2.0*runpos*a[carid].addspd);
}
int cnum1(int x)
{
    bitset <114> worker(x);
    return worker.count();
}
int count(int x)
{
    int res=0;
    for(int i=1;i<=n;i++)
    {
        ok[i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        if(x&(1<<i-1))
        {
            for(int j=1;j<=n;j++)
            {
                if(in[j]<=ckpos[i]&&ckpos[i]<=lv[j]&&ok[j]==0)
                {
                    ok[j]=1;
                    res++;
                }
            }
        }
    }
    return res;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    faster;
    cin >> T;
    for(int i=1;i<(1<<20)-1;i++)
	{
		num1[i]=cnum1(i);
	}
    while(T--)
    {
        mxckpos=0;_k=0;
        cin >> n >> m >> totl >> mxspd;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i].inpos >> a[i].inspd >> a[i].addspd; 
            flag=a[i].addspd;
        }
        for(int i=1;i<=m;i++)
        {
            cin >> ckpos[i];
            mxckpos=max(mxckpos,ckpos[i]);
        }
        stopnum=0;ans=0;
        if(n<=20&&m<=20)
        {  
            for(int i=1;i<=n;i++)
            {
                in[i]=lv[i]=0;
            }
            for(int i=1;i<=m;i++)
            {
                if(a[i].addspd==0&&a[i].inspd>mxspd)
                {
                    in[i]=a[i].inpos;
                    lv[i]=totl;
                }
                else if(a[i].addspd>0&&checkspd(i,totl)>mxspd)
                {
                    int l=a[i].inpos,r=totl;
                    while(l<=r)
                    {
                        int mid=l+r>>1;
                        if(checkspd(i,mid)>mxspd)
                        {
                            in[i]=mid;
                            r=mid-1;
                        }
                        else
                        {
                            l=mid+1;
                        }
                    }
                    lv[i]=totl;
                }
                else if(a[i].inspd>mxspd)
                {
                    in[i]=a[i].inpos;
                    int l=a[i].inpos,r=totl;
                    while(l<=r)
                    {
                        int mid=l+r>>1;
                        if(checkspd(i,mid)>mxspd)
                        {
                            lv[i]=mid;
                            l=mid+1;
                        }
                        else
                        {
                            r=mid-1;
                        }
                    }
                }
            }
            ans=count((1<<m)-1);
            for(int i=1;i<(1<<m)-1;i++)
            {
                if(m-num1[i]>stopnum&&count(i)==ans)
                {
                    stopnum=max(stopnum,m-num1[i]);
                }
            }
        }
        else if(flag>=0)
        {
            for(int i=1;i<=n;i++)
            {
                if(checkspd(i,mxckpos)>mxspd)
                {
                    ans++;
                }
            }
            stopnum=m-1;
        }
        if(ans==0)
        {
            stopnum=m;
        }
        cout << ans << ' ' << stopnum <<'\n';
    }
    return 0;
}
