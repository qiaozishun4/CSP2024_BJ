#include<fstream>
#include<algorithm>

using namespace std;

ifstream cin("color.in");
ofstream cout("color.out");

int T,n,arr[100001];

int meiju(int r[],int b[],int sr,int sb,int s){
    if(sr+sb<n){
        int numr,numb;
        r[sr]=arr[sr+sb];
        numr=meiju(r,b,sr+1,sb,r[sr]==r[sr-1]?s+r[sr]:s);
        b[sb]=arr[sr+sb];
        numb=meiju(r,b,sr,sb+1,b[sb]==b[sb-1]?s+b[sb]:s);
        if(numr>=numb)return numr;
        return numb;
    }
    return s;
}

int main(){
    cin>>T;
    while(T--){
        cin>>n;
        int r[100001],b[100001];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        r[0]=arr[0];
        cout<<meiju(r,b,1,0,0)<<endl;
    }
    return 0;
}