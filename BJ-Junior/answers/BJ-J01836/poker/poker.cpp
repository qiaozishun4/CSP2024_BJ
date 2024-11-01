#include<bits/stdc++.h>
using namespace std;

long long n,b,sum;
string s;
bool a[60];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        b=0;
        if(s[1]=='A'){
            b=1;
        }else if(s[1]=='2'){
            b=5;
        }else if(s[1]=='3'){
            b=9;
        }else if(s[1]=='4'){
            b=13;
        }else if(s[1]=='5'){
            b=17;
        }else if(s[1]=='6'){
            b=21;
        }else if(s[1]=='7'){
            b=25;
        }else if(s[1]=='8'){
            b=29;
        }else if(s[1]=='9'){
            b=33;
        }else if(s[1]=='T'){
            b=37;
        }else if(s[1]=='J'){
            b=41;
        }else if(s[1]=='Q'){
            b=45;
        }else if(s[1]=='K'){
            b=49;
        }

        if(s[0]=='D'){
            b+=0;
        }else if(s[0]=='C'){
            b+=1;
        }else if(s[0]=='H'){
            b+=2;
        }else if(s[0]=='S'){
            b+=3;
        }
        a[b]=1;
    }
    for(int i=1;i<=52;i++){
        if(a[i]==0){
            sum++;
        }
    }
    cout<<sum;
    return 0;

}
