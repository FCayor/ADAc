#include <iostream>
#include <stdlib.h> 
#include <stdio.h>
using namespace std;

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    
} 
void mergeSort(int arr[], int l, int r,int& men,int& may,int& cost) 
{ 
    if (l < r) 
    { 
        
        int m = l+(r-l)/2;
        int men1,men2,may1,may2,cos1,cos2;
  
        mergeSort(arr, l, m,men1,may1,cos1); 
        mergeSort(arr, m+1, r,men2,may2,cos2); 
        int tot=arr[r]-arr[l];
  		if((tot>cos1 and tot>cos2)or(tot==cos1 and tot ==cos2)) {
  			men=arr[l];
            may=arr[r];
            cost=tot;    
		}
        else{

            if(cos1>cos2){
            men=men1;
            may=may1;
            cost=cos1;
            }
            else {
                men=men2;
                may=may2;
                cost=cos2;
            }
        }
        merge(arr, l, m, r); 

  		
         
        
    } 
    else {
        men=arr[l];
        may=arr[l];
        cost=0;
    }
} 

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    int arr[] = {38, 270, 43, 3, 9, 82, 10}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
    int menor,mayor,ganancia;
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1,menor,mayor,ganancia);
    cout<<menor<<endl;
    cout<<mayor<<endl;
    cout<<ganancia<<endl; 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 