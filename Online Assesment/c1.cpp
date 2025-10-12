#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int findTime(string genome, char mutation){
    int time = 0, timeInterval = 0;
    bool firstMutation=true;
    for (int i = genome.size()-1; i>=0; i--){
        if (genome[i] == mutation){
            if (firstMutation){
                timeInterval=0;
                firstMutation=false;
            }
            else{
                timeInterval++;
                time = max(time, timeInterval);
                timeInterval=0;
            }
        }
        else{
            timeInterval++;
        }   
        cout<<time<<' '; 
    }
    time = max(time, timeInterval);
    if (firstMutation) time=0;
    return time;
}

int main()
{
    string genome;
    char mutation;
    cin >> genome >> mutation;
    cout<<findTime(genome,mutation)<<endl;
}