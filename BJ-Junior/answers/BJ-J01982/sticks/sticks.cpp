#include<bits/stdc++.h>
using namespace std;
#define LL long long
//LL f[100005];
LL n,bl[]={8,0,6,9,2,3,5,4,7,1},c[]={0,1,2,3,4,5,6,7,8,9},w[]={6,2,5,5,4,5,6,3,7,6};
/*
void dfs(LL num,LL canuse)
{
    printf("num:%lld canuse:%lld\n",num,canuse);
    if(num>ans)
    {
        //printf("%lld>%lld\n",num,ans);
        return ;
    }
    if(canuse<=0)
    {
        if(canuse==0)
            ans=min(ans,num);
            //printf("ans:%lld\n",ans);
        return ;
    }
    for(int i=0;i<10;i++)
    {
        dfs(num*10+bl[i],canuse-w[bl[i]]);
    }
}
*/
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    //open that


    //start the freopen when you end the match
    //need to know : unsigned
    LL t,i,j,x,y,maxl,ans;
    string strans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%7==0)
        {
            for(i=1;i<=n/7;i++)
                cout<<8;
            cout<<'\n';
            continue;
        }
        if((n-1)%7==0)
        {
            cout<<10;
            for(i=1;i<=(n-1)/7-1;i++)
                cout<<8;
            cout<<'\n';
            continue;
        }
        x=n;
        strans="";
        for(i=0;i<=9;i++)
        {
            if(strans==""&&bl[i]==0)continue;
            //printf("i:%lld\n",i);
            while(x>=w[bl[i]])
            {
                x-=w[bl[i]];
                strans=char(bl[i]+'0')+strans;
            }
        }
        maxl=strans.length();
        ans=0x7fffffff;
    //printf("%lld\n",maxl);
        for(i=pow(10,maxl-1);i<=pow(10,maxl+1)-1;i++)
        {
            if(i==0)continue;
            x=i,y=0;
            while(x)
            {
                y+=w[x%10];
                x/=10;
            }
            if(y==n)
            {
                //printf("%lld:%lld\n",i,y);
                ans=min(ans,i);
            }
        }
        if(ans==0x7fffffff)cout<<"-1\n";
        else cout<<ans<<'\n';

        /*
        memset(f,0x7fffffff,sizeof(f));
        for(i=0;i<=9;i++)
            for(j=w[i];j<=n;j++)
                if(!(i==0&&f[j]==0x7fffffff))
                {
                    f[j]=min(f[j],(f[j-w[i]]==0x7fffffff)?0:f[j-w[i]]+c[i]);
                    printf("i:%lld j:%lld f:%lld\n",i,j,f[j]);
                }

        cout<<f[n]<<'\n';
        */
        /*
        ans=0x7fffffff;
        for(i=pow(10,floor(n*1.0/7));i<=pow(10,floor(n*1.0/7)+1);i++)
        {
            if(i==0)continue;
            x=i,y=0;
            while(x)
            {
                y+=w[x%10];
                x/=10;
            }
            if(y==n)ans=min(ans,i);
        }
        if(ans==0x7fffffff)cout<<-1<<'\n';
        else cout<<ans<<'\n';
        */
        /*
        for(i=0;i<=9;i++)
            if(bl[i]!=0)
                dfs(bl[i],n-w[bl[i]]);
        */
        //if(ans==2*pow(2,50))cout<<"-1\n";
        //else cout<<ans<<'\n';
        //cout<<ans<<'\n';
    }
    return 0;
}
