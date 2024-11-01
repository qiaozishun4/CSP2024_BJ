#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
int n;
set<string> st;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    while(n -- ){
        string s;
        cin >> s;
        st.insert(s);
    }
    int ans = st.size();
    printf("%d",52 - ans);
    return 0;
}
