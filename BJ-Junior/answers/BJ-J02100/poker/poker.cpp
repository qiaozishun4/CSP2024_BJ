#include <bits/stdc++.h>
using namespace std;
int n;
set<string> s;
string x;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        s.insert(x);
    }
    cout<<(52-int(s.size()))<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
