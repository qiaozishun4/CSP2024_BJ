#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
int n;
string t;
set<string> s;
int main(){
    freopen("pocker.in","r",stdin);
    freopen("pocker.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        s.insert(t);
    }
    cout<<52-s.size();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
