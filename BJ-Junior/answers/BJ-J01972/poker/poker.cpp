#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n = 0;
    cin>>n;
    char poker[52][2];
    int ans = 52;
    if(n==1){
        cin>>poker[0];
        cout<<51;
        return 0;
    }
    int check = 0;
    for(int i = 0; i < n; i++){
        cin>>poker[i];
        //cout<<poker[i]<<endl;
        for(int j = 0; j < i; j++){
            if(poker[i][0]==poker[j][0]&&poker[i][1]==poker[j][1]){
                //cout<<poker[i][0]<<poker[i][1]<<" "<<poker[j]<<poker[j][1]<<endl;
                check++;
                break;
            }
            if(j==i-1){
                ans--;
            }
        }
    }
    if(check==0){
        cout<<52-n;
        return 0;
    }
    cout<<ans;
    return 0;
}
