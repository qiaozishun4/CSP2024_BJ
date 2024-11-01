
#include<bits/stdc++.h>
using namespace std;
int t,m,c,leizhul;
long long leizhu,temp;
int arry[100000],n[7]={0,1,2,4,6,7,8},ns[7]={6,2,5,4,6,3,7};
bool flag;
void dg(int a,int l,int s)
{
    if(l>leizhul)
    {
        return;
    }
    if(a==0)
    {
        leizhul=l;
        temp=0;
        flag=1;
        c=0;
        for(int i=0;i<l;i++)
        {
            if(flag)
            {
            if(arry[i]!=0)
            {
                flag=0;
                temp=(long long)(arry[i]*pow(10,c));
                continue;
            }
            if(flag&&arry[i]==0)
            {
                c++;
                continue;
            }
            }
            temp=temp*10+arry[i];
        }
        if(temp==0)
        {
            return;
        }
        leizhu=min(leizhu,temp);
        if(leizhu==-1)
        {
            leizhu=temp;
        }
        return;
    }
    if(a<2)
    {
        return;
    }
    for(int i=s;i<7;i++)
    {
        arry[l]=n[i];
        dg(a-ns[i],l+1,i);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>m;
        leizhu=-1;
        leizhul=INT_MAX;
        dg(m,0,0);
        cout<<leizhu<<'\n';
    }
    return 0;
}