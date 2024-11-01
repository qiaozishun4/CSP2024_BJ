#include<bits/stdc++.h>
using namespace std;
string s[10010];
bool cap(string x,string y)
{
    if(x!=y)return x<y;
}
int main()
{
    //freopen("poker.in","r",stdin);
    //freopen("poker.out","r",stdout);

    int n;
    cin >> n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin >> s[i];
    }
    sort(s+1,s+n+1,cap);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(s[i]==s[j])
            {
                ans++;
            }
            else
            {
                ans=0;
            }
        }
    }
    int sum=53-n+ans;
    cout << sum;
    return 0;

}
