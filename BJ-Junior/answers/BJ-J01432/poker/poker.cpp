#include <iostream>
using namespace std;
int tong1[14],tong2[14],tong3[14],tong4[14];
int n,cnt;
string a;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a[0]=='D'){
            if(a[1]=='A'){
                if(tong1[1]==0){
                    cnt++;
                }
                tong1[1]++;
            }
            if(a[1]=='2'){
                if(tong1[2]==0){
                    cnt++;
                }
                tong1[2]++;
            }
            if(a[1]=='3'){
                if(tong1[3]==0){
                    cnt++;
                }
                tong1[3]++;
            }
            if(a[1]=='4'){
                if(tong1[4]==0){
                    cnt++;
                }
                tong1[4]++;
            }
            if(a[1]=='5'){
                if(tong1[5]==0){
                    cnt++;
                }
                tong1[5]++;
            }
            if(a[1]=='6'){
                if(tong1[6]==0){
                    cnt++;
                }
                tong1[6]++;
            }
            if(a[1]=='7'){
                if(tong1[7]==0){
                    cnt++;
                }
                tong1[7]++;
            }
            if(a[1]=='8'){
                if(tong1[8]==0){

                }
                tong1[8]++;
            }
            if(a[1]=='9'){
                if(tong1[9]==0){
                    cnt++;
                }
                tong1[9]++;
            }
            if(a[1]=='T'){
                if(tong1[10]==0){
                    cnt++;
                }
                tong1[10]++;
            }
            if(a[1]=='J'){
                if(tong1[11]==0){
                    cnt++;
                }

                tong1[11]++;
            }
            if(a[1]=='Q'){
                if(tong1[12]==0){
                    cnt++;
                }
                tong1[12]++;
            }
            if(a[1]=='K'){
                if(tong1[13]==0){
                    cnt++;
                }
                tong1[13]++;
            }
        }
        if(a[0]=='C'){
            if(a[1]=='A'){
                if(tong2[1]==0){
                    cnt++;
                }
                tong2[1]++;
            }
            if(a[1]=='2'){
                if(tong2[2]==0){
                    cnt++;
                }
                tong2[2]++;
            }
            if(a[1]=='3'){
                if(tong2[3]==0){
                    cnt++;
                }
                tong2[3]++;
            }
            if(a[1]=='4'){
                if(tong2[4]==0){
                    cnt++;
                }
                tong2[4]++;
            }
            if(a[1]=='5'){
                if(tong2[5]==0){
                    cnt++;
                }
                tong2[5]++;
            }
            if(a[1]=='6'){
                if(tong2[6]==0){
                    cnt++;
                }
                tong2[6]++;
            }
            if(a[1]=='7'){
                if(tong2[7]==0){
                    cnt++;
                }
                tong2[7]++;
            }
            if(a[1]=='8'){
                if(tong2[8]==0){

                }
                tong2[8]++;
            }
            if(a[1]=='9'){
                if(tong2[9]==0){
                    cnt++;
                }
                tong2[9]++;
            }
            if(a[1]=='T'){
                if(tong2[10]==0){
                    cnt++;
                }
                tong2[10]++;
            }
            if(a[1]=='J'){
                if(tong2[11]==0){
                    cnt++;
                }

                tong2[11]++;
            }
            if(a[1]=='Q'){
                if(tong2[12]==0){
                    cnt++;
                }
                tong2[12]++;
            }
            if(a[1]=='K'){
                if(tong2[13]==0){
                    cnt++;
                }
                tong2[13]++;
            }
        }
        if(a[0]=='H'){
            if(a[1]=='A'){
                if(tong3[1]==0){
                    cnt++;
                }
                tong3[1]++;
            }
            if(a[1]=='2'){
                if(tong3[2]==0){
                    cnt++;
                }
                tong3[2]++;
            }
            if(a[1]=='3'){
                if(tong3[3]==0){
                    cnt++;
                }
                tong3[3]++;
            }
            if(a[1]=='4'){
                if(tong3[4]==0){
                    cnt++;
                }
                tong3[4]++;
            }
            if(a[1]=='5'){
                if(tong3[5]==0){
                    cnt++;
                }
                tong3[5]++;
            }
            if(a[1]=='6'){
                if(tong3[6]==0){
                    cnt++;
                }
                tong3[6]++;
            }
            if(a[1]=='7'){
                if(tong3[7]==0){
                    cnt++;
                }
                tong3[7]++;
            }
            if(a[1]=='8'){
                if(tong3[8]==0){
                    cnt++;
                }
                tong3[8]++;
            }
            if(a[1]=='9'){
                if(tong3[9]==0){
                    cnt++;
                }
                tong3[9]++;
            }
            if(a[1]=='T'){
                if(tong3[10]==0){
                    cnt++;
                }
                tong3[10]++;
            }
            if(a[1]=='J'){
                if(tong3[11]==0){
                    cnt++;
                }

                tong3[11]++;
            }
            if(a[1]=='Q'){
                if(tong3[12]==0){
                    cnt++;
                }
                tong3[12]++;
            }
            if(a[1]=='K'){
                if(tong3[13]==0){
                    cnt++;
                }
                tong3[13]++;
            }
        }
        if(a[0]=='S'){
            if(a[1]=='A'){
                if(tong4[1]==0){
                    cnt++;
                }
                tong4[1]++;
            }
            if(a[1]=='2'){
                if(tong4[2]==0){
                    cnt++;
                }
                tong4[2]++;
            }
            if(a[1]=='3'){
                if(tong4[3]==0){
                    cnt++;
                }
                tong4[3]++;
            }
            if(a[1]=='4'){
                if(tong4[4]==0){
                    cnt++;
                }
                tong4[4]++;
            }
            if(a[1]=='5'){
                if(tong4[5]==0){
                    cnt++;
                }
                tong4[5]++;
            }
            if(a[1]=='6'){
                if(tong4[6]==0){
                    cnt++;
                }
                tong4[6]++;
            }
            if(a[1]=='7'){
                if(tong4[7]==0){
                    cnt++;
                }
                tong4[7]++;
            }
            if(a[1]=='8'){
                if(tong4[8]==0){

                }
                tong4[8]++;
            }
            if(a[1]=='9'){
                if(tong4[9]==0){
                    cnt++;
                }
                tong4[9]++;
            }
            if(a[1]=='T'){
                if(tong4[10]==0){
                    cnt++;
                }
                tong4[10]++;
            }
            if(a[1]=='J'){
                if(tong4[11]==0){
                    cnt++;
                }

                tong4[11]++;
            }
            if(a[1]=='Q'){
                if(tong4[12]==0){
                    cnt++;
                }
                tong4[12]++;
            }
            if(a[1]=='K'){
                if(tong4[13]==0){
                    cnt++;
                }
                tong4[13]++;
            }
        }
    }
    cout<<52-cnt;

    return 0;
}