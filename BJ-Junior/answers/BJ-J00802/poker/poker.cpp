#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    set<string> s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string st;
        cin>>st;
        s.insert(st);
    }
    cout<<52-s.size();


    fclose(stdin);
    fclose(stdout);
    return 0;
}
