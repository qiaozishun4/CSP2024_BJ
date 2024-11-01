#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
int n;
string s;
set<string> st;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    while(n--){
        cin >> s;
        st.insert(s);
    }
    cout << 52-st.size();
    return 0;
}