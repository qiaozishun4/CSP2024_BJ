#include<bits/stdc++.h>
using namespace std;
string poker[53]={"DA","CA","HA","SA",
                  "D2","C2","H2","S2",
                  "D3","C3","H3","S3",
                  "D4","C4","H4","S4",
                  "D5","C5","H5","S5",
                  "D6","C6","H6","S6",
                  "D7","C7","H7","S7",
                  "D8","C8","H8","S8",
                  "D9","C9","H9","S9",
                  "DT","CT","HT","ST",
                  "DJ","CJ","HJ","SJ",
                  "DQ","CQ","HQ","SQ",
                  "DK","CK","HK","SK"};
int tmp[53];
long long n,ans=0;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    memset(tmp,-1,sizeof(tmp));
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<53;j++){
            if(tmp[j]!=1&&s==poker[j]){
                tmp[j]=1;
                ans++;
                break;
            }
        }
    }
    cout<<52-ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}