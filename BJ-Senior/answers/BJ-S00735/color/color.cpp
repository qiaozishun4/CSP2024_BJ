#include <iostream>
using namespace std;
int ans;
int A[100001];
void FullColor(int len,int nearB,int nearR,int c,int number){
    int fb,fr;
    if(nearB==-1||A[nearB]!=A[number]){
        fb=0;
    }
    else if(A[nearB]==A[number]){
        fb=A[number];
    }
    if(nearR==-1||A[nearR]!=A[number]){
        fr=0;
    }
    else if(A[nearR]==A[number]){
        fr=A[number];
    }

    if(number==len){
        c=c+max(fb,fr);
        ans=max(ans,c);
        return;
    }
    
    FullColor(len,number,nearR,c+fb,number+1);
    FullColor(len,nearB,number,c+fr,number+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>A[j];
        }
        ans=0;
        FullColor(n,-1,-1,0,0);
        cout<<ans<<endl;
    }
    return 0;
}