#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
ifstream fin("poker.in");
ofstream fout("poker.out");
int b[105],c[105];
int main(){
    memset(b,0,sizeof b);
    int n,ans=0;
    string a;
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>a;
        if(a[0]=='S'){
            b[i]+=13;
        }else if(a[0]=='H'){
            b[i]+=26;
        }else if(a[0]=='D'){
            b[i]+=39;
        }
        if(a[1]=='A'){
            b[i]+=1;
        }else if(a[1]>'1' && a[1]<='9'){
            b[i]+=int(a[1]-'0');
        }else if(a[1]=='T'){
            b[i]+=10;
        }else if(a[1]=='J'){
            b[i]+=11;
        }else if(a[1]=='Q'){
            b[i]+=12;
        }else if(a[1]=='K'){
            b[i]+=13;
        }
    }
    for(int i=1;i<=n;i++){
        c[b[i]]++;
    }
    for(int i=1;i<=52;i++){
        if(c[i]==0){
            ans++;
        }
    }
    fout<<ans;
    return 0;
}
