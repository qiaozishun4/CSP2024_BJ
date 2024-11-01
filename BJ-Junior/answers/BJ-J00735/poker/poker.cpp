#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,num;
    cin>>n;
    string s,b;
    num=n;
    int len=n;
    int DA=0,CA=0,HA=0,SA=0,D2=0,C2=0,H2=0,S2=0,D3=0,C3=0,H3=0,S3=0,D4=0,C4=0,H4=0,S4=0,D5=0,C5=0,H5=0,S5=0,D6=0,C6=0,H6=0,S6=0,D7=0,C7=0,H7=0,S7=0;
    int D8=0,C8=0,H8=0,S8=0,D9=0,C9=0,H9=0,S9=0,DT=0,CT=0,HT=0,ST=0,DJ=0,CJ=0,HJ=0,SJ=0,DQ=0,CQ=0,HQ=0,SQ=0,DK=0,CK=0,HK=0,SK=0;
        for(int i=0;i<=n-1;i++){
            cin>>s;
        }
    b=s;
    for(int i=0;i<=len-1;i++){
        if(s[i]=='D'&&s[i+1]=='A'&&DA<=1){
                DA++;
            }else if(s[i]=='C'&&s[i+1]=='A'&&CA<=1){
                CA++;
            }else if(s[i]=='H'&&s[i+1]=='A'&&HA<=1){
                HA++;
            }else if(s[i]=='S'&&s[i+1]=='A'&&SA<=1){
                SA++;
            }else if(s[i]=='D'&&s[i+1]=='2'&&D2<=1){
                D2++;
            }else if(s[i]=='C'&&s[i+1]=='2'&&C2<=1){
                C2++;
            }else if(s[i]=='H'&&s[i+1]=='2'&&H2<=1){
                H2++;
            }else if(s[i]=='S'&&s[i+1]=='2'&&S2<=1){
                S2++;
            }else if(s[i]=='D'&&s[i+1]=='3'&&D3<=1){
                D3++;
            }else if(s[i]=='C'&&s[i+1]=='3'&&C3<=1){
                C3++;
            }else if(s[i]=='H'&&s[i+1]=='3'&&H3<=1){
                H3++;
            }else if(s[i]=='S'&&s[i+1]=='3'&&S3<=1){
                S3++;
            }else if(s[i]=='D'&&s[i+1]=='4'&&D4<=1){
                D4++;
            }else if(s[i]=='C'&&s[i+1]=='4'&&C4<=1){
                C4++;
            }else if(s[i]=='H'&&s[i+1]=='4'&&H4<=1){
                H4++;
            }else if(s[i]=='S'&&s[i+1]=='4'&&S4<=1){
                S4++;
            }else if(s[i]=='D'&&s[i+1]=='5'&&D5<=1){
                D5++;
            }else if(s[i]=='C'&&s[i+1]=='5'&&C5<=1){
                C5++;
            }else if(s[i]=='H'&&s[i+1]=='5'&&H5<=1){
                H5++;
            }else if(s[i]=='S'&&s[i+1]=='5'&&S5<=1){
                S5++;
            }else if(s[i]=='D'&&s[i+1]=='6'&&D6<=1){
                D6++;
            }else if(s[i]=='C'&&s[i+1]=='6'&&C6<=1){
                C6++;
            }else if(s[i]=='H'&&s[i+1]=='6'&&H6<=1){
                H6++;
            }else if(s[i]=='S'&&s[i+1]=='6'&&S6<=1){
                S6++;
            }else if(s[i]=='D'&&s[i+1]=='7'&&D7<=1){
                D7++;
            }else if(s[i]=='C'&&s[i+1]=='7'&&C7<=1){
                C7++;
            }else if(s[i]=='H'&&s[i+1]=='7'&&H7<=1){
                H7++;
            }else if(s[i]=='S'&&s[i+1]=='7'&&S7<=1){
                S7++;
            }else if(s[i]=='D'&&s[i+1]=='8'&&D8<=1){
                D8++;
            }else if(s[i]=='C'&&s[i+1]=='8'&&C8<=1){
                C8++;
            }else if(s[i]=='H'&&s[i+1]=='8'&&H8<=1){
                H8++;
            }else if(s[i]=='S'&&s[i+1]=='8'&&S8<=1){
                S8++;
            }else if(s[i]=='D'&&s[i+1]=='9'&&D9<=1){
                D9++;
            }else if(s[i]=='C'&&s[i+1]=='9'&&C9<=1){
                C9++;
            }else if(s[i]=='H'&&s[i+1]=='9'&&H9<=1){
                H9++;
            }else if(s[i]=='S'&&s[i+1]=='9'&&S9<=1){
                S9++;
            }else if(s[i]=='D'&&s[i+1]=='T'&&DT<=1){
                DT++;
            }else if(s[i]=='C'&&s[i+1]=='T'&&CT<=1){
                CT++;
            }else if(s[i]=='H'&&s[i+1]=='T'&&HT<=1){
                HT++;
            }else if(s[i]=='S'&&s[i+1]=='T'&&ST<=1){
                ST++;
            }else if(s[i]=='D'&&s[i+1]=='J'&&DJ<=1){
                DJ++;
            }else if(s[i]=='C'&&s[i+1]=='J'&&CJ<=1){
                CJ++;
            }else if(s[i]=='H'&&s[i+1]=='J'&&HJ<=1){
                HJ++;
            }else if(s[i]=='S'&&s[i+1]=='J'&&SJ<=1){
                SJ++;
            }else if(s[i]=='D'&&s[i+1]=='Q'&&DQ<=1){
                DQ++;
            }else if(s[i]=='C'&&s[i+1]=='Q'&&CQ<=1){
                CQ++;
            }else if(s[i]=='H'&&s[i+1]=='Q'&&HQ<=1){
                HQ++;
            }else if(s[i]=='S'&&s[i+1]=='Q'&&SQ<=1){
                SQ++;
            }else if(s[i]=='D'&&s[i+1]=='K'&&DK<=1){
                DK++;
            }else if(s[i]=='C'&&s[i+1]=='K'&&CK<=1){
                CK++;
            }else if(s[i]=='H'&&s[i+1]=='K'&&HK<=1){
                HK++;
            }else if(s[i]=='S'&&s[i+1]=='K'&&SK<=1){
                SK++;
            }
        }
    cout<<52-DA-CA-HA-SA-D2-C2-H2-S2-D3-C3-H3-S3-D4-C4-H4-S4-D5-C5-H5-S5-D6-C6-H6-S6-D7-C7-H7-S7-D8-C8-H8-S8-D9-C9-H9-S9-DT-CT-HT-ST-DJ-CJ-HJ-SJ-DQ-CQ-HQ-SQ-DK-CK-HK-SK;
    return 0;
}

