#include <iosteam>
using namespace std
int d[20],c[20],h[20],s[20],n,sum;
int main(){
    freopen("poker.in",'r',stdin);
    freopen("poker.out",'w',stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string a;
        int p=0;
        cin>>a;
        for(int i=0;i<=1;i++){
            if(a[1]=='S'||a[1]=='D'||a[1]=='C'||a[1]=='H'){
                swap(a[1],a[0]);
            }
        }

        if(a[1]=='A'){
            p=1;
        }
        else if(a[1]=='T'){
            p=10;
        }
        else if(a[1]=='J'){
            p=11;
        }
        else if(a[1]=='Q'){
            p=12;
        }
        else if(a[1]=='K'){
            p=13;
        }
        else{
            p=a[1]-'0';
        }
        if(a[0]=='D'){
            d[p]+=1;
        }
        if(a[0]=='C'){
            c[p]+=1;
        }
        if(a[0]=='H'){
            h[p]+=1;
        }
        if(a[0]=='S'){
            s[p]+=1;
        }
    }
    for(int i=1;i<=13;i++){
        if(d[i]<=1){
            sum++;
        }
        if(c[i]<=1){
            sum++;
        }
        if(h[i]<=1){
            sum++;
        }
        if(s[i]<=1){
            sum++;
        }
    }
    cout << sum;
    return 0;
}
