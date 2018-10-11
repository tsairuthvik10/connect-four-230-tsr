
#include<iostream>

using namespace std;

void draw_board();

bool checkwinner(int a, int b);

int drop(int b, char player);

char place[6][7];//array for the board



int main() {

	char answer;

	for (int a = 0; a <= 5; a++) {       

		for (int b = 0; b <= 6; b++)    

			place[a][b] = ' ';     //fill board with white space initially

	}                               

	draw_board();//Displays for first time so players can see the board

	int hold;//Will house user row choice

	int hold2 = 0;//will hold drop value

	int charsPlaced = 0;//Number of pieces dropped so we can end game if a draw happens

	bool gamewon = false;//initially false, Will change to true when game is won and will exit loop

	char player = 'O';//start as player 2 will change back 2 player 1

	while (!gamewon) {//will stop when game is won

		if (hold2 != -1) {//check if there was a error in the last drop

			if (player == 'O') {

				cout << "Player 1 turn! Type the column number to insert a piece: ";

				player = 'X';//char of player piece

			}

			else {

				cout << "Player 2 turn! Type the column number to insert a piece: ";

				player = 'O';//char of player piece

			}

		}

		while (true) {//will run untill 'break;'

			if (charsPlaced == 42) break;//if game is draw

			cin >> hold;

			hold--;//take off 1 to account for arrays starting at 0 not 1

			if (hold <= 6 && hold >= 0) break;//if within valid range stop loop

			else cout << "\nplease enter a value between 1 and 7 :";//ask for input and loop again

			if (cin.fail()) //catch a non number

			{                      

				cin.clear();        

				char c;         

				cin >> c;           

			}



		}

		if (charsPlaced == 42) break;//if draw

		hold2 = drop(hold, player);//drop the player, store the row in hold2

		if (hold2 == -1) cout << "Column is full\nPlease enter anothor number between 1 and 7:";//if error -1 row is full

		else {

			gamewon = checkwinner(hold2, hold);//check if game is running

			charsPlaced++;//another character has been succesfully placed

			system("cls");//clears the screen

			draw_board();//displayed updated board

		}

	}

	system("cls");

	if (charsPlaced == 42) {//if draw

		cout << "No winner, Game's a draw\n";


		cout << "Would you like to play again? y/n\n\n";//ask players to play again?
		cin >> answer;
		cin.ignore();
		cout << "\n";
		if (answer == 'y' || answer == 'Y') {//if yes, again print the board with white spaces
			for (int a = 0; a <= 5; a++) {       

				for (int b = 0; b <= 6; b++) {    

					place[a][b] = ' ';
				}
			}
			main();
		}if (answer == 'n' || answer == 'N') {//if no, exit the application
			cout << "\nThanks for playing.";
			cin.get();
		}

		return 0;//exit application

	}

	if (player == 'O')//if won by player 2

		cout << "game won by : player 2\n";

	else cout << "game won by : player 1\n";//Else won by player 1
	cout << "Would you like to play again? y/n\n\n";
	cin >> answer;
	cin.ignore();
	cout << "\n";
	if (answer == 'y' || answer == 'Y') {
		for (int a = 0; a <= 5; a++) {       

			for (int b = 0; b <= 6; b++) {    

				place[a][b] = ' ';
			}
		}
		main();
	}if (answer == 'n' || answer == 'N') {
		cout << "\nThanks for playing.";
		cin.get();
	}


	

	return 0;

}

void draw_board() {

	cout << "1 2 3 4 5 6 7\n";

	for (int a = 0; a <= 5; a++)

	{

		for (int b = 0; b <= 6; b++) cout << " " << " ";

		cout << "\n";

		for (int b = 0; b <= 6; b++) cout << place[a][b] << " ";

		cout << '\n';

		for (int b = 0; b <= 6; b++) cout << char(196) << " ";//_ is placed on each row and column

		cout << '\n';

	}

}

bool checkwinner(int a, int b) {

	int vertical = 1;

	int horizontal = 1;

	int diagonalleft = 1;

	int diagonalright = 1;

	char player = place[a][b];

	int i;//vertical

	int ii;//horizontal

//check for vertical

	for (i = a + 1; place[i][b] == player && i <= 5; i++, vertical++);//Check down

	for (i = a - 1; place[i][b] == player && i >= 0; i--, vertical++);//Check up

	if (vertical >= 4)return true;

	//check for horizontal(-)

	for (ii = b - 1; place[a][ii] == player && ii >= 0; ii--, horizontal++);//Check left

	for (ii = b + 1; place[a][ii] == player && ii <= 6; ii++, horizontal++);//Check right
	if ((place[a][0] == place[a][6] == player) && (horizontal == 3)) horizontal++;
	if (horizontal >= 4) return true;

	//check for diagonal 1 (\)

	for (i = a - 1, ii = b - 1; place[i][ii] == player && i >= 0 && ii >= 0; diagonalleft++, i--, ii--);//Check up and left

	for (i = a + 1, ii = b + 1; place[i][ii] == player && i <= 5 && ii <= 6; diagonalleft++, i++, ii++);//Check down and right



	if (diagonalleft >= 4) return true;

	//check for diagonal 2(/)

	for (i = a - 1, ii = b + 1; place[i][ii] == player && i >= 0 && ii <= 6; diagonalright++, i--, ii++);//Check up and right

	for (i = a + 1, ii = b - 1; place[i][ii] == player && i <= 5 && ii >= 0; diagonalright++, i++, ii--);//Check up and left

	if (diagonalright >= 4) return true;

	return false;

}

int drop(int b, char player) {

	if (b >= 0 && b <= 6)

	{

		if (place[0][b] == ' ') {

			int i;

			for (i = 0; place[i][b] == ' '; i++)

				if (i == 5) {
					place[i][b] = player;

					return i;
				}

			i--;

			place[i][b] = player;

			return i;



		}

		else {

			return -1;

		}



	}

	else {

		return -1;

	}

}