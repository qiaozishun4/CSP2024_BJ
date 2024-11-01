#include<iostream>
using namespace std;

    int a[100];
    int b[100];
    int c[100];
    int d[100];

int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);

    int n;
    cin>>n;
    char w;
    char y;
    for(int i=1;i<=n;i++){
        cin>>w;
        if(w=='D'){
            cin>>y;
           if(y=='A'){
            a[1]++;
           }else if(y=='T'){
            a[10]++;
           }else if(y=='J'){
            a[11]++;
           }else if(y=='Q'){
            a[12]++;
           }else if(y=='K'){
            a[13]++;
           }else if(y=='2'){
            a[2]++;
           }else if(y=='3'){
            a[3]++;
           }else if(y=='4'){
            a[4]++;
           }else if(y=='5'){
            a[5]++;
           }else if(y=='6'){
            a[6]++;
           }else if(y=='7'){
            a[7]++;
           }else if(y=='8'){
            a[8]++;
           }else if(y=='9'){
            a[9]++;
           }
        }
        if(w=='C'){
           cin>>y;
            if(y=='A'){
            b[1]++;
           }else if(y=='T'){
            b[10]++;
           }else if(y=='J'){
            b[11]++;
           }else if(y=='Q'){
            b[12]++;
           }else if(y=='K'){
            b[13]++;
           }else if(y=='2'){
            b[2]++;
           }else if(y=='3'){
            b[3]++;
           }else if(y=='4'){
            b[4]++;
           }else if(y=='5'){
            b[5]++;
           }else if(y=='6'){
            b[6]++;
           }else if(y=='7'){
            b[7]++;
           }else if(y=='8'){
            b[8]++;
           }else if(y=='9'){
            b[9]++;
           }
        }
        if(w=='H'){
           cin>>y;
           if(y=='A'){
            c[1]++;
           }else if(y=='T'){
            c[10]++;
           }else if(y=='J'){
            c[11]++;
           }else if(y=='Q'){
            c[12]++;
           }else if(y=='K'){
            c[13]++;
           }else if(y=='2'){
            c[2]++;
           }else if(y=='3'){
            c[3]++;
           }else if(y=='4'){
            c[4]++;
           }else if(y=='5'){
            c[5]++;
           }else if(y=='6'){
            c[6]++;
           }else if(y=='7'){
            c[7]++;
           }else if(y=='8'){
            c[8]++;
           }else if(y=='9'){
            c[9]++;
           }
        }
        if(w=='S'){
           cin>>y;
           if(y=='A'){
            d[1]++;
           }else if(y=='T'){
            d[10]++;
           }else if(y=='J'){
            d[11]++;
           }else if(y=='Q'){
            d[12]++;
           }else if(y=='K'){
            d[13]++;
           }else if(y=='2'){
            d[2]++;
           }else if(y=='3'){
            d[3]++;
           }else if(y=='4'){
            d[4]++;
           }else if(y=='5'){
            d[5]++;
           }else if(y=='6'){
            d[6]++;
           }else if(y=='7'){
            d[7]++;
           }else if(y=='8'){
            d[8]++;
           }else if(y=='9'){
            d[9]++;
           }

        }
    }
    int ans=52;
    for(int i=1;i<=53;i++){
        if(a[i]!=0){
            ans--;
        }
        if(b[i]!=0){
            ans--;
        }
        if(c[i]!=0){
            ans--;
        }
        if(d[i]!=0){
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
