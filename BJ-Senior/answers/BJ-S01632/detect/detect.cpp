#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("detect.in","r+",stdin);
    freopen("detect.out","w+",stdout);
    int dataNumber;
    cin>>dataNumber;
    for(int dataNow=0;dataNow<dataNumber;dataNow++){
        int n,m,L,V,catched=0;
        cin>>n>>m>>L>>V;
        long double carList[n][3];
        long double detectorList[m];
        for(int i=0;i<n;i++){
            cin>>carList[i][0]>>carList[i][1]>>carList[i][2];
            //cout<<carList[i][0]<<" "<<carList[i][1]<<" "<<carList[i][2]<<endl;
        }
        for(int i=0;i<m;i++){
            cin>>detectorList[i];
        }
        for(int i=0;i<m;i++){
        }
        for(int carNumber=0;carNumber<n;carNumber++){
            //cout<<"*"<<carNumber+1<<endl;
            int catchedLast=catched;
            for(int distanceNow=carList[carNumber][0];distanceNow<L;distanceNow++){
                if(carList[carNumber][2]==0&&carList[carNumber][1]<=V){
                    //cout<<carList[carNumber][1]<<"<="<<V<<endl;
                    break;
                }
                else if(carList[carNumber][2]==0&&carList[carNumber][1]>V){
                    //cout<<carList[carNumber][1]<<">"<<V<<endl;
                    catched++;
                    //cout<<"!catched! "<<carNumber+1<<endl;
                    break;
                }
                long double speedNow=sqrt(carList[carNumber][1]+2.0*carList[carNumber][2]+distanceNow);
                //cout<<speedNow<<" "<<V<<endl;
                if(speedNow<=0){
                    break;
                }
                for(int detectorNumber=0;detectorNumber<m;detectorNumber++){
                    //cout<<"#"<<detectorList[detectorNumber]<<endl;
                    if(detectorList[detectorNumber]==distanceNow){
                        if(speedNow>V){
                            catched++;
                            //cout<<"!catched! "<<carNumber+1<<endl;
                            break;
                        }
                    }
                }
                if(catched>catchedLast){
                    break;
                }
            }
        }
        cout<<catched<<endl;
    }
    return 0;
}
