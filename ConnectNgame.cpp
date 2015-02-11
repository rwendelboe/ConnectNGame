#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

	const int EXTRA_ROWS = 2;
	const int EXTRA_COLS = 3;


int GetConnectionSize(void){
	int WinSize;
	cout<<"How many connections would you like in order to win the game 3, 4, 5 or 6 "<<endl;
	cin>>WinSize;
	return WinSize;
}

char** BuildGameBoard(int WinSize) {
	
	char **GameBoard = new char *[WinSize+EXTRA_ROWS];

	for (int i = 0; i <WinSize+EXTRA_ROWS; i++){

		GameBoard [i] = new char [WinSize+EXTRA_COLS];
		for(int j = 0; j<WinSize+EXTRA_COLS; j++){
			GameBoard[i][j]= ' ';
		}
}
	return GameBoard;
}

void DisplayGameBoard(char **GameBoard, int WinSize){
	cout<<"You are an O and the Computer is X"<<endl;
	for(int i = 0; i < WinSize+EXTRA_COLS; i++){
		cout<<i<<" ";
	}
	cout<<endl;
	for( int i = 0; i < WinSize+EXTRA_ROWS; i++){
		for(int j = 0; j < WinSize+EXTRA_COLS; j++){
			cout<<GameBoard[i][j]<<"|";
		}
		cout<<endl;
		for(int j = 0; j< WinSize+EXTRA_COLS; j++){
			cout<<"--";
		}
		cout<<endl;
}
}

void PlayerMove(char **GameBoard, int WinSize){
	int ColNum;

	cout<<"Which colum would you like to drop your piece into? "<<endl;
	cin>>ColNum;
	
	while(GameBoard[0][ColNum] == 'x' || GameBoard[0][ColNum] == 'o'){
		cout<<"This Colum is full "<<endl;
		cin>>ColNum;
	}
	for(int i = 1; i< WinSize+EXTRA_ROWS; i++){

		if (GameBoard[i][ColNum] == 'x' || GameBoard[i][ColNum] =='o'){ 
				
					GameBoard[i-1][ColNum] = 'o';
					return;
	}
	}
	GameBoard[WinSize+EXTRA_ROWS-1][ColNum]= 'o';
}

void ComputerMove(char **GameBoard, int WinSize){
	srand(static_cast<unsigned int>(time(NULL)));
	rand() ;
	int ColNum = rand()%(WinSize+EXTRA_COLS);
	
	while (GameBoard[0][ColNum] == 'x' || GameBoard[0][ColNum] == 'o'){
		ColNum= rand()%(WinSize+EXTRA_COLS);
	}
	for(int i = 1; i< WinSize+EXTRA_ROWS; i++){

		if (GameBoard[i][ColNum] == 'x' || GameBoard[i][ColNum] =='o'){ 
				
					GameBoard[i-1][ColNum] = 'x';
					return;
	}
	}
	GameBoard[WinSize+EXTRA_ROWS-1][ColNum]= 'x';
}

bool CheckRowWin(char **GameBoard, int WinSize){
	int x = 0;
	int o =0;
	for(int i = 0; i< WinSize+EXTRA_ROWS; i++){
		x= 0;
		o=0;
		for(int j = 0; j<WinSize+EXTRA_COLS; j++){
			if (GameBoard[i][j]=='x'){
				x++;
				o=0;
				if(x>=WinSize){
					cout<<"Computer Wins!!!!"<<endl;
					return true;
				}
			}
			if (GameBoard[i][j]=='o'){
				o++;
				x=0;
				if(o>=WinSize){
					cout<<"You Win!!!!"<<endl;
					return true;
				}
			}
			if (GameBoard[i][j]==' '){
				x= 0;
				o= 0;
			}
		}
}
	return false;
}

bool CheckColumnWin(char **GameBoard, int WinSize){
	int x = 0;
	int o =0;
	for(int i = 0; i< WinSize+EXTRA_COLS; i++){
		x=0;
		o=0;
		for(int j = 0; j<WinSize+EXTRA_ROWS; j++){
			if (GameBoard[j][i]=='x'){
				x++;
				o=0;
				if(x>=WinSize){
					cout<<"Computer Wins!!!!"<<endl;
					return true;
				}
			}
			if (GameBoard[j][i]=='o'){
				o++;
				x=0;
				if(o>=WinSize){
					cout<<"You Win!!!"<<endl;
					return true;
				}
			}
			if (GameBoard[j][i]!='x' && GameBoard[j][i]!='o'){
				x= 0;
				o= 0;
			}
		}
}
	return false;
}
bool CheckRightD(char** GameBoard, int WinSize, int row, int cols){
	int k = row;
	int x = 0;
	int o = 0;
	for(int j = cols; j>=0 && k<WinSize+EXTRA_ROWS; j--){
			if (GameBoard[k][j]=='x'){
				x++;
				o=0;
				if(x>=WinSize){
					cout<<"Computer Wins!!!!"<<endl;
					return true;
				}
			}
			if (GameBoard[k][j]=='o'){
				o++;
				x=0;
				if(o>=WinSize){
					cout<<"You Win!!!"<<endl;
					return true;
				}
			}
			if (GameBoard[k][j]!='x' && GameBoard[k][j]!='o'){
				x= 0;
				o= 0;
			}
			k++;
		}
	return false;
}

