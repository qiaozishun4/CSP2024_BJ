#include<bits/stdc++.h>
using namespace std;
int n, sum;
string s[100];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin>>n;
    sum = 52 - n;
    for(int i= 0; i < n; i++){
        cin>>s[i];
    }
    if(n == 1){
        cout<<51<<endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(s[i] == s[j]){
                sum++;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
