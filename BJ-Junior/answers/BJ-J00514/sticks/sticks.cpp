#include <bits/stdc++.h>
using namespace std;
#define  ll long long

ll weishu;
ll num[10]={6,2,5,5,4,5,6,3,7,6};
ll ans[100005]={0};
void f(ll wei,ll n)
{
    if(n==1) return;
    if(wei==0) return;
    int j;
    for(j=0;j<10;j++)
   {
       if(n-num[j]<=(wei-1)*7)
       {
           ans[weishu-wei+1]=j;
           break;
       }
    }
     wei--;
    f(wei,n-num[j]);
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
  ll c;
  cin>>c;
   ll n[c];
   for(int i=0;i<c;i++)
        cin>>n[i];
    for(ll i=0;i<c;i++)
    {

       if(n[i]%7==0) weishu=n[i]/7;
       else weishu=n[i]/7+1;
        ll temp=weishu;
        for(int j=0;j<=weishu;j++)
        {
            ans[j]=0;
        }
       int k;
       for(k=1;k<10;k++)
       {
           if(n[i]-num[k]<=(weishu-1)*7)
           {
               ans[0]=k;
               break;
           }
       }
       weishu--;

       f(weishu,n[i]-num[k]);
       if(n[i]==1||n[i]==0)
       {
           cout<<-1<<endl;
       }
        else
        {
            for(int m=0;m<temp;m++)
            {
                cout<<ans[m];
            }
            cout<<endl;

        }

    }



   fclose(stdin);
   fclose(stdout);
    return 0;
}