bool CheckRightDiagonalWin(char **GameBoard, int WinSize){
	int x = 0;
	int o =0;
	bool win = false;
	for(int i = 0; i< WinSize+EXTRA_ROWS-1; i++){
		win=CheckRightD(GameBoard, WinSize, i, WinSize+EXTRA_COLS);
		if (win) return true;
	}
	for(int i = WinSize+EXTRA_COLS-1; i>0; i--){
		win = CheckRightD(GameBoard, WinSize, 0, i);
		if (win) return true;
	}

	return false;
}
bool CheckDiagnal(char** GameBoard, int WinSize, int row, int cols){
	int k = row;
	int x = 0;
	int o = 0;
	for(int j = cols; j>=0 && k>0; j--){
			
			if (GameBoard[k][j]=='x'){
				x++;
				o=0;
				if(x>=WinSize){
					cout<<"Computer Wins!!!!"<<endl;
					return true;
				}
			}
			if (GameBoard[k][j]=='o'){
				o++;
				x=0;
				if(o>=WinSize){
					cout<<"You Win!!!"<<endl;
					return true;
				}
			}
			if (GameBoard[k][j]!='x' && GameBoard[k][j]!='o'){
				x= 0;
				o= 0;
			}
			k--;
		}
	return false;
}

bool CheckLeftDiagonalWin(char **GameBoard, int WinSize){
	int x =0;
	int o =0;
	bool win = false;
	for(int i = 1; i< WinSize+EXTRA_ROWS; i++){
		
		win = CheckDiagnal(GameBoard, WinSize, i, WinSize+EXTRA_COLS-1);
		if (win ) return true;
}
	for(int i = 1; i<WinSize+EXTRA_COLS-1; i++){
		win = CheckDiagnal(GameBoard, WinSize, WinSize+EXTRA_ROWS-1, i);
		if (win) return true;
	}
	return false;
}

bool CheckTie(char **GameBoard, int WinSize){
	
	for(int i = 0; i< WinSize+EXTRA_ROWS; i++){	
		for(int j = 0; j<WinSize+EXTRA_COLS; j++){
			if (GameBoard[i][j]==' '){
				return false;
			}
		}
	}
	cout<<"Its a Tie!!!"<<endl;
	return true;	
}

void DestroyGameBoard(char **GameBoard, int WinSize){
	int EXTRA_ROWS = 2;
	int EXTRA_COLS = 3;
	for (int i = 0; i < WinSize+EXTRA_ROWS; i++){
		delete [] GameBoard[i] ;	
		GameBoard[i] = 0 ;
	}

	delete [] GameBoard;
	GameBoard = 0 ;

}

int main(){

	int size;
	char** Game;
	bool playing = true;

	size = GetConnectionSize();
	Game = BuildGameBoard(size);
	DisplayGameBoard(Game, size);
	while(playing = true){
		PlayerMove(Game, size);
		DisplayGameBoard(Game, size);	
			cout<<"You Made the Move it is Computers Turn"<<endl;
			if(CheckRowWin(Game, size))break;
			if(CheckColumnWin(Game, size))break;
			if(CheckRightDiagonalWin(Game, size))break;
			if(CheckLeftDiagonalWin(Game, size))break;
			if(CheckTie(Game, size))break;
		ComputerMove(Game, size);
		DisplayGameBoard(Game, size);
			cout<<"Computer Made the Move it is Players turn"<<endl;
			if(CheckRowWin(Game, size))break;
			if(CheckColumnWin(Game, size))break;
			if(CheckRightDiagonalWin(Game, size))break;
			if(CheckLeftDiagonalWin(Game, size))break;
			if(CheckTie(Game, size))break;
	}

	DestroyGameBoard(Game, size);
	cin.get();
	cin.get();
	return 0;
}