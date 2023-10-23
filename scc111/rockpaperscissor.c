#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
void ui();
int game(int first, int second);
void countdown();

int main()
{
    ui();
}

void ui()
{
    srand(time(NULL));

    int player = 0, cpu = 0, games = 0, won = 0, loss = 0, tie = 0;
    char *hands[] = {"Rock", "Paper", "Scissors"}; 

    printf("Welcome to rock, paper, scissors!\n");

    while(1)
    {
        printf("Please enter 1 for Rock, 2 for Paper or 3 for Scissors, and 0 to quit\n");
        scanf("%i", &player);
        cpu = rand() % 3 + 1;;

        if (player > 0 && player <= 3) 
        {
            countdown();

            printf("Player chose: %s\n", hands[player - 1]);
            printf("Machine chose: %s\n", hands[cpu - 1]);

            int result = game(player, cpu);
            games++;
            if (result == 0)
            {
                printf("It's a draw this round!\n\n");
                tie++;
            }
            else if (result == -1)
            {
                printf("Sorry, you lost this round!\n\n");
                loss++;
            }
            else
            {
                printf("Nice, you won this round!\n\n");
                won++;
            }
        }
        else
        {
            printf("Games played %d, games won %d, games lost %d, games tied %d\n", games, loss, won, tie);
            return;
        }
    }
}

int game(int player, int cpu)
{
    if (player == cpu) 
    {
        return 0;
    }

    if (player == 1) 
    {
        if (cpu == 2)
        {
            return -1;
        }
        else if (cpu == 3)
        {
            return 1;
        }
        
    }

    if (player == 2) 
    {
        if (cpu == 1)
        {
            return 1;
        }
        else if (cpu == 3)
        {
            return -1;
        }
        
    }

    if (player == 3) 
    {
        if (cpu == 1)
        {
            return -1;
        }
        else if (cpu == 2)
        {
            return 1;
        }
        
    }
}

void countdown()
{
    char *flags[] = {"Rock", "Paper", "Scissors"};
    for (int i = 0; i < 3; i++) 
    {
        printf("%s\n", flags[i]);
        sleep(1);
    }
    printf("Shoot!\n\n");
    sleep(1);
}
