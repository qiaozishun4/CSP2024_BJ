#include<iostream>
using namespace std;
bool b[100];
char c;
int a,n,cnt=52;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c;
        a=0;
        if(c=='C'){
            a=13;
        }
        else if(c=='H'){
            a=2*13;
        }
        else if(c=='S'){
            a=3*13;
        }
        cin>>c;
        if(c=='A'){
            a+=1;
        }
        else if(c=='T'){
            a+=10;
        }
        else if(c=='J'){
            a+=11;
        }
        else if(c=='Q'){
            a+=12;
        }
        else if(c=='K'){
            a+=13;
        }
        else{
            a+=(c-'0');
        }
        if(!b[a]){
            b[a]=true;
            cnt--;
        }
    }
    cout<<cnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
