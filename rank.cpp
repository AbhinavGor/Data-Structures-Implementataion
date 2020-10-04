#include <iostream>

using namespace std;

class Player{
    public:
        int ranks[3];
        // char name[];
        int total = ranks[0] + ranks[1] + ranks[2];
}players[5];

int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            cout<<"Enter the rank of player "<<i + 1<<" by judge "<<j + 1<<"\n";
            cin>>players[i].ranks[j];
        }
        players[i].total = players[i].ranks[0] + players[i].ranks[2] +  players[i].ranks[1];
    }

    int max = 0;
    int maxInd = -1;

    for (int i = 0; i < 5; i++){
        if(players[i].total > max){
            maxInd = i;
            max = players[i].total;
        }
        cout<<players[i].total<<"\n";
    }
    cout<<"The player "<<maxInd + 1<<" has highest total.\n";
}