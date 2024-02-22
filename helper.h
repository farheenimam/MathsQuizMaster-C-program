// This file consist of all of the function here
#define blue "\x1b[96m"
#define pink "\x1b[38;2;255;105;180m"
#define red "\e[0;31m"
#define pink_brg "\x1b[38;2;255;105;180m"
#define reset "\x1b[0m"
#define green "\e[0;32m"
#define yellow "\e[0;33m"

struct
{
    char name[100];
    int register_no;
    char lvl_played[6];
    int class;
    int correct;
    int wrong;
} user;

// To enter the level, class played by the user, count of wrong anser, count of right answered
void data_entry()
{
    // Declared a variable data that is going to point at the actual file
    FILE *data = fopen("users.csv", "a"); // Using 'a' mean to append mode, to add things into the file without deleting the previous context

    // To print to the file
    fprintf(data, "%s, %d, %s, %d, %d, %d\n", user.name, user.register_no, user.lvl_played, user.class, user.wrong, user.correct);
    
    // To close the file
    fclose(data);
}
// This reads the content of the file from top to bottom with tthe help of fgets
void users_history()
{
    int isfirst_line = 1; // To keep the track of the first line
    // The file is on read mode, '*data is file pointer': it points to the actual file
    FILE *data = fopen("users.csv", "r");
    char content[10000]; // Declaring a varaible to read the content from csv file to this array
    printf(yellow"\n\t\t------------------------------------------------\n");
    printf("\t\t|\t\t  HISTORY\t\t\t|");
    printf("\n\t\t-----------------------------------------------\n");
    printf("\t\t  Name\t ID\tLevel\tClass\tRight\tWrong\t\n\t\t");
    if (data != NULL)
    {
        // Takes the first argument of to store the read data, the maximum numbers of characters to read and file pointer
        while(fgets(content,sizeof(content), data)) // Using while to read the whole file, fgets return True is there is content to be read and False until nothing is left
        { 
            if(isfirst_line == 1)
            {
                isfirst_line = 0;
                continue;
            }
        // This pointer starts by point to the beginning of the content, checks lf it is not passing to a null terminator 
        for (char *pointer = content; *pointer != '\0'; *pointer++)
        {
            if (*pointer == ',') // If the character the poniter points to is comma, replace it by |t
            {
                *pointer = '\t';
            }
        }
         printf("  %s\t\t", content);
    }
    }
    else
        printf("File pointer is empty, file open unsuccessful!\n");
    printf("\n\t\t_________________________________________________\n"reset);
    fclose(data);
}
void quiz(int wrong, int correct)
{
    printf(yellow"\t\t|Correct answer: %d\t|\n\t\t|Wrong answer: %d\t|\n\t\t|",user.correct,user.wrong);
    if(user.wrong > user.correct)
        printf("You need more practice |\n"reset);
    else
        printf("Good job. Keep it up  |\n"reset);
}
// To check for right and wrong
void right_wrong(int answer, int result)
{
    if (answer == result)
    {
        user.correct++;
        printf(green"\tRight O\n"reset);
    }        
    else
    {
        user.wrong++;
        printf(red"\tWrong X\n"reset);
    }            
}
// For level 5 - 12
// This function displays the questions from the txt file according to the level and class
void problems(int class)
{
    int count = 1;
    FILE *ques = fopen("ques.txt", "r");
    if (ques == NULL)
        printf("Error opening the file.\n");

    int line_skip = (class - 5) * 10;

    // First skips specific numbers of line, saved the lines to skip in another array
    for (int i = 0; i < line_skip; i++)
    {
        char skipped[1000];
        (fgets(skipped, sizeof(skipped), ques));// Only reads files and is then discarded
    }
    char question[1000];
    while(fgets(question, sizeof(question), ques) != NULL && count <= 10)
    {
    if (count % 2 != 0) 
        printf("\t%s\n", question); 
    else 
    { 
        int result = atoi(question); // Used atori to convert string to integer 
        int answer;
        printf("\tAnswer: "); 
        scanf("%d", &answer); 
        right_wrong(answer, result); 
        printf(pink_brg"\n\t==============================================================================================================\n\n"reset); 
    } 
    count++;
    } 
}  

