#include<bits/stdc++.h>
using namespace std;
bool poker[52]={0};
string pokename[52]={"DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK","CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK","HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK","SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"};
string s;
int num=0;
int main(){

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>s;
        for(int j=0;j<52;++j){
            if(s==pokename[j]&&poker[j]==0){
                poker[j]=1;
                num++;
                break;
            }
        }
    }
    cout<<52-num;
    return 0;
}
