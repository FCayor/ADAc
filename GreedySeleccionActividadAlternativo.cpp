#include <iostream> 
#include <vector> 
#define N 11
#define PES 8 
using namespace std; 
   
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
   
int partitiond (int P[],int W[], int izq, int der)  
{  
    int pivot = P[der];  
    int i = (izq - 1); 
   
    for (int j=izq;j<der;j++)  
    {  
        if (P[j]<=pivot)
        {  
            i++; 
            swap(&P[i],&P[j]); 
            swap(&W[i],&W[j]); 
        }
    }  
    swap(&P[i + 1], &P[der]); 
    swap(&W[i + 1], &W[der]); 
    return (i + 1);  
}  


int partition (int P[],int W[], int izq, int der)  
{  
    int pivot = P[der];  
    int i = (izq - 1); 
   
    for (int j=izq;j<der;j++)  
    {  
        if (P[j]<=pivot)
        {  
            i++; 
            swap(&P[i],&P[j]); 
            swap(&W[i],&W[j]); 
        }
    }  
    swap(&P[i + 1], &P[der]); 
    swap(&W[i + 1], &W[der]); 
    return (i + 1);  
}  
void quickSort(int P[],int W[], int izq, int der)  
{  
    if (izq < der)  
    {  
        int pi = partition(P,W, izq, der);  
        quickSort(P,W, izq, pi - 1);  
        quickSort(P,W, pi + 1, der);  
    }  
}  
int main()  
{  
    int S[N]={1,3,0,5,3,5,6,8,8,2,12}, // inicio 
    F[N]={4,5,6,7,9,9,10,11,12,14,16}; // fin
    quickSort(S,F,0,N-1);
    bool r=0;
    int fin=0,aux;
    vector<int> ex;
    for(int i=1;i<N;i++){
        if(S[i-1]==S[i]){
            fin++;
            if(r==0){
                ex.push_back(i-1);
                r=1;
            }
        }
        else{
            if(r==1){
                quickSort(F,S,ex[0],ex[0]+fin);
                r=0;
                ex.clear();
                fin=0;
            }
        }
    }
    int sum=0;
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