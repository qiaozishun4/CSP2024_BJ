#include<bits/stdc++.h>
using namespace std;
#define pt printf
#define fr(i,a,b) for(int i(a);i<=b;i++)
#define rf(i,a,b) for(int i(a);i>=b;i--)
#define eb emplace_back
#define pii pair<int,int>
#define file(f1,f2) if(f1!="")freopen(f1,"r",stdin);if(f2!="")freopen(f2,"w",stdout);
int n;
string s;
set<string>st;
signed main(){
    file("poker.in","poker.out");
    cin>>n;
    while(n--){
        cin>>s;
        st.insert(s);
    }
    pt("%d\n",52-st.size());
    return 0;
}
