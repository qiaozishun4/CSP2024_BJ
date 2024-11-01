#include<iostream>
using namespace std;
int n=0;
char hua[100]={};
char dian[100]={};
int cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>hua[i];
        cin>>dian[i];
    }
    for(int i=0;i<n;i++){
         for(int j=0;n>j>i;j++){
            if(hua[i]==hua[j]&&dian[i]==dian[j]&&i!=j){
                cnt++;
            }
        }
    }
    cout<<52-n+cnt;
    return 0;
}
