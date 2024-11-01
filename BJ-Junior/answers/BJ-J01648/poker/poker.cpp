#include<iostream>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    char a[100][3]={};
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        int flag=1;
        for(int j=1;j<i;j++){
            if(a[i][0]==a[j][0]&&a[i][1]==a[j][1]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            cnt++;
        }
    }
    cout<<52-cnt;
    return 0;
}

