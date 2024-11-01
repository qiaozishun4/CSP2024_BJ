#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=55;
map <string,int> m;
int n,ans;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        //printf("%c%c\n",s[0],s[1]);
        if(m[s]==0)
        {
            m[s]=1;
            ++ans;
        }
    }
    ans=52-ans;
    printf("%d",ans);
    return 0;
}
