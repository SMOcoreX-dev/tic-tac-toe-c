#include <stdio.h>
int main()
{
	//draw the board
	char board[]={'1','2','3','4','5','6','7','8','9'};
	printf(" %c | %c | %c\n",board[0],board[1],board[2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n",board[3],board[4],board[5]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n",board[6],board[7],board[8]);
	printf("---|---|---\n");
	//ask players to select either X or O
	char first_player;
	char second_player;
	printf("user one choose between (X and O):");
	scanf(" %c",& first_player);
	if(first_player=='X')
	{
		second_player='O';
	}
	else if(first_player=='O')
	{
		second_player='X';
	}
	else
	{
		printf("invalid input");
		return 1;
	}
	//ask players to input their position and updating the board then loop it to avoid stress
	int position;
	int moves=0;
	char current_player=first_player;
	while(1)
	{
	printf("player %c input your position(1-9):",current_player);
	scanf("%d",&position);
		if(board[position - 1]=='X' || board[position - 1]=='O')
	{
	printf("position taken!!");
	continue;
	}
	board[position - 1] = current_player;
	//count players move incase of stalemate
	moves++;
	//update the board after player plays
	printf(" %c | %c | %c\n",board[0],board[1],board[2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n",board[3],board[4],board[5]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n",board[6],board[7],board[8]);
	printf("---|---|---\n");				
		//to detect if any player wins	
		if(
		board[0]==current_player &&
		board[4]==current_player &&
		board[8]==current_player)
		{
			printf("player %c wins!",current_player);
			break;
		}
		else if(
		board[2]==current_player &&
		board[4]==current_player &&
		board[6]==current_player)
		{
			printf("player %c wins!",current_player);
			break;
		}
	else if(
		board[0]==current_player &&
		board[1]==current_player &&
		board[2]==current_player)
		{
			printf("player %c wins!",current_player);
			break;
		}
		else if(
		board[3]==current_player &&
		board[4]==current_player &&
		board[5]==current_player)
		{
			printf("player %c wins!",current_player);
			break;
		} 
		else if(
		board[6]==current_player &&
		board[7]==current_player &&
		board[8]==current_player)
		{
			printf("player %c wins!",current_player);
			break;
		}
		else if(
		board[0]==current_player &&
		board[3]==current_player &&
		board[6]==current_player)
		{
			printf("player %c wins!",current_player);
			break;
		}
		else if(
		board[1]==current_player &&
		board[4]==current_player &&
		board[7]==current_player)
		{
			printf("player %c wins!",current_player);
			break;
		}
		else if(
		board[2]==current_player &&
		board[5]==current_player &&
		board[8]==current_player)
		{
			printf("player %c wins!",current_player);
			break;
		}
		//this is after every players played and no one wins
		if(moves==9)
		{
			printf("stalemate!!!");
			break;
		}
		// to switch to the next player
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
}
