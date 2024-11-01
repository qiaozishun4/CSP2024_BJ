#include<iostream>
using namespace  std;
const int b[101]={'6','2','5','5','4','5','6','3','7','6'};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,x=1;
    char a;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a=='1'){
            cout << "-1";
        }
        for(int j=0;j<10;j++){
            if(b[j]==a){
                cout << j << endl;
                break;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
}
