#include <bits/stdc++.h>
using namespace std;
int n;
string s[55];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","W",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>s[i];
    int num=52-n;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j]) num++;
        }
    }
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}