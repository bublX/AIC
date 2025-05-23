#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "generator.h"
#include "structs.h"
#include "functions.h"
#include <conio.h>
//функции необходимые для генерации человека
int checkLastChar(const char* result, const char* glas)
{
    if (strlen(result) == 0)
        return 0;

    char lastChar = result[strlen(result) - 1];

    if (strchr(glas, lastChar) != NULL)
        return 1;

    return 0;
}
void SurnameGenerator(char * result, int * sex)
{
    char postfix[13][6] = {"ev", "ov","in", "ih", "yan", "in", "ina", "eva", "ina", "ova", "skaya", "skiy", "ko"};
    char sogl[] = "bcdfghklmnprstvz";
    char glas[] = "aoiue";
    char slogi[][3] = {"rt","zh","sh","br","dr", "gr"};
    int ne_i = rand() % 2 + 1;
    int length_one = rand() % 5 + 3;
    int way = rand() % length_one + 1;
    switch(ne_i)
    {
    case 1:
        if (length_one % 2 == 0)
        {
            for(int j = 0; j < length_one; j++)
            {
                if (j % 2 == 0)
                result[j] = glas[rand() % (strlen(glas) - 1)];
                else
                result[j] = sogl[rand() % (strlen(sogl) - 1)];
            }
        }
        else
        {
            for(int j = 0; j < length_one; j++)
            {
                if (j % 2 == 0)
                result[j] = sogl[rand() % (strlen(sogl) - 1)];
                else
                result[j] = glas[rand() % (strlen(glas) - 1)];
            }
        }

        strcat(result, postfix[rand() % 13]);
        result[0] = toupper((unsigned char)result[0]);
        break;
    case 2:
        if (way % 2 == 0) //Если согласная буква первая
        {
            for(int j = 0; j < length_one; j++)
            {
                if ( j == way)
                {
                    strcat(result, slogi[rand() % 6]);
                    if (rand() % 2 == 1)
                    result[strcspn(result, "\0")] = glas[rand() % (strlen(glas) - 1)];
                    else
                    result[j] = sogl[rand() % (strlen(sogl) - 1)];
                    j += 4;
                }
                else{
                    if(j % 2 == 0)
                    {
                        result[j] = sogl[rand() % (strlen(sogl) - 1)];
                    }
                    else
                    {
                        result[j] = glas[rand() % (strlen(glas) - 1)];
                    }
                }
            }
            if (strrchr(glas, result[strlen(result)]) != NULL)
            {
                strcat(result, postfix[rand() % 3 + 10]);
            }
        }
        else
        {
            for(int j = 0; j < length_one; j++)
            {
                if ( j == way)
                {
                    strcat(result, slogi[rand() % 6]);
                    if (rand() % 2 == 1)
                    result[strcspn(result, "\0")] = glas[rand() % (strlen(glas) - 1)];
                    else
                    result[j] = sogl[rand() % (strlen(sogl) - 1)];
                    j += 4;
                }
                else{
                    if(j % 2 != 0)
                    {
                        result[j] = sogl[rand() % (strlen(sogl) - 1)];
                    }
                    else
                    {
                        result[j] = glas[rand() % (strlen(glas) - 1)];
                    }
                }
            }
            if (checkLastChar(result, glas) == 1)
                strcat(result, postfix[rand() % 3 + 10]);
            else
                strcat(result, postfix[rand() % 10]);
        }

        result[0] = toupper((unsigned char)result[0]);
        break;
    }

    if (result[strlen(result) - 1] == 'a')
        * sex = 0;
    else
        * sex = 1;
}
void NameGenerator(char * result, int * sex)
{
    char nameF[20][20] = {
        "Anna", "Mariya", "Elena", "Olga", "Tatyana",
        "Natalya", "Yekaterina", "Irina", "Svetlana", "Viktoriya",
        "Aleksandra", "Darya", "Yuliya", "Lyudmila", "Galina",
        "Valentina", "Margarita", "Kseniya", "Vera", "Sofiya"
    };

    char nameM[20][20] = {
        "Aleksandr", "Dmitriy", "Sergey", "Andrey", "Aleksey",
        "Ivan", "Vladimir", "Mikhail", "Nikolay", "Yevgeniy",
        "Egor", "Konstantin", "Artem", "Maksim", "Oleg",
        "Roman", "Viktor", "Georgiy", "Vasiliy", "Boris"
    };
    if (* sex == 1)
        strcpy(result, nameM[rand() % 20]);
    else
        strcpy(result, nameF[rand() % 20]);
}
void SecondNameGenerator(char * result, int * sex)
{
    char help[20];
    char postfix[4][6] = {"evich","ovich","evna","ovna"};
    char nameM[20][20] = {
        "Georgiy", "Vasiliy", "Dmitriy", "Sergey", "Andrey", "Nikolay", "Yevgeniy","Aleksey",
        "Ivan", "Vladimir", "Mikhail","Egor", "Konstantin", "Artem", "Maksim", "Oleg", "Roman", "Viktor", "Boris", "Aleksandr"};
    if (* sex == 1)
    {
        int choicename = rand() % 20;
        if (choicename > 7)
        {
            strcpy(help, nameM[choicename]);
            strcat(help, postfix[1]);
            strcpy(result,help);
        }
        else
        {
            strcpy(help, nameM[choicename]);
            help[strlen(help) - 1] = '\0';
            strcat(help, postfix[0]);
            strcpy(result,help);
        }
    }
    else
    {
        int choicename = rand() % 20;
        if (choicename > 7)
        {
            strcpy(help, nameM[choicename]);
            strcat(help, postfix[3]);
            strcpy(result,help);
        }
        else
        {
            strcpy(help, nameM[choicename]);
            help[strlen(help) - 1] = '\0';
            strcat(help, postfix[2]);
            strcpy(result,help);
        }
    }
}
void PlaceGenerator(char * result)
{
    char Alphabet[] = "ABCDEF";
    char Numbers[] = "0123456789";
    result[0] = Alphabet[rand() % 6];
    result[1] = Numbers[rand() % 5];
    result[2] = Numbers[rand() % 10];
}
void NumberGenerator(char * result)
{
    char Numbers[] = "0123456789";
    result[0] = Numbers[rand() % 9 + 1];
    result[1] = Numbers[rand() % 10];
    result[2] = Numbers[rand() % 10];
}
void WeightGenerator(char * result)
{
    char Numbers[] = "123456789";
    result[0] = Numbers[rand() % 9];
}
int is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int days_in_month(int month, int year)
{
    if (month == 2)
        return is_leap_year(year) ? 29 : 28;
    else if (month == 4 || month == 6 || month == 9 || month == 11)

        return 30;
    else
        return 31;

}
void DataGenerator(char * result)
{
    int year = 2000 + rand() % 24;

    int month = 1 + rand() % 12;

    int day = 1 + rand() % days_in_month(month, year);

    sprintf(result, "%02d/%02d/%d", day, month, year);
}
void GeneratePerson(const char * fname, const char * ftname)
{
    flypas NEED;
    srand(time(NULL));
    int a = 1;
    int j = 1;
    int cou;
    int * sex = &a;
    char namik[20]= {};
    char second_name[30] = {};
    char arrN[5] = {};
    char arrP[4] = {};
    char arrW[3] = {};
    char date[11] = {};
    char button;
    system("cls");
    printf("Choose how many people you want to generate?\n");
    scanf("%d", &cou);
    FILE * p = fopen(fname, "ab+");
    for (int k = 0; k < cou; k++)
    {
        char surname[20] = {};
        SurnameGenerator(surname, sex);
        NameGenerator(namik, sex);
        SecondNameGenerator(second_name, sex);
        PlaceGenerator(arrP);
        NumberGenerator(arrN);
        WeightGenerator(arrW);
        DataGenerator(date);
        strcpy(NEED.FIO.F, surname);
        strcpy(NEED.FIO.I,namik);
        strcpy(NEED.FIO.O,second_name);
        strcpy(NEED.NUMpl,arrP);
        strcpy(NEED.NUMfl,arrN);
        strcpy(NEED.weight,arrW);
        strcpy(NEED.Fly, date);
        rewind(p);
        fwrite(&NEED, sizeof(flypas), 1, p);
    }
    fclose(p);

        p = fopen(fname, "rb+");
        if (p == NULL)
        {
            perror("Error opening file");
            return;
        }

    while (fread(&NEED, sizeof(flypas), 1, p) == 1)
        {
            NEED.ID = j;
            fseek(p, -sizeof(flypas), SEEK_CUR);
            fwrite(&NEED, sizeof(flypas), 1, p);
            j++;
            fseek(p, 0, SEEK_CUR);
        }
    fclose(p);
    printf("Press E to get to menu:\n");
    do
        button = getch();
    while (button != 'e');
    menu(fname, ftname);
}

