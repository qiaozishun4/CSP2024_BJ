#include <bits/stdc++.h>
using namespace std;
set<int>se[4];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    //D C H S
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        char s,t;
        cin>>s>>t;
        int r;
        if(t>='2' && t<='9') r = t-'0';
        else if(t == 'A') r = 1;
        else if(t == 'T') r = 10;
        else if(t == 'J') r = 11;
        else if(t == 'Q') r = 12;
        else if(t == 'K') r = 13;
        if(s == 'D') se[0].insert(r);
        else if(s == 'C') se[1].insert(r);
        else if(s == 'H') se[2].insert(r);
        else if(s == 'S') se[3].insert(r);
    }
    cout<<52-se[0].size()-se[1].size()-se[2].size()-se[3].size();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
