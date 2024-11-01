#include<iostream>
#include<algorithm>
using namespace std;
int n,r[100005],cnt=0,tong[100005],_max=-2147483640;
bool flag[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>r[i];
        tong[r[i]]++;
    }
    for(int i=0;i<100005;i++)
    {
        if(tong[i]==n)
        {
            cout<<tong[i];
            return 0;
        }
    }
    for(int i=0;i<n;i+=2)
    {

        if(flag[i]==false)
        {
            if(r[i]<r[i+1])
            {
                cnt++;
                flag[i+1]=true;
            }
            else if(r[i]==r[i+1])
            {
                cnt+=2;
                flag[i]=true;
                flag[i+1]=true;
            }
            else if(r[i]>r[i+1])
            {
                cnt++;
                flag[i]=true;
            }
        }
    }
    if(n%2!=0)
    {
        cout<<cnt-1;
    }
   else
        cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
