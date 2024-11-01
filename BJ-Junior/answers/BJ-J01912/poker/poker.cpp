#include<bits/stdc++.h>
using namespace std;
int n,book[52]={},sum=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    //cout<<int('1');
    string s[55]={"DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK","CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK","HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK","SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"};//DCHS
    string a;

//    for(int i=1;i<=52;i++){
//        cout<<book[i];
//    }
     cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        for(int j=1;j<=52;j++){
            if(a==s[j]){
                    //cout<<"okokokokokokokokokokokokokokokok";
                    //cout<<j;

                    book[j]++;
                    break;
            }
        }
//
//        if(a=='A'){
//            book[1]=b;
//        }else if(a=='T'){
//            book[10]=b;
//        }else if(a=='J'){
//            book[11]=b;
//        }else if(a=='Q'){
//            book[12]=b;
//        }else{
//            book[int(a-48)]=[[b;
//        }
//
    }
//    for(int i=1;i<=n;i++){
//        if(book[i]==0){
//            sum++;
//            //cout<<"okokokokokokokokokokokokokokok";
//        }
//    }
    //cout<<book[39];
    //cout<<sum;
    cout<<52-n;
    return 0;
}
