#include<iostream>
#include<string>
using namespace std;

char a[10005];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,m;
    cin>>n;
    int paishu=52-n;
    string hua;
    for(int i=0;i<n;i++){
        cin>>hua[0]>>hua[1];
        a[i*2]=hua[0];
        a[i*2+1]=hua[1];
        for(int j=0;j<i*2;j+=2){
            if(a[j]==hua[0]&&a[j+1]==hua[1]){
                paishu++;
                break;
            }
        }
    }
    cout<<paishu;
    return 0;
}
