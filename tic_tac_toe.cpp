#include <bits/stdc++.h>
#include <conio.h>
using namespace std;



void pripntInputMatrix();
void printBoard();
int addMark();
int check();
	// funtion prototype we are going to use in this program

char board[3][3] = {' ',' ',' ',
					' ',' ',' ',
					' ',' ',' '};
	// made a 2D array with character type and initialized with space

int turn=1 ;
	/* 
		turn= 1 means turn belongs to player 1
		for player 2, turn will come when turn =0;
	*/
char mark='O';
	/*
		O is assigned to player 1 and 
		X is assigned to player 2
	*/

int input;



void printInputMatrix(){
	cout<<"\n\n\t\t\t\t\t\tINPUT MATRIX\n"<<endl;
	cout<<"\t\t\t\t\t\t 1 | 2 | 3 \n";
	cout<<"\t\t\t\t\t\t -----------\n";
	cout<<"\t\t\t\t\t\t 4 | 5 | 6 \n";
	cout<<"\t\t\t\t\t\t -----------\n";
	cout<<"\t\t\t\t\t\t 7 | 8 | 9\n";
} // printInputMatrix function body

void printBoard(){
	cout<<"\n\n\t\t\t\t\t\t-------------"<<endl;
	cout<<"\t\t\t\t\t\t| "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" |"<<endl;
	cout<<"\t\t\t\t\t\t|-----------|\n";
	cout<<"\t\t\t\t\t\t| "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" |"<<endl;
	cout<<"\t\t\t\t\t\t|-----------|\n";
	cout<<"\t\t\t\t\t\t| "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" |"<<endl;
	cout<<"\t\t\t\t\t\t-------------"<<endl;
}	// printBoard funtion body


int addMark(){
	for(int i=0,k=1;i<3;i++){
		for(int j=0;i<3;j++,k++){
			if(k==input){
				if(board[i][j] == ' '){
					board[i][j]=mark;
					return 1;
				}
				else{
					cout<<"\t\t\t\t Invalid Input";
					getch();
					return 0;
				}
			}
		}
	}	
}	// addMark funtion body 

int check(){
	// checking for Rows
	
	if(board[0][0]==mark && board[0][1]==mark && board[0][2]==mark)
		return 1;
	if(board[1][0]==mark && board[1][1]==mark && board[1][2]==mark)
		return 1;
	if(board[2][0]==mark && board[2][1]==mark && board[2][2]==mark)
		return 1;
	
	// checking for Columns
	if(board[0][0]==mark && board[1][0]==mark && board[2][0]==mark)
		return 1;
	if(board[0][1]==mark && board[1][1]==mark && board[2][1]==mark)
		return 1;
	if(board[0][2]==mark && board[1][2]==mark && board[2][2]==mark)
		return 1;
		
	// checking for diagonals
	if(board[0][0]==mark && board[1][1]==mark && board[2][2]==mark)
		return 1;
	if(board[0][2]==mark && board[1][1]==mark && board[2][0]==mark)
		return 1;
	
	return 0;
} // check functoin body

int main(){
	
	char choice='a';
	do{
		system("cls");
		
	
		for(int i=0; i< 3; i++){
			for(int j=0;j<3;j++){
				board[i][j]=' ';
				}
			}
		/*
			initializing box objects with space so that box would be empty if players 
			wish to play again and they click y,Y
		*/	
		
		int won=0; 
		// won is 0 as no one is winner in begining
		
		int validInput=0;
	
		for(int i =0; i< 9; i++){
			system("cls");
			printBoard();
			
			if(turn){
				cout<<"\n\tPlayer 1 Turn (Symobol: \'O\'\n"<<endl;
			}
			else 
				cout<<"\n\tPlayer 1 Turn (Symobol: \'X\'\n"<<endl;
			printInputMatrix();
			cout<<"\n\tEnter Input from Input Matrix: ";
			cin>>input;
			
			while(input<0||input>9){
				cout<<"\t\t\t\tInvalid Input";
				cin>>input;
			}
			
			if(turn){
				mark='O';
				// player1's turn 
			}
			else{
				mark='X';
				// player2's turn
			}
			
			validInput = addMark();
			if(!validInput){
				i--;
				continue;
			}
			
			won=check();
			if(won){
				system("cls");
				printBoard();
				if(turn){
					cout<<endl<<"\n\t\t\t\t_____***** Player 1 - WON *****_____\n\n\n";
				}
				else{
					
					cout<<endl<<"\n\t\t\t\t\t_____***** Player 2 - WON *****_____\n\n\n";
				}
				cout<<"\t\t\t..#....#..  ..######..  ..#....#..  ..#....#..  ..######..  ..######..\n";
				cout<<"\t\t\t..#....#..  ....##....  ..##...#..  ..##...#..  ..#.......  ..#....#..\n";
				cout<<"\t\t\t..#.##.#..  ....##....  ..#.#..#..  ..#.#..#..  ..#####...  ..######..\n";
				cout<<"\t\t\t..##..##..  ....##....  ..#..#.#..  ..#..#.#..  ..#.......  ..#...#...\n";
				cout<<"\t\t\t..#....#..  ..######..  ..#...##..  ..#...##..  ..######..  ..#....#..\n";
				// this will print "WINNER" if any player wins
				
				getch();
			
				break;
			}
			
			if(i==8){
				system("cls");
				printBoard();
				cout<<endl<<"\n\t\t\t\t___**** MATCH DRAW ****___\n\n";
			}
			
			turn=!turn;
		
			}
			
			cout<<"\n\t\tWant to play more: [ Y / y ] for Yes , press anything for NO : ";
			cin>>choice;
	
	}while(choice=='y'||choice=='Y');
	

return 0;
}
// main ended here 
