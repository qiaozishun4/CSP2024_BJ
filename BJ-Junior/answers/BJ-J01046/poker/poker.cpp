#include<bits/stdc++.h>
using namespace std;
int n;
int sum=52;
bool c[125][125];
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(c[s[0]][s[1]]==0){
            sum--;
            c[s[0]][s[1]]=1;
        }
    }
    cout<<sum;
    return 0;
}
