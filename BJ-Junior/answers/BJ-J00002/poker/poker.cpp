#include<iostream>
using namespace std;
int n,ans=0;
int a[61];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        string t;
        int b;
        cin>>t;
        if(t[0]=='D'){
            b=0;
        }
        else if(t[0]=='C'){
            b=1;
        }
        else if(t[0]=='H'){
            b=2;
        }
        else{
            b=3;
        }
        b*=13;
        if(t[1]=='A'){
            b+=1;
        }
        else if(t[1]=='T'){
            b+=10;
        }
        else if(t[1]=='J'){
            b+=11;
        }
        else if(t[1]=='Q'){
            b+=12;
        }
        else if(t[1]=='K'){
            b+=13;
        }
        else{
            b+=t[1]-'0';
        }
        a[b]++;
    }
    for(int i=1;i<=52;i++){
        if(a[i]==0){
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
