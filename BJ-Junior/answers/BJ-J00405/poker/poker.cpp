#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    set<pair<char,char> > s;
    for(int i = 1;i<=n;i++) {
        char a,b;
        cin>>a>>b;
        s.insert({a,b});
    }
    cout << 52 - s.size() << endl;
    return 0;
}
