#include <iostream>
#include <vector>
#define N 4
#define PES 8
using namespace std;
  
void swap(float* a, float* b) 
{ 
    float t = *a; 
    *a = *b; 
    *b = t; 
} 
  
int partition (float P[],float W[], int izq, int der) 
{ 
    float pivot = P[der]; 
    int i = (izq - 1);
  
    for (int j=izq;j<der;j++) 
    { 
        if (P[j]>=pivot) 
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
void quickSort(float P[],float W[], int izq, int der) 
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
    float P[N]={1.0,2.0,5.0,6.0}, // objeto
    W[N]={2.0,3.0,4.0,5.0}; // pesos
    quickSort(P,W,0,N-1);
    float sum=0;
    for(int i=0;i<N;i++){
        sum+=W[i];
        if(sum>PES) sum-=W[i];
    }
    cout<<sum<<endl;
    for(int i=0;i<N;i++){
        cout<<P[i]<<"-"<<W[i]<<endl;
    }
    system("pause");
    return 0; 
} 