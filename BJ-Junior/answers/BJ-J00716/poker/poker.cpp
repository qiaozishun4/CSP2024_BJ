#include<iostream>
using namespace std;
const int maxn=15;
int n,ans;
int s1[maxn],s2[maxn],s3[maxn],s4[maxn];
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        if(s[0]=='D') {
            if(s[1]=='A') s1[1]++;
            else if(s[1]=='T') s1[10]++;
            else if(s[1]=='J') s1[11]++;
            else if(s[1]=='Q') s1[12]++;
            else if(s[1]=='K') s1[13]++;
            else s1[s[1]-'0']++;
        }
        if(s[0]=='C') {
            if(s[1]=='A') s2[1]++;
            else if(s[1]=='T') s2[10]++;
            else if(s[1]=='J') s2[11]++;
            else if(s[1]=='Q') s2[12]++;
            else if(s[1]=='K') s2[13]++;
            else s2[s[1]-'0']++;
        }
        if(s[0]=='H') {
            if(s[1]=='A') s3[1]++;
            else if(s[1]=='T') s3[10]++;
            else if(s[1]=='J') s3[11]++;
            else if(s[1]=='Q') s3[12]++;
            else if(s[1]=='K') s3[13]++;
            else s3[s[1]-'0']++;
        }
        if(s[0]=='S') {
            if(s[1]=='A') s4[1]++;
            else if(s[1]=='T') s4[10]++;
            else if(s[1]=='J') s4[11]++;
            else if(s[1]=='Q') s4[12]++;
            else if(s[1]=='K') s4[13]++;
            else s4[s[1]-'0']++;
        }
    }
    for(int i=1;i<=13;i++) {
        if(s1[i]==0) ans++;
        if(s2[i]==0) ans++;
        if(s3[i]==0) ans++;
        if(s4[i]==0) ans++;
    }
    cout<<ans;
    return 0;
}
