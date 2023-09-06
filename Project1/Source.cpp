#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void print(char array[18][32]) {
	for (int i = 0; i < 18;i++) {
		for (int j = 0; j < 32;j++) {
			cout << array[i][j];
		}
		cout << endl;
	
	}
}
void moveright(char array[18][32],int &hindX,int &vindX,int &score) {
	if (array[vindX][hindX+1]=='*' || array[vindX][hindX+1]==' ') {
		if (array[vindX][hindX+1]=='*') {
			array[vindX][hindX] = ' ';
			hindX++;
			array[vindX][hindX] = 'P';
			score++;
		}
		else {
			array[vindX][hindX] = ' ';
			hindX++;
			array[vindX][hindX] = 'P';
		}
	}
}
void moveleft(char array[18][32], int& hindX, int& vindX, int &score) {
	if (array[vindX][hindX - 1] == '*' || array[vindX][hindX - 1] == ' ') {
		if (array[vindX][hindX-1]=='*') {
			array[vindX][hindX] = ' ';
			hindX--;
			array[vindX][hindX] = 'P';
			score++;
		}
		else {
			array[vindX][hindX] = ' ';
			hindX--;
			array[vindX][hindX] = 'P';
		}
	}
}

void moveup(char array[18][32],int &vindX,int &hindX,int &score) {
	if (array[vindX-1][hindX]=='*' || array[vindX-1][hindX] == ' ') {
		if (array[vindX-1][hindX]=='*') {
			array[vindX][hindX] = ' ';
			vindX--;
			array[vindX][hindX] = 'P';
			score++;
		}
		else {
			array[vindX][hindX] = ' ';
			vindX--;
			array[vindX][hindX] = 'P';

		}
	}
}
void movedown(char array[18][32],int &vindX,int &hindX,int &score) {
	if (array[vindX+1][hindX]=='*' || array[vindX + 1][hindX] == ' ') {
		if (array[vindX+1][hindX]=='*') {
			array[vindX][hindX] = ' ';
			vindX++;
			array[vindX][hindX] = 'P';
			score++;
		}
		else {
			array[vindX][hindX] = ' ';
			vindX++;
			array[vindX][hindX] = 'P';
		}
	}
}
void menu() {
	cout << "Next move?" << endl;
	cout << "1. Move up" << endl;
	cout << "2. Move down" << endl;
	cout << "3.Move left" << endl;
	cout << "4. Move right" << endl;
	cout << "5. Quit" << endl;
	}
void initialiseMonster(char array[18][32],int &ranV,int &ranH) {
	 ranV=9, ranH=14;
	
	 array[ranV][ranH] = '@';
	
}
void monstermove(char array[18][32], int& vindX, int& hindX) {
	srand(time(NULL));
	int choice = 0;
	choice = rand() % 4 + 1;
	int n = 0;

	if (choice == 1) {
		if (array[vindX + 1][hindX] != 'X') {
			if (array[vindX + 1][hindX] == '*') {
				array[vindX + 1][hindX] = '@';
				array[vindX][hindX] = '*';
				vindX++;
			}
			else {
				array[vindX + 1][hindX] = '@';
				array[vindX][hindX] = ' ';
				vindX++;
			}
		}
	}
	else if (choice == 2) {
		if (array[vindX - 1][hindX] != 'X') {
			if (array[vindX - 1][hindX] == '*') {
				array[vindX - 1][hindX] = '@';
				array[vindX][hindX] = '*';
				vindX--;
			}
			else {
				array[vindX - 1][hindX] = '@';
				array[vindX][hindX] = ' ';
				vindX--;
			}
		}
	}
	else if (choice == 3) {
		if (array[vindX][hindX + 1] != 'X') {
			if (array[vindX][hindX + 1] == '*') {
				array[vindX][hindX + 1] = '@';
				array[vindX][hindX] = '*';
				hindX++;
			}
			else {
				array[vindX][hindX + 1] = '@';
				array[vindX][hindX] = ' ';
				hindX++;
			}
		}
	}
	else {
		if (array[vindX][hindX - 1] != 'X') {
			if (array[vindX][hindX - 1] == '*') {
				array[vindX][hindX - 1] = '@';
				array[vindX][hindX] = '*';
				hindX--;
			}
			else {
				array[vindX][hindX - 1] = '@';
				array[vindX][hindX] = ' ';
				hindX--;
			}
		}
	}
}




int main() {
	int choice=0;
	int choice2=0;
	int vertINDX = 0;
	int horINDX = 0;
	int score = 0;
	int mVindX, mhindX = 0;
	char arr[18][32] = {
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	"X    X                 X      X",
	"X    X                 X      X",
	"XXX XX                 XX XXXXX",
	"X                             X",
	"X                             X",
	"X                             X",
	"X                             X",
	"X             XXXX            X",
	"X                             X",
	"X                             X",
	"X                             X",
	"X                             X",
	"X                             X",
	"XXXXXX XXX            XXX XXXXX",
	"X        X            X       X",
	"X        X            X       X",
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
	};	
	for (int i = 0; i < 18;i++) {
		for (int j = 0; j < 31;j++) {
			if (arr[i][j]!='X') {
				arr[i][j] = '*';
			}
		}
	}
	initialiseMonster(arr,mVindX,mhindX);
	arr[16][14]='P';
	vertINDX = 16;
	horINDX = 14;
	print(arr);
	cout << "Menu:" << endl;
	cout << "1. Play game" << endl;
	cout << "2. View Board" << endl;
	cin >> choice;
	if (choice == 1) {
		while (choice2 != 5) {
			menu();
			cin >> choice2;
			if (choice2 == 1) {
				moveup(arr, vertINDX, horINDX, score);
				monstermove(arr,mVindX,mhindX);		
				print(arr);
				if (arr[vertINDX][horINDX] == '@') {
					choice2 = 5;
					cout << "Game over" << endl;
					cout << score << endl;
				}
			}
			else if (choice2 == 2) {
				movedown(arr, vertINDX, horINDX, score);
				monstermove(arr, mVindX, mhindX);
				print(arr);
				if (arr[vertINDX][horINDX]=='@') {
					choice2 = 5;
					cout << "Game over" << endl;
					cout << score << endl;
				}
			}
			else if (choice2 == 3) {
				moveleft(arr, horINDX, vertINDX, score);
				monstermove(arr, mVindX, mhindX);
				print(arr);
				if (arr[vertINDX][horINDX] == '@') {
					choice2 = 5;
					cout << "Game over" << endl;
					cout << score << endl;
				}
			}
			else if (choice2 == 4) {
				moveright(arr, horINDX, vertINDX, score);
				monstermove(arr, mVindX, mhindX);
				print(arr);
				if (arr[vertINDX][horINDX] == '@') {
					choice2 = 5;
					cout << "Game over" << endl;
					cout << score << endl;
				}
			}
			else {
				cout << "Your score is:" << score << endl;
			}
		}
	}
		else {
			print(arr);
		}
	}