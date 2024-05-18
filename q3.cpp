#include<iostream>
using namespace std;
int main(){
    int examScores[10];
    int sum = 0;
    for(int i=0;i<10;i++){
        cin >> examScores[i];
        sum+=examScores[i];
        
    }
    int avg = sum/10;
    int max = -1;
    int min = 10000;
    int abvavg=0;
    int belavg=0;
    for(int i=0;i<10;i++){
        
        if(examScores[i]>max){
            max = examScores[i];
        }
        if(examScores[i]<min){
            min = examScores[i];
        }
        if(examScores[i]>avg){
            abvavg++;
        }
        else if(examScores[i]<avg){
            belavg++;

        }
    }

    cout << "Average exam score"<< avg << endl;
    cout << "Highest exam score " << max <<  endl;
    cout << "Lowest exam score " << min << endl;
    cout << "Number of exam scores above the average " << abvavg << endl;
    cout << "Number of exam scores below the average " << belavg;


}