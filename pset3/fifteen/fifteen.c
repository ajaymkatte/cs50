/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

//following variables keep track of tile to be moved and the current position of the empty tile
int length, width, lengthmove, widthmove;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
//search of the tile index
void searchtile(int tile);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
    //keeping trakc of the empty tile
    length = d-1;
    width = d-1;

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(700000);
        }

        // sleep thread for animation's sake
        usleep(700000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(7000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int tile=(d*d)-1;
    printf("%d\n",tile);
    for(int p=0; p<d; p++)
    {
        for(int q=0; q<d; q++)
        {
            board[p][q]=tile;
            --tile;
        }
    }
    if(d%2==0)
    {
        int junk = board[d-1][d-2];
        board[d-1][d-2]=board[d-1][d-3];
        board[d-1][d-3]=junk;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for(int p=0; p<d; p++)
    {
        for(int q=0; q<d; q++)
        {
            if(p==length&&q==width)
                printf("_\t");
            else
                printf("%d\t",board[p][q]);
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    if(tile<=(d*d)-1)
    {
        //search for the tile's position
        searchtile(tile);
        //checks if the move is valid by iterating through the valid positions and retruns true if the move is indeed a valid one
        if(((lengthmove==length-1)&&(widthmove==width))||((lengthmove==length+1)&&(widthmove==width))||((lengthmove==length)&&(widthmove==width+1))||((lengthmove==length)&&(widthmove==width-1)))
        {
            int junk=board[lengthmove][widthmove];
            board[lengthmove][widthmove]=board[length][width];
            board[length][width]=junk;
            length=lengthmove;
            width=widthmove;
            return true;
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int verify=1;
    for(int p=0; p<d; p++)
    {
        for(int q=0; q<d; q++)
        {
            if(p==d-1&&q==d-1&&board[p][q]==0)
                return true;
            else if(board[p][q]!=verify)
                return false;
            ++verify;
        }
    }
    return false;
}

/**
 * Search the tile index
 */
void searchtile(int tile)
{
    for(int p=0; p<d; p++)
    {
        for(int q=0; q<d; q++)
        {
            if(board[p][q]==tile)
            {
                lengthmove=p;
                widthmove=q;
                return;
            }
        }
    }
}