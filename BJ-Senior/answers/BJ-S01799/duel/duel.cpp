#include<bits/stdc++.h>
using namespace std;
int b[100005];
bool cmp(int a,int c)
{
    return a>c;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int l;
        cin>>l;
        b[l]++;
    }
    sort(b+1,b+n+1,cmp);
    cout<<b[1]<<endl;
    return 0;
}
