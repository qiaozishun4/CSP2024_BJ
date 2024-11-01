#include <bits/stdc++.h>
#define _for(i,x,y) for(int i=x; i<=y; i++)
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
unordered_map<string,bool> p;
char f[100]={' ','D', 'C', 'H','S'};
char s[100]={' ','A' ,'2' ,'3','4' ,'5' ,'6' ,'7' ,'8' ,'9', 'T' ,'J' ,'Q' ,'K'};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    ll n,cnt=0;
    cin>>n;
    string st;
    _for(i,1,n){
        cin>>st;
        p[st]=1;
    }
    _for(i,1,4){
        _for(j,1,13){
            st="";
            st=st+f[i]+s[j];
//            cout<<st<<endl;
            if(!p[st]) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
