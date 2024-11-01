#include<bits/stdc++.h>
using namespace std;
int n;
map<string,int> m;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin >> n;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        m[s]=i;
    }

    cout << 52-m.size();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
