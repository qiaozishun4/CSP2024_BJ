#include<bits/stdc++.h>
using namespace std;
long long int n, m;
char c;
long long int num;
string s;
int a[4][120];
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>s;
        c=s[0];
        m=s[1]-'0';

        if(c=='D') {
            if(a[0][m])continue;
            num++;
            a[0][m]=1;
        }
        else if(c=='C') {
            if(a[1][m])continue;
            num++;
            a[1][m]=1;
        }
        else if(c=='H') {
            if(a[2][m])continue;
            num++;
            a[2][m]=1;
        }
        else {
            if(a[3][m])continue;
            num++;
            a[3][m]=1;
        }

    }
    cout<<52-num;
    return 0;
}