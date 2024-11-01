#include <iostream>
#include <fstream>
using namespace std;
int x(char in){
    if(in=='D'){
        return 0;
    }else if(in=='C'){
        return 1;
    }else if(in=='H'){
        return 2;
    }else{
        return 3;
    }
}
int y(char in){
    if(in>='2' && in<='9'){
        return in-'0';
    }else if(in=='T'){
        return 10;
    }else if(in=='J'){
        return 11;
    }else if(in=='Q'){
        return 12;
    }else{
        return 13;
    }
}
int n,ans=0;
bool a[13][4];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        string p;
        cin>>p;
        char u=p[0],v=p[1];
        a[x(u)][y(v)]=true;
    }
    for(int i=0;i<13;i++){
        for(int j=0;j<4;j++){
            if(a[i][j]==false){
                ans++;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
