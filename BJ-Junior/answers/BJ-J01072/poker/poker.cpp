#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string tt;
int n, cnt=0;
bool d[101], c[101], h[101],s[101];
int main () {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> tt;
        int t;
        t=tt[1]-'0';
        //cout <<tt[1] << endl<< endl;
        if (tt[1]=='A') t=1;
        if (tt[1]=='T') t=10;
        if (tt[1]=='J') t=11;
        if (tt[1]=='Q') t=12;
        if (tt[1]=='K') t=13;
        if(tt[0]=='D')
        {
            d[t]=true;
            //cout << 'D' << endl << t << endl;
        }

        if(tt[0]=='S') {
            s[t]=true;
            //cout << 's' << endl << t << endl;
        }

        if(tt[0]=='H'){
            h[t]=true;
            //cout << 'h' << endl << t << endl;
        }
        if(tt[0]=='C') {
            c[t]=true;
            //cout << 'c' << endl << t << endl;
        }
    }
    for (int i=1;i<=13;i++) {
        if (!s[i]) cnt++;
        if (!d[i]) cnt++;
        if (!h[i]) cnt++;
        if (!c[i]) cnt++;
    }
    cout << cnt;
    return 0;
}
