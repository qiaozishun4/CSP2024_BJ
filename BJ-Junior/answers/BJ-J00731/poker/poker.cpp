#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n;
int a[100][100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(s[1]>='0'&&s[1]<='9'){
            s[1]-='0';
        }
        a[s[0]][s[1]]++;
    }
    char c='D';
    int cnt=0;
    for(int i=2;i<=9;i++){
        if(a[c][i]==0){
            cnt++;
        }
    }
    if(a[c]['A']==0){
        cnt++;
    }
    if(a[c]['T']==0){
        cnt++;
    }
    if(a[c]['J']==0){
        cnt++;
    }
    if(a[c]['Q']==0){
        cnt++;
    }
    if(a[c]['K']==0){
        cnt++;
    }

    c='C';
    for(int i=2;i<=9;i++){
        if(a[c][i]==0){
            cnt++;
        }
    }
    if(a[c]['A']==0){
        cnt++;
    }
    if(a[c]['T']==0){
        cnt++;
    }
    if(a[c]['J']==0){
        cnt++;
    }
    if(a[c]['Q']==0){
        cnt++;
    }
    if(a[c]['K']==0){
        cnt++;
    }

    c='H';
    for(int i=2;i<=9;i++){
        if(a[c][i]==0){
            cnt++;
        }
    }
    if(a[c]['A']==0){
        cnt++;
    }
    if(a[c]['T']==0){
        cnt++;
    }
    if(a[c]['J']==0){
        cnt++;
    }
    if(a[c]['Q']==0){
        cnt++;
    }
    if(a[c]['K']==0){
        cnt++;
    }

    c='S';
    for(int i=2;i<=9;i++){
        if(a[c][i]==0){
            cnt++;
        }
    }
    if(a[c]['A']==0){
        cnt++;
    }
    if(a[c]['T']==0){
        cnt++;
    }
    if(a[c]['J']==0){
        cnt++;
    }
    if(a[c]['Q']==0){
        cnt++;
    }
    if(a[c]['K']==0){
        cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
