#include<iostream>
#include<cstdio>
using namespace std;
int a[5][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string s;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='D'){
            if(s[1]>='2'&&s[1]<='9'&&a[1][s[1]-'0']==0){
                a[1][s[1]-'0']=1;
                cnt++;
            }else if(s[1]=='A'&&a[1][1]==0){
                a[1][1]=1;
                cnt++;
            }else if(s[1]=='T'&&a[1][10]==0){
                a[1][10]=1;
                cnt++;
            }else if(s[1]=='J'&&a[1][11]==0){
                a[1][11]=1;
                cnt++;
            }else if(s[1]=='Q'&&a[1][12]==0){
                a[1][12]=1;
                cnt++;
            }else if(s[1]=='K'&&a[1][13]==0){
                a[1][13]=1;
                cnt++;
            }
        }else if(s[0]=='C'){
            if(s[1]>='2'&&s[1]<='9'&&a[2][s[1]-'0']==0){
                a[2][s[1]-'0']=1;
                cnt++;
            }else if(s[1]=='A'&&a[2][1]==0){
                a[2][1]=1;
                cnt++;
            }else if(s[1]=='T'&&a[2][10]==0){
                a[2][10]=1;
                cnt++;
            }else if(s[1]=='J'&&a[2][11]==0){
                a[2][11]=1;
                cnt++;
            }else if(s[1]=='Q'&&a[2][12]==0){
                a[2][12]=1;
                cnt++;
            }else if(s[1]=='K'&&a[2][13]==0){
                a[2][13]=1;
                cnt++;
            }
        }
        else if(s[0]=='S'){
            if(s[1]>='2'&&s[1]<='9'&&a[3][s[1]-'0']==0){
                a[3][s[1]-'0']=1;
                cnt++;
            }else if(s[1]=='A'&&a[3][1]==0){
                a[3][1]=1;
                cnt++;
            }else if(s[1]=='T'&&a[3][10]==0){
                a[3][10]=1;
                cnt++;
            }else if(s[1]=='J'&&a[3][11]==0){
                a[3][11]=1;
                cnt++;
            }else if(s[1]=='Q'&&a[3][12]==0){
                a[3][12]=1;
                cnt++;
            }else if(s[1]=='K'&&a[3][13]==0){
                a[3][13]=1;
                cnt++;
            }
        }else if(s[0]=='H'){
            if(s[1]>='2'&&s[1]<='9'&&a[4][s[1]-'0']==0){
                a[4][s[1]-'0']=1;
                cnt++;
            }else if(s[1]=='A'&&a[4][1]==0){
                a[4][1]=1;
                cnt++;
            }else if(s[1]=='T'&&a[4][10]==0){
                a[4][10]=1;
                cnt++;
            }else if(s[1]=='J'&&a[4][11]==0){
                a[4][11]=1;
                cnt++;
            }else if(s[1]=='Q'&&a[4][12]==0){
                a[4][12]=1;
                cnt++;
            }else if(s[1]=='K'&&a[4][13]==0){
                a[4][13]=1;
                cnt++;
            }
        }
    }
    cout<<52-cnt;
    return 0;
}
