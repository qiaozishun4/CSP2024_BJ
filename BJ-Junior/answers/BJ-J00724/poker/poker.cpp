#include <iostream>
using namespace std;

bool pok[4][14];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int ans=52;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char A,B;
        cin>>A>>B;
        int a,b;
        switch(A){
            case 'D':{
                a=0;
                break;
            }case 'C':{
                a=1;
                break;
            }case 'H':{
                a=2;
                break;
            }case 'S':{
                a=3;
                break;
            }
        }
        if(B=='T')
            b=10;
        else if(B=='J')
            b=11;
        else if(B=='Q')
            b=12;
        else if(B=='K')
            b=13;
        else b=B-48;

        if(!pok[a][b]){
            pok[a][b]=true;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
