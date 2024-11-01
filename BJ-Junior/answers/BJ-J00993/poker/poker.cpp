#include<bits/stdc++.h>
using namespace std;
int t[14],t2[14],t3[14],t4[14];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        if(s[0]=='D') {
            if(s[1]=='A') {
                t[1]++;
            }else if(s[1]=='T') {
                t[10]++;
            }else if(s[1]=='J') {
                t[11]++;
            }else if(s[1]=='Q') {
                t[12]++;
            }else if(s[1]=='K') {
                t[13]++;
            }else {
                t[s[1]-'0']++;
            }
        }else if(s[0]=='C') {
            if(s[1]=='A') {
                t2[1]++;
            }else if(s[1]=='T') {
                t2[10]++;
            }else if(s[1]=='J') {
                t2[11]++;
            }else if(s[1]=='Q') {
                t2[12]++;
            }else if(s[1]=='K') {
                t2[13]++;
            }else {
                t2[s[1]-'0']++;
            }
        }else if(s[0]=='H') {
            if(s[1]=='A') {
                t3[1]++;
            }else if(s[1]=='T') {
                t3[10]++;
            }else if(s[1]=='J') {
                t3[11]++;
            }else if(s[1]=='Q') {
                t3[12]++;
            }else if(s[1]=='K') {
                t3[13]++;
            }else {
                t3[s[1]-'0']++;
            }
        }else {
            if(s[1]=='A') {
                t4[1]++;
            }else if(s[1]=='T') {
                t4[10]++;
            }else if(s[1]=='J') {
                t4[11]++;
            }else if(s[1]=='Q') {
                t4[12]++;
            }else if(s[1]=='K') {
                t4[13]++;
            }else {
                t4[s[1]-'0']++;
            }
        }
    }
    int cnt=0;

    for(int i=1;i<=13;i++) {
        if(t[i]==0) {
            cnt++;
        }
        if(t2[i]==0) {
            cnt++;
        }
        if(t3[i]==0) {
            cnt++;
        }
        if(t4[i]==0) {
            cnt++;
        }
    }
    cout<<cnt;

    return 0;
}