// For level 1: generate different patterns
void pattern_generate(int num1, int num2)
{
    int result = 0, answer, option = num1;
    switch(option)
    {
        case 1:  // Prints a sqaure
            for (int i = 0; i < num2; i++)
            {
                printf("\t\t\t");
                for (int j = 0; j < num2; j++)
                {
                    printf(blue"*");
                    result++;
                }
                printf("\n"reset);
            }
            printf("\tAnswer:");
            scanf("%d", &answer);
            right_wrong(answer, result);
            break;
        case 2: // Prints a right angle triangle
            for (int i = 1; i < num2; i++)
            {
                printf("\t\t\t");
                for (int j = num2; j >= 1; j--)
                {
                    if (i>= j)
                    {
                        printf(blue"*");
                        result ++;
                    }    
                    else
                        printf(" ");  
                }
                printf("\n"reset);     
            }
            printf("\tAnswer:");
            scanf("%d", &answer);
            right_wrong(answer, result);
            break;
        case 3: // Print a pyramid
            for (int i = 1; i <= num2; i++)
            {
                printf("\t\t\t");
                for (int j = num2; j >= 1; j--)
                {
                    if (i>= j)
                    {
                        printf(blue"* ");
                        result ++;
                    }
                    else
                        printf(" ");  
                }
                printf("\n"reset);     
            }
            printf("\tAnswer:");
            scanf("%d", &answer);
            right_wrong(answer, result);
            break;
        case 4: // Prints a left angle triangle
            for (int i = 0; i < num2; i++)
            {
                printf("\t\t\t");
                for (int j = 0; j <= i; j++)
                {
                    printf(blue"*");
                    result ++;
                }    
                printf("\n"reset);
            }
            printf("\tAnswer:");
            scanf("%d", &answer);
            right_wrong(answer, result);
            break;
        case 5: // Prints a inverted left angle triangle
            for (int i = 0; i < num2; i++)
            {
                printf("\t\t\t");
                for (int j = num2; j > i; j--)
                {
                    printf(blue"*");
                    result ++;
                }
                printf("\n"reset);
            }
            printf("\tAnswer:");
            scanf("%d", &answer);
            right_wrong(answer, result);
            break;    
        case 6: // Prints a inverted right angle triangle
            for (int i = 0; i < num2; i++)
            {
                printf("\t\t\t");
                for (int j = 0; j < num2; j++)
                {
                    if (i <= j)
                    {
                        printf(blue"*");
                        result ++;
                    }    
                    else
                        printf(" ");
                }
                printf("\n"reset);
            }
            printf("\tAnswer:");
            scanf("%d", &answer);
            right_wrong(answer, result);
            break;
        default:
            break;
    }

}
// Addition
int add(int a , int b)
{
    return a+b;
}
// Substraction
int minus(int a , int b)
{
    return a-b;
}
// Multiplication
int multi(int a , int b)
{
    return a*b;
}
// Division
int divide(int a , int b)
{
    return a/b;
}
// Factorial
int factorial(int a)
{
    if (a == 0)
        return 1;
    else
        return a * factorial(a -1);
}
// Prints the question according to the operation
void print_operator(int count, int x, int y, int lvl, char operator, char *operation)
{
    if (lvl == 2 || lvl == 3)
        lvl = 1;
    switch (lvl)
    {
    case 1:
        printf("\tQues%d): %d %c %d = ?",count, x, operator, y);
        printf("\n\tAnswer:");
        break;
    case 4:
        printf("\t%d)What is the %s of %d and %d?", count,operation, x, y);
        printf("\n\tAnswer:");
    }
}
   
