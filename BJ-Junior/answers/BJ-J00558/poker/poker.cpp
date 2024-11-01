#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;

int n;
string s[60];
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    sort(s+1,s+1+n);
    ans=n;
    for(int i=1;i<=n;i++)if(s[i]==s[i-1])ans--;
    cout<<52-ans;
    return 0;
}
