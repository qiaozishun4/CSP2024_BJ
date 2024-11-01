#include<bits/stdc++.h>
using namespace std;
int a[5][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int shu;
        if(s[1]=='A'){
            shu=1;
        }else if(s[1]=='T'){
            shu=10;
        }else if(s[1]=='J'){
            shu=11;
        }else if(s[1]=='Q'){
            shu=12;
        }else if(s[1]=='K'){
            shu=13;
        }else{
            shu=s[1]-48;
        }
        if(s[0]=='C'){
            a[0][shu]++;
        }else if(s[0]=='S'){
            a[1][shu]++;
        }else if(s[0]=='H'){
            a[2][shu]++;
        }else{
            a[3][shu]++;
        }
    }
    int sum=0;
    for(int i=0;i<4;i++){
        for(int j=1;j<=13;j++){
            if(!a[i][j]){
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}