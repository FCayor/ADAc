
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void LCS(char *A,char *B,int T[],int t1,int t2,int C[]){
    for(int i=0;i<t1;i++){
        for(int j=0;j<t2;j++){
            if (i==0 or j==0){ 
                T[(i*t2)+j]=0;
                C[(i*t2)+j]=0;
                }
            else{
                if(A[i]==B[j]){
                    T[(i*t2)+j]=1+T[((i-1)*t2)+(j-1)];
                    C[(i*t2)+j]=((i-1)*t2)+(j-1);
                }
                else{
                    T[(i*t2)+j]=max(T[(i*t2)+(j-1)],T[((i-1)*t2)+j]);
                    if(T[(i*t2)+j]==T[(i*t2)+(j-1)]) C[(i*t2)+j]=(i*t2)+(j-1);
                    else C[(i*t2)+j]=((i-1)*t2)+j;
                }
            }
        }
    }
}

int main(){
    char sq1[]="0abcbdab";
    char sq2[]="0bdcaba";
    vector<char > rt;
    int t1=strlen(sq1),t2=strlen(sq2);
    int T[t1*t2];
    int C[t1*t2];
    int cam,a,b;
    LCS(sq1,sq2,T,t1,t2,C);
    ///////
    for(int i=0;i<t1;i++){
        for(int j=0;j<t2;j++){
            cout<<T[(i*t2)+j]<<"-";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<t1;i++){
        for(int j=0;j<t2;j++){
            cout<<C[(i*t2)+j]<<"-";
        }
        cout<<endl;
    }
    ////////
    cam=(t1*t2)-1;
    while(C[cam]!=0){
        if(C[cam]==cam-t1){
            a=cam%t2;
            b=cam%t1;
            rt.push_back(sq2[a]);
            cam=C[cam];
        }
        else {
            cam=C[cam];
        }
    }

    cout<<rt.size()<<endl;
    for(int i=rt.size()-1;i>=0;i--){
        cout<<rt.at(i);
    }
    cout<<endl;
    system("pause");                                                
}

//481

//481

