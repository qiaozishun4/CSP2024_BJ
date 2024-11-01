#include<bits/stdc++.h>
using namespace std;
int n,sum=52,x[100]={0};
string a[100]={"DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK","CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK","HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK","SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"};
string b[100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<52;j++){
            if(b[i]==a[j]&&x[j]==0){
                x[j]++;
                sum--;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
