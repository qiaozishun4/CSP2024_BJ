#include<bits/stdc++.h>
using namespace std;
char a[100005];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n=0,m=0,s=0;
    cin>>n;
    int sum=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
    }
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=n;j++)
        {
            if(i==j) s+=1;
            if(a[i]==a[j] && s==0)
            {
                sum-=1;
                m+=1;
            }
        }
    }
    m=m%2;
    sum+=m;
    cout<<52-sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
