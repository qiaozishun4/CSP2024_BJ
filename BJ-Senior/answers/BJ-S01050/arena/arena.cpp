#include<iostream>
using namespace std;
int n,m,a[100005],b[100005];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    cout<<b[0];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
