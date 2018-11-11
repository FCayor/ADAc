#include <iostream>
#include <vector>
#include <string.h>
#define infn -9999999
using namespace std;

int main(){
    int T[]={1,3,5,2,5};
    //int T[]={6,3,4,5,2};
    //int T[]={-7,10,9,2,3,8,8,6};
    vector<int> aux1;
	int n = sizeof(T)/sizeof(T[0]);
    int aux2[n],t,c,m=0;
    memset(aux2,0,sizeof(aux2));
    for(int i=1;i<n;i++){
        c=-1;
        t=infn;
		for(int j=0;j<i;j++){
            if(T[j]<T[i]){
                t=max(T[j],t);
                c=max(aux2[j],c);
            }
		}
        aux2[i]=c+1;
        m=max(aux2[i],m);
    }
    for(int i=0;i<n;i++){
        cout<<aux2[i]<<"-";
    }
    cout<<endl<<m+1<<endl;
    for(int i=n-1;i>=0;i--){
        if(aux2[i]==m){
            m--;
            aux1.push_back(T[i]);
        }
    }
    cout<<endl;
    for(int i=aux1.size();i>0;i--){
        cout<<aux1[i-1]<<" ";
    }
    system("pause");
    return 0;
}