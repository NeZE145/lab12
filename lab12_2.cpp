#include<iostream>
#include<string>

using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	int randomnum;
	randomnum = rand()%13+1;
	return randomnum;
}

int calScore(int x,int y,int z){
  if(x>10)
            x=10;
  if(y>10)
            y=10;
   if(z>10)
            z=10;
    int sum = x+ y+z;
	if(sum>=10)
		sum -=10;
	if(sum>=10)
		sum -=10;
	
	

    return sum;
}

int findYugiAction(int s){	
	if(s == 9) return 2; 
	else if(s < 6) return 1; 
	else{
        int TrueFalse = rand() % 100+1;
        if (TrueFalse <=69)
            return 1;
            else return 2;
	}
}

void checkWinner(int p,int y){
    cout<<"---------------------------------"<<endl;
    if(p>y)
    cout << "|         Player wins!!!        |";
    if(y>p)
    cout << "|          Yugi wins!!!         |";
    if(p==y)
    cout << "|             Draw!!!           |";
    cout<< endl <<"---------------------------------";
}

int main(){	
	srand(time(0));
	int playerScore, yugiScore, playerAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(), drawCard(), 0};
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore ;
	do{
		cout << "\n(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
		if(playerAction == 2)
			break;
	  }while(playerAction != 1);
	if(playerAction == 1){
		cout << "Player draws the 3rd card!!!" << "\n";
		playerCards[2] = drawCard();
		cout << "Your 3rd card: " << cardNames[playerCards[2]] <<"\n";
		cout << "Your new score: " << calScore(playerCards[0],playerCards[1],playerCards[2]);
		playerScore =calScore(playerCards[0],playerCards[1],playerCards[2]);
		cout << "\n------------ Turn end -------------------\n\n";
	}else if (playerAction ==2)
	    cout << "------------ Turn end -------------------\n\n";
	
	
	
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
	yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
	cout << "Yugi's score: " << yugiScore << "\n";
	if(findYugiAction(yugiScore) == 1){
		cout << "Yugi draws the 3rd card!!!" << "\n";
		yugiCards[2] = drawCard();
		cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]] <<"\n";
		cout << "Yugi's new score: " << calScore(yugiCards[0],yugiCards[1],yugiCards[2])<<endl;
	}
	yugiScore=calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
	cout << "------------ Turn end -------------------\n\n";
	
	
	
	checkWinner(playerScore,yugiScore);
}
