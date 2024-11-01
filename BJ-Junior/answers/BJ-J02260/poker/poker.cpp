#include<bits/stdc++.h>
using namespace std;
int n;
int a[15];
int b[15];
int c[15];
int d[15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char temp1,temp2;
        cin>>temp1>>temp2;
        if(temp1=='D'){
            if(temp2=='A')a[1]=1;
            else if(temp2=='T')a[10]=1;
            else if(temp2=='J')a[11]=1;
            else if(temp2=='Q')a[12]=1;
            else if(temp2=='K')a[13]=1;
            else a[temp2-'0']=1;
        }
        else if(temp1=='C'){
            if(temp2=='A')b[1]=1;
            else if(temp2=='T')b[10]=1;
            else if(temp2=='J')b[11]=1;
            else if(temp2=='Q')b[12]=1;
            else if(temp2=='K')b[13]=1;
            else b[temp2-'0']=1;
        }else if(temp1=='H'){
            if(temp2=='A')c[1]=1;
            else if(temp2=='T')c[10]=1;
            else if(temp2=='J')c[11]=1;
            else if(temp2=='Q')c[12]=1;
            else if(temp2=='K')c[13]=1;
            else c[temp2-'0']=1;
        }else{
            if(temp2=='A')d[1]=1;
            else if(temp2=='T')d[10]=1;
            else if(temp2=='J')d[11]=1;
            else if(temp2=='Q')d[12]=1;
            else if(temp2=='K')d[13]=1;
            else d[temp2-'0']=1;
        }
    }
    int ans=52;
    for(int i=1;i<=13;i++){
        if(a[i]){
            ans--;
        }
        if(b[i]){
            ans--;
        }
        if(c[i]){
            ans--;
        }
        if(d[i]){
            ans--;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

