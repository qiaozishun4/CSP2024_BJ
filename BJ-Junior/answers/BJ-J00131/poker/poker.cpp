#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,a,b) for(int i=a;i>=b;i--)
#define push_back pb
#define make_pair mkp
int n;
string s;
set<string> st;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    FOR(i,1,n){
        cin>>s;
        st.insert(s);
    }
    cout<<52-st.size();
    return 0;
}
