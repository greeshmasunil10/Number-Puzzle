#include<iostream>
#include<ctime>

using namespace std;

int calcSum(int a, int b, int c){
    return a + b + c;
}

int calcProd(int a, int b, int c){
    return a * b * c;
}

bool playGame(int a1, int a2, int a3, int b1, int b2, int b3){
  if(calcSum(a1, a2,a3)==calcSum(b1, b2, b3) 
    &&calcProd(a1, a2,a3)==calcProd(b1, b2, b3))
    return true;
    else return false;
}

bool playGame(int num1,int num2, int num3, int level){
    cout<<"The sum of the 3 numbers = "<< calcSum(num1,num2,num3) <<endl;
    cout<<"The product of the 3 numbers = "<< calcProd(num1,num2,num3) <<endl;
    cout<<"Enter the 3 numbers (seperated by space):";

    int Guess1, Guess2, Guess3;
    
    cin>>Guess1>>Guess2>>Guess3;

    if (playGame(num1,num2,num3,Guess1, Guess2, Guess3)){
        cout<<"\n***********************************************************"<<endl;
        cout<<"\n********** Well done! You have completed " << level<<". ***********"<<endl;
        return true;
    } else{
        cout<<"\n*** Wrong answer, better luck next time!"<<endl;
        return false;
    } 

}

int main(){
    srand(time(NULL));  
    int LevelOfDifficulty = 1;
    int MaxLevelOfDifficulty = 10;
    int range = 2;
    bool LevelComplete = false;
    int MaxAttempts = 3;
    int attempts=0;
    int a, b, c;
    cout<<"\n***********************************************************"<<endl;
    cout<<"\nWelcome to Number Puzzle!"<<endl;

    while(LevelOfDifficulty <= MaxLevelOfDifficulty && attempts <= MaxAttempts){
        cout<<"\n***************************LEVEL"<<LevelOfDifficulty<<"*************************"<<endl;
        a = rand() % range + range;
        b = rand() % range + range;
        c = rand() % range + range;
        do{
            ++attempts;
            LevelComplete = playGame(a,b,c, LevelOfDifficulty);
        }while(LevelComplete==false && attempts <= MaxAttempts);
        cin.clear();
        cin.ignore();
        if(LevelComplete){
            ++LevelOfDifficulty;
            ++range;
        }
        if(attempts>MaxAttempts){
            cout<<"You have exhausted the max attempts. Game Over!"<<endl;
            cout<<"The answer was "<<a<<" "<<b<<" "<<c;
            return 0;
        }
        attempts = 0;
    }

    cout<<"Congratulations, you have completed all levels!"<<endl;
    return 0;
}