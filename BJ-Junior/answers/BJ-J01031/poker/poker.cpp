#include<bits/stdc++.h>
using namespace std;
struct node{
    string name;
    int num=0;
}a[55];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    a[1].name="DA";
    a[2].name="CA";
    a[3].name="HA";
    a[4].name="SA";
    a[5].name="D2";
    a[6].name="C2";
    a[7].name="H2";
    a[8].name="S2";
    a[9].name="D3";
    a[10].name="C3";
    a[11].name="H3";
    a[12].name="S3";
    a[13].name="D4";
    a[14].name="C4";
    a[15].name="H4";
    a[16].name="S4";
    a[17].name="D5";
    a[18].name="C5";
    a[19].name="H5";
    a[20].name="S5";
    a[21].name="D6";
    a[22].name="C6";
    a[23].name="H6";
    a[24].name="S6";
    a[25].name="D7";
    a[26].name="C7";
    a[27].name="H7";
    a[28].name="S7";
    a[29].name="D8";
    a[30].name="C8";
    a[31].name="H8";
    a[32].name="S8";
    a[33].name="D9";
    a[34].name="C9";
    a[35].name="H9";
    a[36].name="S9";
    a[37].name="DT";
    a[38].name="CT";
    a[39].name="HT";
    a[40].name="ST";
    a[41].name="DJ";
    a[42].name="CJ";
    a[43].name="HJ";
    a[44].name="SJ";
    a[45].name="DQ";
    a[46].name="CQ";
    a[47].name="HQ";
    a[48].name="SQ";
    a[49].name="DK";
    a[50].name="CK";
    a[51].name="HK";
    a[52].name="SK";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        for(int j=1;j<=52;j++){
            if(x==a[j].name){
                a[i].num++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=52;i++){
        if(!a[i].num)ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}