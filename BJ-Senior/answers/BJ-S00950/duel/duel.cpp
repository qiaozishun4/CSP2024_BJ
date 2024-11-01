#include<bits/stdc++.h>
using namespace std;
int a[100002];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int head=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>a[head])
            head++;
    }
    cout<<n-head<<endl;
    return 0;
}