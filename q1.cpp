#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j%2){
                for(int j=1;j<=i;j++){
            cout << j;
        }
        for(int j=i+1;j<=n;j++){
            cout << " ";
        }
            }
        else{
            for(int j=1;j<=n-i;j++){
            cout<< " ";
        }
        int x =i;
        for(int j=1;j<=i;j++){
            cout << x;
            x--;
        }
        }
        }
        cout << endl;
    }
    
    
    }
