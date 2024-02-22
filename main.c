#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "helper.h"

int main()
{
    char enter;
    printf("\t----------------------------------------------------------------------------\n\t|");
    printf(pink"\t\t\t  MATH QUIZ MASTER\t\t\t\t   "reset);
    printf("|\n");
    printf("\t|--------------------------------------------------------------------------|\n\t|");
    printf(red"\tIncase of leaving the game right after data entry, user's history\n"reset); 
    printf("\t|\t");
    printf(red"and information will not be saved\n"reset); 
    printf("\t|\t");
    printf("\n\t|- Do You want to see the history of the previous players or play\n\t|History-> Press H\n\t|Play-> Press P\n\t|Enter: ");
    scanf(" %c", &enter);
    printf("\t|");
    if (enter == 'h' || enter == 'H')
    {
        users_history();
        printf("\t|--------------------------------------------------------------------------|\n\t|");
    }      
    else if (enter == 'P' || enter == 'p')
        start_game();
    else
        printf(red"Invalid Input!\n"reset);  

}
