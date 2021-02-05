#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
    	
    double a[3][2] = {1,2,3,4,5,6}; 
    double b[2]; 
    findColSum(a[0],b,3,2);
    showData(b,1,2);
    return 0;
}

void showData(double A[],int N, int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << A[i];
        if((i+1) % M == 0) cout << endl;
        else cout << " ";
    }
}


void randData(double A[], int N, int M){
    for(int i = 0; i < N*M; i++){
        A[i] = rand()%101/100.0;
    }
}

void findRowSum(const double A[],double *b,int N,int M){
    double sum=0;
    int j = 0;
    for(int i=0; i<M*N; i++){
        sum = sum+A[i];
        *(b+j) = sum;
        if((i+1) % M == 0){
            sum = 0;
            j++;
        }
    }
}

void findColSum(const double A[],double *b,int N,int M){
    double sum;
    for(int i=0; i<M; i++){
        sum = A[i];
        for(int j=1; j<N;j++){
            sum = sum+A[i+(j*M)];
        }
        *(b+i) = sum;
    }
}

