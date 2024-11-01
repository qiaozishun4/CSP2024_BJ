#include<bits/stdc++.h>
using namespace std;
string s[60];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        bool equ=1;
        for(int j=1;j<=i-1;j++){
            if(s[i]==s[j]){
                equ=0;
                break;
            }
        }
        if(equ) cnt++;
    }
    cout<<52-cnt;
    return 0;
}
