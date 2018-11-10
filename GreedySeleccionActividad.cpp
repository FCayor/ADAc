#include <iostream> 
#include <vector> 
#define N 11
#define PES 8 
using namespace std; 
int main()  
{  
    int S[N]={1,3,0,5,3,5,6,8,8,2,12}, // inicio 
    F[N]={4,5,6,7,9,9,10,11,12,14,16}; // fin
    int aux;
    for(int i=0;i<N;i++){ 
        cout<<S[i]<<"-"<<F[i]<<endl; 
    }
    cout<<"Tiempos"<<endl<<S[0]<<"-"<<F[0]<<endl;
    aux=F[0];
    for(int i=1;i<N;i++){
        if(S[i]>=aux){
            cout<<S[i]<<"-"<<F[i]<<endl;
            aux=F[i];
        }
    }
    system("pause"); 
    return 0;  
} 