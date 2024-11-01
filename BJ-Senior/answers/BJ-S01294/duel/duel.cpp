#include <bits/stdc++.h>
using namespace std;
int a[100005],x,cnt,n;
bool flag[100005][2];
bool cmp(int a,int b)
{
    return a>b;
}
int qwe (int x)
{
    for(int i=x;i<=n;i++)
    {
        if(flag[i][1]==true&&a[x]>a[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        flag[i][1]=true;//flag[1]生命
        flag[i][2]=true;
        x++;
        cnt++;
    }
    sort(a+1,a+n+1,cmp);
    //
    //for(int i=1;i<=n;i++)
    //{
        //cout<<a[i]<<" ";
    //}
    //cout<<endl;
    //
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1])
        {
            flag[i][2]=0;
            flag[i-1][1]=0;
            //
            //cout<<"qwe"<<i-1<<" ";
            //
            x--;
            cnt--;
            if(flag[i-1][2]==true)
            {
                flag[i-1][2]=0;
                x--;
            }
            if(x==0)
            {
                break;
            }
        }
        else if(qwe(i)!=-1&&flag[i][2]==true)
        {
            flag[i][2]=0;
            flag[qwe(i)][1]=0;
            //
            //cout<<"qwe"<<i-1<<" ";
            //
            if(flag[qwe(i)][2]==true)
            {
                flag[qwe(i)][2]=0;
                x--;
            }
            x--;
            cnt--;
        }
        if(x==0)
        {
            break;
        }
    }
    cout<<cnt+1;
    return 0;
}
