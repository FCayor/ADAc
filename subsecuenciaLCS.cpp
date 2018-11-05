#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>
#define Tam1 3
#define Tam2 5
using namespace std;

int LCS(char *A,char *B,int T[],int i,int j,int t2,vector<char> &res){
    if(T[(i*t2)+j]>0) {
        res.push_back(A[i]);
        return T[(i*t2)+j];
        }
    if(A[i]=='0' or B[j]=='0'){
        T[(i*t2)+j]=0;
        return 0;
    }
    if(A[i]==B[j]){
        T[(i*t2)+j]=1;
        res.push_back(A[i]);
        return 1+LCS(A,B,T,i+1,j+1,t2,res);
    }
    else{
        vector<char> temp1=res;
        vector<char> temp2=res;
        int tt=max(LCS(A,B,T,i+1,j,t2,temp1),LCS(A,B,T,i,j+1,t2,temp2));
        if(temp1.size()>=temp2.size()){
            res=temp1;
            temp1.clear();
            temp2.clear();
        }
        else{
            res=temp2;
            temp1.clear();
            temp2.clear();
        }
        return tt;
    }
}

int main(){
    vector<char> res;
    char sq1[]="asdasdwqsewq0";
    char sq2[]="ewqdsassads0";
    int t1=strlen(sq1),t2=strlen(sq2);
    int T[t1*t2];
    memset(T,0,sizeof(T));
    cout<<endl<<LCS(sq1,sq2,T,0,0,t2,res)<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i];
    }
    cout<<endl;
    system("pause");                                                
}