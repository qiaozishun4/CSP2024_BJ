#include<iostream>
#include<time.h>
#include<random>
using namespace std;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int T;
    cin>>T;
    srand(time(0));
    while(T--){
        /*正解时间复杂度为*/
        /*$$O(T \times n)$$*/
        /*可惜不会写*/
        /*             
        N        N     OOOOO                BBBBBBB     U       U     GGGGGG      SSSSSS  !                                                                                                                                                                                                                                          
        NN       N    O     O               B      B    U       U    G           S        !                                                                                                                                                                                
        N NN     N   O       O              B      B    U       U   G           S         !                                                                                 
        N   N    N   O       O              BBBBBBB     U       U   G    GGGG    SSS      !                                                                                                                                                                   
        N    NN  N   O       O              B      B    U       U   G      GG       SSS   !                                                                                                                            
        N      N N    O     O               B      B     U     U     G    G G          S                                                                                                              
        N       NN     OOOOO                BBBBBBB       UUUUU       GGGG  G    SSSSSS   !                                                                                                      
        */
        cout<<rand()<<endl;
    }
    return 0;
}
