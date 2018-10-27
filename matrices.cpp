#include <iostream>
#define N 4
#define INFF 9999999
using namespace std;

void particion(int A[N][N],int i,int d){
        if(i==d) cout<<"A"<<i;
        else {
            cout<<"(";
            particion(A,i,A[d][i]);
            cout<<"*";
            particion(A,A[d][i]+1,d);
            cout<<")";
        }
}

int main(){
    int M[N][N];
    int d[N+1]={5,4,6,2,7}; 
    int t,a; //auxiliares

    for(int i=0;i<N;i++){
        M[i][i]=0;
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<N-i;j++){
            t=i+j;
            M[j][t]=INFF;
            for(int k=0;k<t;k++){
                a=M[j][t];
                M[j][t]=min(M[j][t],M[j][k]+M[k+1][t]+(d[j]*d[k+1]*d[t+1]));
                if(M[j][t]!=a) M[t][j]=k;
            }
        }
    }
   ////////////////////////////
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<M[i][j]<<"-";
        }
        cout<<endl;
    }
   
    particion(M,0,N-1);
    cout<<endl;
    for(int i=0;i<N;i++){
        cout<<"A"<<i<<"="<<d[i]<<"*"<<d[i+1]<<endl;
    }

    system("pause");
}