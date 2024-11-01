#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
string s[60];
string ss[60]={"DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK",
               "CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK",
               "HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK",
               "SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"};
int sss[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    int flag=0;
    memset(sss,-1,sizeof(sss));
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<60;j++){
            if(s[i]==ss[j]){
                sss[j]=1;
            }
        }
    }
    for(int i=0;i<52;i++){
        //cout<<sss[i]<<endl;
        if(sss[i]==-1){
            ans++;
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
