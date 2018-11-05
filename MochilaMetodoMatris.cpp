#include <iostream>
#include <vector>
#define N 4
#define M 8

using namespace std;



int main(){
    int P[N]={1,2,5,6}, // objeto
    W[N]={2,3,4,5}, // pesos
    T[N+1][M+1],
    y=0,
    o=-1;
    bool a=0;
    vector<vector<int>> res;
    vector<int> temp;
    for(int i=0;i<N+1;i++){
        for(int j=0;j<M+1;j++){
            a==0;
            if(i==0 or j==0) {
                T[i][j]=0;
            }
            else{
                if(j-W[i-1]>=0) {
                    T[i][j]=max(T[i-1][j],T[i-1][j-W[i-1]]+P[i-1]);
                    if(T[i][j]!=T[i-1][j]){
                    
                        if(res.size()==0 or j-W[i-1]==0){
                            for(int k=0;k<res.size();k++){
                                if(T[i][j]==res[k][0]){
                                    y=k;
                                    a=1;
                                }
                            }
                            if(a==0){
                                temp.push_back(T[i-1][j-W[i-1]]+P[i-1]);
                                temp.push_back(P[i-1]);
                                res.push_back(temp);
                                o++;
                            }
                        }
                        else{
                            if(j-W[i-1]!=0){
                                a=0;
                                for(int k=0;k<res.size();k++){
                                    if(T[i][j]==res[k][0]) a=1;
                                }
                                if(a==0){
                                    temp.push_back(T[i-1][j-W[i-1]]+P[i-1]);
                                    for(int l=0;l<res.size();l++){
                                        if(T[i-1][j-W[i-1]]==res[l][0]) y=l;
                                    }
                                    if(y!=0){
                                        for(int u=1;u<res[y].size();u++){
                                            temp.push_back(res[y][u]);
                                        }
                                    }
                                    temp.push_back(P[i-1]);
                                    
                                    res.push_back(temp);
                                    o++;
                                }
                                
                            }
                        }
                        
                    }
                    
                }
                else T[i][j]=T[i-1][j]; 
            }
            cout<<T[i][j]<<"-";
            temp.clear();
        }
        cout<<endl;
    }
    cout<<"Items a robar :V "<<endl;
    for(int j=1;j<res[o].size();j++){
        cout<<res[o][j]<<" ";
    }
    cout<<endl;


    system("pause");
}