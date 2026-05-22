#include <stdio.h>
void board(char board[3][3])
{
	//design the board and draw it
	int columns =3;
	int rows =3;
	for(int i=0; i<rows; i++)
	{
  	 for(int j=0; j<columns; j++)
		{
			printf("%c",board[i][j]);
			if(j<columns-1)
			{
				printf("|");
			}
		}
	   printf("\n");
	   if(i<rows-1)
	   {
	   	printf("------\n");
	   }
}		
}
int main()
{
	char game_board[3][3]={
		{'0','1','2'},
		{'3','4','5'},
		{'6','7','8'}
	};
	board(game_board);
	//ask user to select either X or O
	char first_player;
	char second_player;
	printf("first_player choose between(X or O):");
	scanf(" %c",& first_player);
	if(first_player=='x')
	{
		first_player='X';
	}
	if(first_player=='o')
	{
		first_player='O';
	}
	if(first_player=='X')
	{
		second_player='O';
	}
	else if(first_player=='O')
	{
		second_player='X';
	}else
	{
		printf("invalid selection!!!");
		return 1;
	}
		//ask players position they want to play their character and store it and update the board then loop it
	int position;
	char current_player=first_player;
	int moves=0;
	while(1)
	{
	printf(" %c player enter your position(0-8):",current_player);
	scanf("%d",&position);
	if(position<0 || position>8)
	{
		printf("invalid position!!!");
		continue;
	}
	int row=position/3;
	int col=position%3;
		if(game_board[row][col]=='X' || game_board[row][col]=='O')
	{
		printf("position already taken!!!");
		continue;
	}
	game_board[row][col]=current_player;
	//counting moves incase of stalemate
	moves++;
	board(game_board);
		//to check if a player win
	if(game_board[0][0]==current_player &&
	game_board[0][1]==current_player &&
	game_board[0][2]==current_player)
	{
		printf(" %c player won!!!",current_player);
		break;
	} else if(game_board[1][0]==current_player &&
	game_board[1][1]==current_player &&
	game_board[1][2]==current_player)
	{
		printf(" %c player won!!!",current_player);
		break;
	}
else if(game_board[2][0]==current_player &&
	game_board[2][1]==current_player &&
	game_board[2][2]==current_player)
	{
		printf(" %c player won!!!",current_player);
		break;
	}
else if(game_board[0][0]==current_player &&
	game_board[1][0]==current_player &&
	game_board[2][0]==current_player)
	{
		printf(" %c player won!!!",current_player);
		break;
	}
else if(game_board[0][1]==current_player &&
	game_board[1][1]==current_player &&
	game_board[2][1]==current_player)
	{
		printf(" %c player won!!!",current_player);
		break;
	}
else if(game_board[0][2]==current_player &&
	game_board[1][2]==current_player &&
	game_board[2][2]==current_player)
	{
		printf(" %c player won!!!",current_player);
		break;
	}
else if(game_board[0][0]==current_player &&
	game_board[1][1]==current_player &&
	game_board[2][2]==current_player)
	{
		printf(" %c player won!!!",current_player);
		break;
	}
else if(game_board[0][2]==current_player &&
	game_board[1][1]==current_player &&
	game_board[2][0]==current_player)
	{
		printf(" %c player won!!!",current_player);
		break;
	}
	if(moves==9)
	{
		printf("stalemate!!!");
		break;
	}
	//to switch to next player inputting position
	if(current_player==first_player)
	{
		current_player=second_player;
	}
	else
	{
		current_player=first_player;
}
}
return 0;
