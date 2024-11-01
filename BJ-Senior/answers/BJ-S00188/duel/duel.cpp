#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x<y;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    int cnt=n;
    bool flag[100001];
    int tong[100001];
    int num[100001];
    int temp[100001]={};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
    }
    sort(num+0,num+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(num[i]<=num[j]&&temp[i]!=1&&i!=j)
            {
                cnt++;
                temp[i]=1;
                temp[j]=1;
            }
            else if(num[i]<num[j]&&temp[i]!=1&&i!=j)
            {
                cnt++;
                temp[i]=1;
                temp[j]=1;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
