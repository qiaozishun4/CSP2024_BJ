#include <bits/stdc++.h>
using namespace std;
int num=52;
int n;
string s;
int a[256][256];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(a[s[0]][s[1]]==0){
            a[s[0]][s[1]]++;
            num--;
        }
    }
    cout<<num<<endl;
    return 0;
}
