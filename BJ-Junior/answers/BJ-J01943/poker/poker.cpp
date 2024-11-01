#include<bits/stdc++.h>
using namespace std;

int n,cnt=0;
map<string,bool> m;
string t;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n-->0){
        
        cin>>t;
        if(!m[t]){
            m[t] = 1;
            cnt++;
        }
    }
    cout<<52-cnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}