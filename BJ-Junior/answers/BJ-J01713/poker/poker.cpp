#include<bits/stdc++.h>
using namespace std;
int n;
int a,d;
int possible[N];
const int N=1e6+6;
char ans[105];
char s[105]{'DACASAHAD2C2S2H2D3C3S3H3D4C4S4H4D5C5S5H5D6C6S6H6D7C7S7H7D8C8S8H8D9C9S9H9DTCTSTHTDJCJSJHJDQCQSQHQDKCKSKHK'};
int main(){
    freopen("pocker.in","r",stdin);
   freopen("pocker.out","w",stdout);

    cin>>n;
    while(cin>>ans[1]>>ans[2]){
        for(int i=0;i<=104;i+=2){
            if(i==105)break;
            if(ans[1]==s[i]&&ans[2]==s[i+1]){
            s[i]='0',s[i+1]='0';break;}
        }
    }
    int ann=0;
    for(int i=0;i<=105;i++){
        if(s[i]!='0')ann++;
    }
    cout<<ann/2;
    return 0;
}