// Level 2, 3 and level 4 function
void basic_level(int class)
{
    int option, answer, result, n1, n2;
    char *operation, operator;
    srand(time(0));
    for (int i = 1; i <= 5; i++)
    {
        if (class == 1)
                option = 1;
        else if (class == 2)
                option = rand() % 2 + 2; // Genrates number from 2 to 3, as the remainder will be 1 or 0 and + 2
        else if (class == 3)
                option = rand() % 2 + 4; // Generate random from 4 to 5
        else if (class == 4)
                option = rand() % 5 + 2; // Generate number from 2 to 6
      
        switch(option)
        {
            // Level 1
            case 1: 
                n1 = rand() % 6 + 1;
                n2 = rand() % 5 + 3;
                printf("\tQues %d): How many stars are in this %d height?\n\n",i, n2);
                pattern_generate(n1, n2);
                break;
            // Level 2 and level 4
            case 2:
                operation = "Sum";
                operator = '+';
                n1 = rand() % 9 + 1;
                n2 = rand() % 9 + 1;
                print_operator(i, n1, n2, class,operator, operation);        
                scanf("%d", &answer);
                result = add(n1, n2);
                right_wrong(answer, result);  
                break;
            case 3:
                operation = "Minus";
                operator = '-';
                n1 = rand() % 20 + 11; //random no generate from 11-30 
                //19+11=30 (0-19)
                n2 = rand() % 9 + 1; // Generate number from 10 - 30
                print_operator(i, n1, n2, class,operator, operation);       
                scanf("%d", &answer);
                result = minus(n1, n2);
                right_wrong(answer, result);
                break;
            // Level 3 and level 4
            case 4:
                operation = "Product";
                operator = '*';
                n1 = rand() % 9 + 1;
                n2 = rand() % 9 + 1;
                print_operator(i, n1, n2, class,operator, operation);        
                scanf("%d", &answer);
                result = multi(n1, n2);
                right_wrong(answer, result);
                break;
            case 5:
                operation = "Quotient";
                operator = '/';
                n1 = rand() % 20 + 11;
                n2 = rand() % 9 + 1;
                printf("\tGive answer in intege of the division!\n");
                print_operator(i, n1, n2, class,operator, operation);
                scanf("%d", &answer);
                result = divide(n1, n2);
                right_wrong(answer, result);
                break;
            // Level 4    
            case 6:
                n1 = rand() % 9 + 1;
                printf("\tWhat is the factoiral of %d?\n\tAnswer:", n1);        
                scanf("%d", &answer);
                result = factorial(n1);
                right_wrong(answer, result);
                break;    
            default:
                break;         
        }  
         printf(pink_brg"\n\t=========================================================================================================\n\n"reset);  
    } 
}
void start_game()
{
    char choice;
    printf("\n\t|\t- Enter your name\n\t|\t[It should not be less than 3 or more than 5 characters]: ");
    scanf("  %s", user.name);

    printf("\t|\n\t|\t- Enter your (1 - 999 digits acceptable)registeration number: ");
    scanf("%d", &user.register_no);

    // If the conditions is not met
    if(strlen(user.name) <= 5 && strlen(user.name) >= 3 && isalpha(user.name[0]) && user.register_no >= 1 && user.register_no <= 999)
    {
        printf("\t|\t\tEntry successful!\n\t|\n\t|\n\t|");
    }
    else
    {
        printf("\t|\t\tInvalid data!!\n\n");
        exit(0);
    }
    printf("``````````````````````````````````````````````````````````````````````````|\n");     
   
     do 
    {
        // For levels
        printf("\t|\tEnter the level to play;\n");
        printf("\t|\t* Basic Level is for primary students, for class 1 up till 5.\n\t|\tYou can choose any one of the class accordingly\n\t|\n");  
        printf("\t|\t* Medium Level is for secondary students, for class 1 uptill 5.\n\t|\tYou can choose any one of the class accordingly\n\t|\n");
        printf("\t|\t* Hard Level is for college students, for class 11 and 12.\n\t|\tYou can choose any one of the class accordingly\n\t|\n\t|\n\t|");
        printf("\t\tBasic\tMedium\t Hard: ");
        scanf("%s", user.lvl_played);
        printf("\t|\n\t|\n\t|");
        // It the string
        if (strcmp(user.lvl_played, "Basic") == 0 )
        {
            printf("\t\tEnter a classes [1, 2, 3, 4, 5]: ");
            scanf("%d", &user.class);
            if (user.class > 5 || user.class < 0)
            {
                 printf(red"\t\t|\tInvalid Input!\n"reset);
                 exit(0);   
            }
            printf("\t_____________________________________________________________________________________________________________\n\n");
            printf(yellow"\t\t\t\t\t **QUIZ START!**\n"reset);
            printf("\t_____________________________________________________________________________________________________________\n\n");    
            if (user.class > 0 && user.class < 5)
                basic_level(user.class);
            if (user.class == 5 )
                problems(5);

        }
        else if (strcmp(user.lvl_played, "Medium") == 0 )
        {
            printf("\t|\tEnter a class [6, 7, 8, 9, 10]:");
            scanf("%d", &user.class);
            if (user.class < 6 || user.class > 10 )
                {
                 printf(red"\t\t|\tInvalid Input!\n"reset);
                 exit(0);   
            }
            else 
            {   
                printf("\t_____________________________________________________________________________________________________________\n\n");
                printf(yellow"\t\t\t\t\t**QUIZ START!**\n"reset);
                printf("\t_____________________________________________________________________________________________________________\n\n");    
                problems(user.class); 
            }    
        }
        else if (strcmp(user.lvl_played, "Hard") == 0 )
        {
            printf("\t|\tEnter a class [11, 12]: ");
            scanf("%d", &user.class);
            if (user.class == 11 || user.class == 12 )
                 {
                    printf("\t_____________________________________________________________________________________________________________\n\n");
                 printf(yellow"\t\t\t\t\t**QUIZ START!**\n"reset);
                printf("\t_____________________________________________________________________________________________________________\n\n");  
                problems(user.class); 
                      
            }
            else
            {
                 printf(red"\t\t|\tInvalid Input!\n"reset);
                exit(0);
            }         
        }
        else
        {
            printf(red"\t|\tInvalid Input!!\n"reset);
            exit(0);
        }          
        data_entry(); 
        quiz(user.correct, user.wrong);
        printf("--------------------------------------------------------------------------------------------------------------------------------------\n");  
        printf("\t|Do you want to play again, y or n: ");
        scanf(" %c", &choice);
        printf("\t|");
    } while (choice == 'y' || choice == 'Y');
    printf("_____________________________________________XXXXXXXXXXXXXXXXX_____________________________________________________\n\n");    
}
