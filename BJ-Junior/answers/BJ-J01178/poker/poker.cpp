#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
int main(){
    FILE* f1=freopen("poker.in","r",stdin);
    FILE* f2=freopen("poker.out","w",stdout);
    int n,ans=52;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(!m[s]){
            ans--;
            m[s]=1;
        }
    }
    cout<<max(0,ans);
    fclose(f1);
    fclose(f2);
    return 0;
}
