#include<iostream>
#include<string>
using namespace std;
int n,ans=0;
string a;
int arr[20][20]={};
void save(int c){
    if(a[1]=='A'){
        arr[c][1]=1;
    }else if(a[1]=='T'){
        arr[c][10]=1;
    }else if(a[1]=='J'){
        arr[c][11]=1;
    }else if(a[1]=='Q'){
        arr[c][12]=1;
    }else if(a[1]=='K'){
        arr[c][13]=1;
    }else{
        arr[c][a[1]-'0']=1;
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a[0]=='D'){
            save(1);
        }else if(a[0]=='C'){
            save(2);
        }else if(a[0]=='H'){
            save(3);
        }else if(a[0]=='S'){
            save(4);
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(arr[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
