#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    string s[100];
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    int cnt=52;
    for(int i=0;i<n;i++){
        cnt--;
        //cout<<1;
        for(int j=0;j<i;j++){
            if(s[i][0]==s[j][0]&&s[i][1]==s[j][1]){cnt++;/*cout<<endl<<s[i]<<" "s[j]<<endl;*/}
        }
    }
    cout<<cnt;
    return 0;
}
