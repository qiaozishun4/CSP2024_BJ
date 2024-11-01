#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    unordered_set<string> us;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        us.insert(s);
    }
    cout<<52-us.size();
    fclose(stdin);
    fclose(stdout);
    return 0;
}