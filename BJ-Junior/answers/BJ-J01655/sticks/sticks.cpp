#include <bits/stdc++.h>
#define ll long long
using namespace std;

int shu[10]={6,2,5,5,4,5,6,3,7,6};
ll amin=1e12;
int h=0;

void dfs(int n,string sum)
{
    if(n==0)
    {

        if(sum[1]=='0')
            return;
        else
            {
                ll asum=0;
                for(int i=1;i<sum.size();i++)
                    asum=asum*10+(ll)(sum[i]-'0');
                amin=min(asum,amin);
                return;
            }


    }
    for(int i=0;i<=9;i++)
    {
        int k=sum.size()-1;
        if(n>=shu[i])
        {

           for(int j=0;j<sum.size();j++)
           {

                if(i<=sum[j]-'0')
                {
                    k=j;
                    break;
                }
            }
            string y;
            for(int xunhuan=0;xunhuan<=k;xunhuan++)
            {
                y+=sum[xunhuan];
            }
                char opq=('0'+i);
                y+=opq;

            for(int xunhuan=k+1;xunhuan<sum.size();xunhuan++)
            {
                y+=sum[xunhuan];
            }

        dfs(n-shu[i],y);
           }

        }
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
    dfs(n,"0");
    if(amin==1e12)
        cout<<-1<<endl;
    else
        cout<<amin<<endl;

    amin=1e12;

}
}
