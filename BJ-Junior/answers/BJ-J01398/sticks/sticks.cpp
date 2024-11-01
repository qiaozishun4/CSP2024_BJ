#include<bits/stdc++.h>
using namespace std;
int digui(int* need,int num,int u,int l)
{
    if(u<0)
    {
        return INT_MAX;
    }
    if(u==0)
    {
        return num;
    }
    int a=0;
    if(l==1)
        a=1;
    int fmin=digui(need,num*10+a,u-need[i],l++);
    for(int i=a+1;i<10;i++)
    {
        int f=digui(need,num*10+i,u-need[i],l++);
        if(f<fmax)
        {
            fmin=f;
        }
    }
    return fmin;
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    int need[]={6,2,5,5,4,5,6,3,7,6}
    while(T--)
    {
        int use;
        cin>>use;
        int ans;
        ans=digui(need,0,use,1);
        cout<<digui<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
