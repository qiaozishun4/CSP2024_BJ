#include<bits/stdc++.h>
using namespace std;
int n;
bool t[5][20];
string a;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        int f,p;
        if(a[0]=='D'){
            f=1;
        }else if(a[0]=='C'){
            f=2;
        }else if(a[0]=='H'){
            f=3;
        }else{
            f=4;
        }
        if(a[1]=='A'){
            t[f][1]=1;
        }else if(a[1]>='2'&&a[1]<='9'){
            t[f][a[1]-'0']=1;
        }else if(a[1]=='T'){
            t[f][10]=1;
        }else if(a[1]=='J'){
            t[f][11]=1;
        }else if(a[1]=='Q'){
            t[f][12]=1;
        }else{
            t[f][13]=1;
        }

    }
    int sum=0;
    for(int i=1;i<=13;i++){
        for(int j=1;j<=4;j++){
            if(!t[j][i]){
                sum++;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
