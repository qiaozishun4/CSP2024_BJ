#include<iostream>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string a[60];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=0;
    bool flag;
    for(int i=0;i<n;i++){
        flag=1;
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            if(a[i]==a[j]&&i<j){
                flag=0;
                break;
            }
        }
        if(flag){
            cnt++;
        }
    }
    cout<<52-cnt;
    return 0;
}