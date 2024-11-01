#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string str;
    int cnt=0;
    int num=52;
    for(int i=1;i<=n;i++){
        cin>>str;
    }
    for(int i=1;i<=n;i++){
        if(str[i]!=str[i+1]){
            cnt=num-n;
        }else{
            cnt=num-n;
            cnt+=1;
        }
    }
    cout<<cnt;
    return 0;
}