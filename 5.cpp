// Practical 5

#include<bits/stdc++.h>
using namespace std;

void showInstructions()
{
    printf("\t\t\t TIC TAC TOE\n\n");
    printf("Cells are numbered from 1 to 9 as below\n\n");

    printf("\t\t\t 1 | 2 | 3 \n");
    printf("\t\t\t-----------\n");
    printf("\t\t\t 4 | 5 | 6 \n");
    printf("\t\t\t-----------\n");
    printf("\t\t\t 7 | 8 | 9 \n");
    printf("\t\t\t-----------\n");

    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t\n\n");

    return;
}

struct Move
{
	int row, col;
};

char player = 'x', opponent = 'o';

bool isMovesLeft(char board[3][3])
{
	for (int i = 0; i<3; i++)
		for (int j = 0; j<3; j++)
			if (board[i][j]=='_')
				return true;
	return false;
}

int evaluate(char b[3][3])
{
	// Checking for Rows for X or O victory.
	for (int row = 0; row<3; row++)
	{
		if (b[row][0]==b[row][1] &&
			b[row][1]==b[row][2])
		{
			if (b[row][0]==player)
				return +10;
			else if (b[row][0]==opponent)
				return -10;
		}
	}

	// Checking for Columns for X or O victory.
	for (int col = 0; col<3; col++)
	{
		if (b[0][col]==b[1][col] &&
			b[1][col]==b[2][col])
		{
			if (b[0][col]==player)
				return +10;

			else if (b[0][col]==opponent)
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory.
	if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
	{
		if (b[0][0]==player)
			return +10;
		else if (b[0][0]==opponent)
			return -10;
	}

	if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
	{
		if (b[0][2]==player)
			return +10;
		else if (b[0][2]==opponent)
			return -10;
	}

	// Else if none of them have won then return 0
	return 0;
}

int minimax(char board[3][3], int depth, bool isMax)
{
	int score = evaluate(board);

	// If Maximizer has won the game return his/her
	// evaluated score
	if (score == 10)
		return score;

	// If Minimizer has won the game return his/her
	// evaluated score
	if (score == -10)
		return score;

	// If there are no more moves and no winner then
	// it is a tie
	if (isMovesLeft(board)==false)
		return 0;

	// If this maximizer's move
	if (isMax)
	{
		int best = -1000;

		// Traverse all cells
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				// Check if cell is empty
				if (board[i][j]=='_')
				{
					// Make the move
					board[i][j] = player;

					// Call minimax recursively and choose
					// the maximum value
					best = max( best,
						minimax(board, depth+1, !isMax) );

					// Undo the move
					board[i][j] = '_';
				}
			}
		}
		return best;
	}

	// If this minimizer's move
	else
	{
		int best = 1000;

		// Traverse all cells
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				// Check if cell is empty
				if (board[i][j]=='_')
				{
					// Make the move
					board[i][j] = opponent;

					// Call minimax recursively and choose
					// the minimum value
					best = min(best,
						minimax(board, depth+1, !isMax));

					// Undo the move
					board[i][j] = '_';
				}
			}
		}
		return best;
	}
}

// This will return the best possible move for the player
Move findBestMove(char board[3][3])
{
	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			// Check if cell is empty
			if (board[i][j]=='_')
			{
				// Make the move
				board[i][j] = player;

				// compute evaluation function for this
				// move.
				int moveVal = minimax(board, 0, false);

				// Undo the move
				board[i][j] = '_';

				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}

	printf("The value of the best Move is : %d\n\n",
			bestVal);

	return bestMove;
}

int find_pos(int i, int j)
{
    int pos;
        if(i==0&&j==0)
        {
            pos=1;
        }
        else if(i==0&&j==1)
        {
            pos=2;
        }
        else if(i==0&&j==2)
        {
            pos=3;
        }
        else if(i==1&&j==0)
        {
            pos=4;
        }
        else if(i==1&&j==1)
        {
            pos=5;
        }
        else if(i==1&&j==2)
        {
            pos=6;
        }
        else if(i==2&&j==0)
        {
            pos=7;
        }
        else if(i==2&&j==1)
        {
            pos=8;
        }
        else if(i==2&&j==2)
        {
            pos=9;
        }

        return pos;
}

int main()
{
    int block;
    showInstructions();
    cout<<"Symbol pf player - x\nopponent - o"<<endl;
	char board[3][3] =
	{
		{ 'x', 'o', 'x' },
		{ 'o', 'o', 'x' },
		{ 'o', '_', '_' }
	};

	int i,j;
	cout<<endl;
	for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<board[i][j]<<"\t";
        }
        cout<<endl;
    }

	Move bestMove = findBestMove(board);

	printf("The Optimal Move is :\n");
	block=find_pos(bestMove.row,bestMove.col);
	cout<<block;
	return 0;
}
