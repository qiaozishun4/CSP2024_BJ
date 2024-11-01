#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
bool b[100005];
bool cmp(int a1,int a2)
{
    return a1<a2;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;int num=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
		int j=i+1;
		while(j<=n)
		{
			if(!b[j]&&a[j]>a[i])
			{
				b[j]=1;
				num++;
				break;
			}
			j++;
		}
	}
    cout<<n-num<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
