#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main(void)
{
    //board genrator
    int bly = 20, blx = 20; //bfx = board length x, bfy = board length y
    int board[bly][blx];
    int score = 0;
    int xpos = 1, ypos = 1;//x and y pos of snake
    int gfx = 0, gfy = 0; //gfx = genrate food x, gfy = genrate food y
    srand(time(0));
    gfx = rand() % blx; //genrates food randomly on the board
    gfy = rand() % bly;
    char key;
    for (int i = 0; i <= bly - 1; i++)
    {
        for (int j = 0; j <= blx - 1; j++)
        {
            board[i][j] = 0;
        }
    }
    board[xpos][ypos] = 1;
    board[gfy][gfx] = 3;
    //main game
    while (1)
    {
        for (int i = 0; i <= bly - 1; i++)
        {
            for (int j = 0; j <= blx - 1; j++)
            {
                if (board[i][j] == 0)
                {
                    printf("   ");
                }
                else if (board[i][j] == 1)
                {
                    printf("---");
                }
                else if (board[i][j] == 2)
                {
                    printf(" | ");
                }
                else if (board[i][j] == 3)
                {
                    printf(" 0 ");
                }
            }
            puts("|");
        }
        for (int x = 0; x < blx; x++)
        {
            printf("---");
        }
        printf("%d", score);
        Sleep(250);
        if (kbhit())
        {
            key = getch();
            key = tolower(key);
            if ((int)key == 27)
            {
                break;
            }
        }
        if (key == 'w' && ypos > 0)
        {
            board[ypos][xpos] = 0;
            ypos--;
            if (board[ypos][xpos] == 3)
            {
                score++;
                gfx = rand() % blx;
                gfy = rand() % bly;
                printf("%d %d", gfx, gfy);
                board[gfy][gfx] = 3;
            }
            board[ypos][xpos] = 2;
        }
        else if (key == 's' && ypos < bly - 1)
        {
            board[ypos][xpos] = 0;
            ypos++;
            if (board[ypos][xpos] == 3)
            {
                score++;
                gfx = rand() % blx;
                gfy = rand() % bly;
                board[gfy][gfx] = 3;
            }
            board[ypos][xpos] = 2;
        }
        else if (key == 'a' && xpos > 0)
        {
            board[ypos][xpos] = 0;
            xpos--;
            if (board[ypos][xpos] == 3)
            {
                score++;
                gfx = rand() % blx;
                gfy = rand() % bly;
                board[gfy][gfx] = 3;
            }
            board[ypos][xpos] = 1;
        }
        else if (key == 'd' && xpos < blx - 1)
        {
            board[ypos][xpos] = 0;
            xpos++;
            if (board[ypos][xpos] == 3)
            {
                score++;
                gfx = rand() % blx;
                gfy = rand() % bly;
                board[gfy][gfx] = 3;
            }
            board[ypos][xpos] = 1;
        }
        system("cls");
    }
}