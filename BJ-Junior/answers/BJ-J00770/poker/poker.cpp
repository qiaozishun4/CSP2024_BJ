#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
int P[200][200],n,ans;
string s;
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin>>n;
    forr(i,1,n) {
        cin>>s;
        P[s[0]][s[1]] ++;
    }
    forr(i,2,9) if(P['D'][i+'0']==0) ++ans;
    forr(i,2,9) if(P['C'][i+'0']==0) ++ans;
    forr(i,2,9) if(P['H'][i+'0']==0) ++ans;
    forr(i,2,9) if(P['S'][i+'0']==0) ++ans;

    if(P['D']['A']==0) ++ans;
    if(P['D']['T']==0) ++ans;
    if(P['D']['J']==0) ++ans;
    if(P['D']['Q']==0) ++ans;
    if(P['D']['K']==0) ++ans;

    if(P['C']['A']==0) ++ans;
    if(P['C']['T']==0) ++ans;
    if(P['C']['J']==0) ++ans;
    if(P['C']['Q']==0) ++ans;
    if(P['C']['K']==0) ++ans;

    if(P['S']['A']==0) ++ans;
    if(P['S']['T']==0) ++ans;
    if(P['S']['J']==0) ++ans;
    if(P['S']['Q']==0) ++ans;
    if(P['S']['K']==0) ++ans;

    if(P['H']['A']==0) ++ans;
    if(P['H']['T']==0) ++ans;
    if(P['H']['J']==0) ++ans;
    if(P['H']['Q']==0) ++ans;
    if(P['H']['K']==0) ++ans;

    cout << ans;




    return 0;
}

