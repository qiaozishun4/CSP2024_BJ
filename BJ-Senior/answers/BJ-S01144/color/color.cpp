#include<bits/stdc++.h>

using namespace std;
int n;
struct cl{
    int z;
    char c;
}a[200005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int cnt=0;
        cin>>n;
        for(int i = 0 ; i < n ; i++)
        {
            cin>>a[i].z;
            cnt+=a[i].z;
        }
        srand(time(0));
        cout<<rand()%cnt;
    }
    return 0;
}
