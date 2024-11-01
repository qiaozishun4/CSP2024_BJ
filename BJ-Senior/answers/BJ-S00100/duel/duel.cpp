#include<iostream>
#include<ctime>
#include<cstdlib>
#include<set>
using namespace std;
set <long long int> st;
long long int r[100010]={0};
long long int b[100010]={0};//1->yigongji
long long int c[100010]={0};//1->taotai
long long int kkkkk=-1e18;
long long int ccccc=1e18;
long long int min1=ccccc;
long long int n=0;
void ooo(long long int f,long long int shengyu)
{
    long long int geshu=0;
    for(long long int j0=1;j0<=n;j0++)
    {
        if(b[j0]==1 && c[j0]==0)
        {
            geshu++;
        }
    }
    if(geshu==shengyu)
    {
        if(min1>shengyu)
        {
            min1=shengyu;
            //cout<<"min1="<<min1<<endl;
        }
    }
    if(f>n)
    {
        return;
    }
    //cout<<"shengyu="<<shengyu<<" geshu="<<geshu<<endl;
    long long int j1=f;
    for(long long int j2=1;j2<=n;j2++)
    {
        if(j2==j1)
        {
            continue;
        }
        else
        {
            if(c[j2]==0)
            {
                long long int cur=shengyu;
                //cout<<"f="<<f<<" k="<<j2<<" cur="<<cur<<endl;
                if(r[j1]>r[j2])
                {
                    cur--;
                    c[j2]=1;
                }
                b[j1]=1;
                //cout<<"i="<<j1<<" j="<<j2<<" shengyu="<<shengyu<<endl;
                ooo(f+1,cur);
                b[j1]=0;
                c[j2]=0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    long long int maxc=kkkkk;
    long long int cnt1=0;
    long long int oct2=0;
    for(long long int j1=1;j1<=n;j1++)
    {
        cin>>r[j1];
        if(r[j1]==1)
        {
            cnt1++;
        }
        else
        {
            if(r[j1]==2)
            {
                oct2++;
            }
        }
        maxc=max(maxc,r[j1]);
        st.insert(r[j1]);
    }
    long long int len=st.size();
    if(len==n)
    {
        cout<<1;
    }
    else
    {
        if(len==1)
        {
            cout<<n;
        }
        else
        {
            if(maxc<=2)
            {
                long long int ans=n-min(cnt1,oct2);
                cout<<ans;
            }
            else
            {
                ooo(1,n);
                cout<<min1;
            }
        }
    }
    return 0;
}
