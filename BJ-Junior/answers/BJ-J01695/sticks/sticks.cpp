#include <iostream>
using namespace std;
const int N=100005;
const int stick[10]={6,2,5,5,4,5,6,3,7,6};
string dp[N];
bool bigger(string a,string b) {
    if(a[0]=='-') return 0;
    if(b[0]=='-') return 1;
    if(a.size()!=b.size()) return a.size()>b.size();
    for(int i=0;i<a.size();i++)  {
        if(a[i]>b[i]) return 1;
        if(b[i]>a[i]) return 0;
    }
    return 0;
}
int progress=8;
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    dp[1]="-1"; dp[2]="1"; dp[3]="7"; dp[4]="4"; dp[5]="2"; dp[6]="6"; dp[7]="8"; dp[8]="10";
    int n;
    cin>>n;
    while(n--) {
        int t;
        cin>>t;
        for(int i=progress+1;i<=t;i++) {
            dp[i]=dp[i-stick[0]]+'0';
            for(int j=1;j<=9;j++) {
                if(bigger(dp[i],dp[i-stick[j]]+char(j+'0'))) {
                    dp[i]=dp[i-stick[j]]+char(j+'0');
                }
            }
            //cout<<i<<" dp:"<<dp[i]<<endl;
        }
        cout<<dp[t]<<endl;
        progress=max(progress,t);
    }
    return 0;
}
