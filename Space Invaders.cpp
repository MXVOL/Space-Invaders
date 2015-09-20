#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

	char Map[20][20] =
	{

	"###################",
	"#                 #",
	"#     @     @     #",
	"#      @   @      #",
	"#     @@@@@@@     #",
	"#    @@ @@@ @@    #",
	"#   @@@@@@@@@@@   #",
	"#   @ @@@@@@@ @   #",
	"#   @ @     @ @   #",
	"#      @@ @@      #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#        ^        #",
	"###################",
	};

	bool endgame = false;	int gamespeed=50;	int randomNum;	int maxHealth=100;	int yourHealth=maxHealth;
	char sss=char(-37);
	int main()
	{
	system("color 17");
	SetConsoleTitle("Space Invaders");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

	system("cls");
	system("mode 70,24");
	cout<<"            _______  _______  _______  _______  _______              "<<endl;
	cout<<"           |       ||       ||   _   ||       ||       |             "<<endl;
	cout<<"           |  _____||    _  ||  |_|  ||       ||    ___|             "<<endl;
	cout<<"           | |_____ |   |_| ||       ||       ||   |___              "<<endl;
	cout<<"           |_____  ||    ___||       ||      _||    ___|             "<<endl;
	cout<<"            _____| ||   |    |   _   ||     |_ |   |___              "<<endl;
	cout<<"           |_______||___|    |__| |__||_______||_______|             "<<endl;
	cout<<" ___  __    _  __   __  _______  ______   _______  ______    _______ "<<endl;
	cout<<"|   ||  |  | ||  | |  ||   _   ||      | |       ||    _ |  |       |"<<endl;
	cout<<"|   ||   |_| ||  |_|  ||  |_|  ||  _    ||    ___||   | ||  |  _____|"<<endl;
	cout<<"|   ||       ||       ||       || | |   ||   |___ |   |_||_ | |_____ "<<endl;
	cout<<"|   ||  _    ||       ||       || |_|   ||    ___||    __  ||_____  |"<<endl;
	cout<<"|   || | |   | |     | |   _   ||       ||   |___ |   |  | | _____| |"<<endl;
	cout<<"|___||_|  |__|  |___|  |__| |__||______| |_______||___|  |_||_______|"<<endl;
	cout<<"                              "<<sss<<"     "<<sss<<"  "<<endl;
	cout<<"                               "<<sss<<"   "<<sss<<"   "<<endl;
	cout<<"                              "<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<"  "<<endl;
	cout<<"                             "<<sss<<""<<sss<<" "<<sss<<""<<sss<<""<<sss<<" "<<sss<<""<<sss<<" "<<endl;
	cout<<"                            "<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<endl;
	cout<<"                            "<<sss<<" "<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<" "<<sss<<""<<endl;
	cout<<"                            "<<sss<<" "<<sss<<"     "<<sss<<" "<<sss<<""<<endl;
	cout<<"                               "<<sss<<""<<sss<<" "<<sss<<""<<sss<<"   "<<endl;
	cout<<"(C) Piotr Zborowski 2015"<<endl;
	getchar();
game:

	system("mode 20,21");
	while(endgame == false)
	{

		srand(time(0));
		system("cls");
		for(int y=0; y<20; y++)
		{

			cout << Map[y];
			cout<<endl;

		}

		cout<<"Health: ";
		cout << yourHealth;

		cout<<"/";
		cout << maxHealth;

		for(int y=0; y<20; y++)
		{

			for(int x=0; x<20; x++)
			{
				switch (Map[y][x])

				{

				case '^':
				if(GetAsyncKeyState(VK_LEFT) != 0)
				{
					int newX=x-1;switch (Map[y][newX])

				{

				case ' ':
				Map[y][x] = ' ';
				x--;
				Map[y][newX] = '^';break;

				}

			}

			if(GetAsyncKeyState(VK_RIGHT) != 0)
			{
				int newX=x+1;switch (Map[y][newX])

				{

					case ' ':
					Map[y][x] = ' ';
					x++;
					Map[y][newX] = '^';break;

				}

			}

			if(GetAsyncKeyState(VK_SPACE) != 0)
			{

				Beep( 600, 100 );
				y--;
				Map[y][x] = '|';
			}

			if(GetAsyncKeyState(VK_ESCAPE) != 0)
			{

				system("mode 32,10");
				system("cls");
				cout<<"            "<<sss<<"     "<<sss<<"  "<<endl;
				cout<<"             "<<sss<<"   "<<sss<<"   "<<endl;
				cout<<"            "<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<"  "<<endl;
				cout<<"           "<<sss<<""<<sss<<" "<<sss<<""<<sss<<""<<sss<<" "<<sss<<""<<sss<<" "<<endl;
				cout<<"          "<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<endl;
				cout<<"          "<<sss<<" "<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<" "<<sss<<""<<endl;
				cout<<"          "<<sss<<" "<<sss<<"     "<<sss<<" "<<sss<<""<<endl;
				cout<<"             "<<sss<<""<<sss<<" "<<sss<<""<<sss<<"   "<<endl;
				cout<<"Press enter to return the game."<<endl;
				getchar();
				goto game;

				}
			break;

			case '|':
			Map[y][x] = ' ';
			y--;
			if((Map[y][x] != '#' && Map[y][x] != sss))
			{

				Map[y][x] = '|';
			}

			if(Map[y][x] == sss)
			{

				Map[y][x] = ' ';
			}
			break;

			case '@':
			randomNum = rand() %10 + 1;
			if(randomNum == 1)
			{

				y++;
				if((Map[y][x] != '@' && Map[y][x] != sss))
				{

					Map[y][x] = sss;
					Map[y][x] = '!';
				}

			else
			{

				Map[y][x] = sss;
			}

		}

	if(randomNum != 1)
	{

		Map[y][x] = sss;
	}
	break;

	case char(-37):
	Map[y][x] = sss;
	randomNum = rand() %10 + 1;
	if(randomNum == 1)
	{

		y++;
		if((Map[y][x] != char(-37) && Map[y][x] != '@'))
		{

			Map[y][x] = '!';
		}

	}
	break;

	case '!':
	Map[y][x] = ' ';
	y++;
	if((Map[y][x] != '#' && Map[y][x] != '^' && Map[y][x] != char(-37) && Map[y][x] != '@'))
	{

		Map[y][x] = '!';
	}

	if(Map[y][x] == '#')
	{

		Beep( 600, 100 );
	}

	else
	if(Map[y][x] == '^')
	{

		Beep( 700, 100 );
		yourHealth -= 20;
	}
	break;

	}

}

if(yourHealth <= 0)
{
	endgame = true;
}

}

	Sleep(gamespeed);

	}

	system("mode 12,10");
	system("cls");
	cout<<"  "<<sss<<"     "<<sss<<"  "<<endl;
	cout<<"   "<<sss<<"   "<<sss<<"   "<<endl;
	cout<<"  "<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<"  "<<endl;
	cout<<" "<<sss<<""<<sss<<" "<<sss<<""<<sss<<""<<sss<<" "<<sss<<""<<sss<<" "<<endl;
	cout<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<endl;
	cout<<""<<sss<<" "<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<""<<sss<<" "<<sss<<""<<endl;
	cout<<""<<sss<<" "<<sss<<"     "<<sss<<" "<<sss<<""<<endl;
	cout<<"   "<<sss<<""<<sss<<" "<<sss<<""<<sss<<"   "<<endl;
	cout<<"Game over! "<<endl;
	getchar();

}
