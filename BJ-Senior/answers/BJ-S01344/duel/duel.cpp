#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int r[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>r[i];
    sort(r,r+n);
    for(i=0,j=0;j<n;j++)
    {
        if(r[i]!=r[j])i++;
    }
    cout<<j-i;
    return 0;
}
