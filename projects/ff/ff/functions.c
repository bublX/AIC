#include "functions.h"
#include "structs.h"

#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>

typedef int * (* Comp) (int *, flypas * , int, char *, int *); //объявление указателя на функцию, которым пользуемся в функции поиска SearchNote, указывает на Compare

int * Compare( int * INDEX, flypas * p, int i, char * s, int * t) //вспомогательная функция сравнения для поиска по файлу
{

    char str_ID[8] = {};
    sprintf(str_ID, "%d", p->ID);

    switch(i)
    {
        case 1:
            if(strstr(str_ID, s) != NULL)
            {
                INDEX[*t] = p->ID;
                (*t)++;
            }
            break;
        case 2:
            if(strstr(p->NUMfl, s))
            {
                INDEX[*t] = p->ID;
                (*t)++;
            }
            break;
        case 3:
            if(strstr(p->Fly, s))
            {
                INDEX[*t] = p->ID;
                (*t)++;
            }
            break;
        case 4:
        {
            if(strstr(p->FIO.F, s))
            {
                INDEX[*t] = p->ID;
                (*t)++;
            }
            else if (strstr(p->FIO.I, s))
            {
                INDEX[*t] = p->ID;
                (*t)++;
            }
            else if (strstr(p->FIO.O, s))
            {
                INDEX[*t] = p->ID;
                (*t)++;
            }
            break;
        }
        break;
        case 5:
            if(strstr(p->NUMpl, s))
            {
                INDEX[*t] = p->ID;
                (*t)++;
            }
            break;
        case 6:
            if(strstr(p->weight, s))
            {
                INDEX[*t] = p->ID;
                (*t)++;
            }
            break;
    }
    int * temp = realloc(INDEX, (*t + 1) * sizeof(int));
    INDEX = temp;
    if (*t != 0)
            printf("Not found\n");
    return INDEX;
}
flypas FieldEditor(flypas *p, int i, int j) //вспомогательная функция изменения файла, позволяет изменять конкретное поле структуры
{
    flypas Help;
    switch(i)
            {
                case 1:
                    scanf("%s", Help.NUMfl);
                    strcpy(p->NUMfl, Help.NUMfl);
                    break;
                case 2:
                    scanf("%s", Help.Fly);
                    strcpy(p->Fly, Help.Fly);
                    break;
                case 3:
                    switch (j)
                    {
                        case 1:
                                scanf("%s", Help.FIO.F);
                                strcpy(p->FIO.F, Help.FIO.F);
                            break;
                        case 2:
                                scanf("%s", Help.FIO.I);
                                strcpy(p->FIO.I, Help.FIO.I);
                            break;
                        case 3:
                                scanf("%s", Help.FIO.O);
                                strcpy(p->FIO.O, Help.FIO.O);
                            break;
                    }
                    break;
                case 4:
                        scanf("%s", Help.NUMpl);
                        strcpy(p->NUMpl, Help.NUMpl);
                    break;
                case 5:
                        scanf("%s", Help.weight);
                        strcpy(p->weight, Help.weight);
                    break;
            }
            return * p;
}
int * Counter(const char * fname, int * count) //функция счётчика, позволяет найти количество уже записанных строк в файл для дальнейшей индексации, удаления, изменения
{
    FILE * p = fopen(fname, "rb+");
    *count = 0;
    while (!feof(p))
	{
		flypas NEED;

		if (fread(&NEED, sizeof(flypas), 1, p))
            (*count)++;
	}
	fclose(p);
    return count;
}



void FillMassive(flypas *HUMAN, const char *fname, int x) //функция, которая позволяет записать заранее инициализированный массив в файл
{
    flypas NEED;
    int j = 1;
    FILE *p = fopen(fname, "rb+");
    if (!p)
    {
        printf("errno: %d ---> ", errno);
        perror(fname);
    }
        fseek(p, 0, SEEK_SET);
        fwrite(HUMAN, sizeof(flypas), x, p);
        rewind(p);
        while (fread(&NEED, sizeof(flypas), 1, p) == 1)
        {
            NEED.ID = j;
            fseek(p, -sizeof(flypas), SEEK_CUR);
            fwrite(&NEED, sizeof(flypas), 1, p);
            j++;
            fseek(p, 0, SEEK_CUR);
        }
    fclose(p);
}
void CreateBinary(const char * fname, const char * ftname) //функция создания файла
{
    FILE * p = fopen(fname, "wb+");
    if (!p)
    {
        printf("errno: %d ---> ", errno);
        perror(fname);
    }
    fclose(p);
    FILE * f = fopen(ftname, "wb+");
    if (!f)
    {
        printf("errno: %d ---> ", errno);
        perror(ftname);
    }
    fclose(f);
    system("cls");
    menu(fname, ftname);
}
void PrintFile1(const char * fname, const char * ftname) //функция печати файла в виде таблицы
{
    system("cls");
    FILE * p = fopen(fname, "rb");
    if (!p)
    {
        printf("errno: %d ---> ", errno);
        perror(fname);
    }

    flypas NEED;

    rewind(p);

    printf("+---------+--------------+------------+-----------------+-----------------+-----------------+------------+--------------+\n");
    printf("| ID      | Flight Number| Date       | Last Name       | Name            | Second Name     | Sit Number |Weight Luggage|\n");
    printf("+---------+--------------+------------+-----------------+-----------------+-----------------+------------+--------------+\n");

    while(fread(&NEED, sizeof(flypas), 1, p) == 1)
    {
        printf("| %-7d | %-12s | %-10s | %-15s | %-15s | %-15s | %-10s | %-11s  |\n", NEED.ID, NEED.NUMfl, NEED.Fly, NEED.FIO.F, NEED.FIO.I, NEED.FIO.O, NEED.NUMpl, NEED.weight);
    }
    fclose(p);

    printf("+---------+--------------+------------+-----------------------------------------------------+------------+--------------+\n");
}
void PrintFile(const char * fname, const char * ftname) //функция печати файла с возвратом в меню
{
    PrintFile1(fname, ftname);
    printf("Press E to return to menu:\n");
    char button;
    do
    button = getch();
    while (button != 'e');
    menu(fname, ftname);
}
void AddANote(const char * fname, const char * ftname) //функция добавления записи в файл
{
    system("cls");
    flypas NEED;
    char button;
    int count;
    int * numerate;

    numerate = Counter(fname, &count);
    *numerate += 1;

        do
        {

            FILE * p = fopen(fname, "ab+");

            if (!p)
            {
                printf("errno: %d ---> ", errno);
                perror(fname);
            }

            NEED.ID = *numerate;
            (*numerate)++;

            printf("Enter flight number:\n");
            scanf("%s",NEED.NUMfl);

            printf("Enter data of flight(03 01 2025):\n");
            scanf("%s",NEED.Fly);

            printf("Enter name(IVANOV IVAN IVANOVICH):\n");
            scanf("%s",NEED.FIO.F);
            scanf("%s",NEED.FIO.I);
            scanf("%s",NEED.FIO.O);

            printf("Enter your sit number(A00):\n");
            scanf("%s", NEED.NUMpl);

            printf("Enter weight of luggage:\n");
            scanf("%s",NEED.weight);

            fwrite(&NEED, sizeof(flypas), 1, p);
            fclose(p);

            printf("Press any key to continue\n");
            printf("Press E to get back to menu\n");
            button = getch();
            system("cls");
        }
    while (button != 'e');
    menu(fname, ftname);
}
void DeleteNote(const char * fname, const char * ftname) //функция удаления записи из файла
{
    int i, a, count;
    flypas NEED;
    FILE *p = fopen(fname, "rb+");
    if (!p)
    {
        printf("errno: %d ---> ", errno);
        perror(fname);
    }

    rewind(p);
    system("cls");

    PrintFile1(fname, ftname);

    do  //выбор строки для удаления с проверкой на корректный ввод
    {
        printf("Choose string to delete:\n");
        a = scanf("%d", &i);
        while((getchar() != '\n'));
        if(a != 1)
        {
            printf("Input ID again\n");
        }

    }
    while(a != 1);

    if (i <= *Counter(fname, &count)) //проверка на существование строки с таким ID
    {
        fseek(p, (i) * (long)sizeof(flypas), SEEK_SET);
        while (!feof(p))
        {
            if (!fread(&NEED, sizeof(flypas), 1, p))
                break;

            fseek(p, -2 * (long)sizeof(flypas),SEEK_CUR);
            fwrite(&NEED, sizeof(flypas), 1, p);
            fseek(p, sizeof(flypas), SEEK_CUR);
        }
        //изменение размера файла
        long curFileSize = ftell(p);
        int desc = _fileno(p);
        _chsize(desc, curFileSize - sizeof(flypas));
        fclose(p);

        p = fopen(fname, "rb+");
        if (p == NULL)
        {
            perror("Error opening file");
            return;
        }

        int j = 1;
        //переиндексация после удаления
        while (fread(&NEED, sizeof(flypas), 1, p) == 1)
        {
            NEED.ID = j;
            fseek(p, -sizeof(flypas), SEEK_CUR);
            fwrite(&NEED, sizeof(flypas), 1, p);
            j++;
            fseek(p, 0, SEEK_CUR);
        }

        fclose(p);
    }
    else
        printf("Wrong ID\n");
    char button;
    printf("Press E to get to menu:\n");
    do
        button = getch();
    while (button != 'e');
    menu(fname, ftname);
}
void UpdateFile(const char * fname, const char * ftname) //функция изменения конкретного поля структуры
{
    flypas NEED;
    char button;
    int id, a,count;
    int i = 0, j = 0;

    FILE * p = fopen(fname, "rb+");
    if (!p)
    {
        printf("errno: %d ---> ", errno);
        perror(fname);
    }
    system("cls");
    do      //ввод ID для изменения с проверкой
    {
        printf("Enter ID to edit:\n");
        a = scanf("%d", &id);
        while((getchar() != '\n'));
        if(a != 1)
        {
            printf("Input ID again\n");
        }
    }
    while (a!= 1);
    system("cls");
    if (id <= *Counter(fname, &count)) //проверка на количество строк под вписанный ID
    {
        i = menuUpdate() + 1;
        if (i == 3)
        {
            j = menuUpdateFIO() + 1;
        }
        printf("Enter the change value:\n");
        rewind(p);
        while(fread(&NEED, sizeof(flypas), 1, p) == 1)
        {
            if(NEED.ID == id)
            {
                FieldEditor(&NEED, i, j);
                break;
            }
        }
        fseek(p, -sizeof(flypas),SEEK_CUR);
        fwrite(&NEED, sizeof(flypas), 1, p);
    }
    else
        printf("Wrong ID\n");

    fclose(p);

    printf("Press E to get to menu:\n");
    do
        button = getch();
    while (button != 'e');
    menu(fname, ftname);
    }
void SearchNote(const char * fname, const char * ftname, Comp CMP) //функция поиска по файлу
{
    flypas NEED;
    char button, s[30];
    int i = menuSearch() + 1;
    int v = 0;
    int * l = &v;
    int * INDEX = malloc(sizeof(int));


    FILE * p = fopen(fname, "rb");
    if (!p)
    {
        printf("errno: %d ---> ", errno);
        perror(fname);
    }
    printf("Enter to search:\n");
    scanf("%s", s);
    while(fread(&NEED, sizeof(flypas), 1, p) == 1)
    {
        CMP(INDEX, &NEED, i, s, l);
    }
    *l = 0;

    rewind(p);
    system("cls");
    int k = 0;
    while(fread(&NEED, sizeof(flypas), 1, p) == 1)
    {
        if(INDEX[k] == NEED.ID)
        {
            printf("+-----+--------------+------------+-----------------+-----------------+-----------------+------------+---------------+\n");
            printf("| %-3d | %-12s | %-10s | %-15s | %-15s | %-15s | %-10s | %-13s |\n", NEED.ID, NEED.NUMfl, NEED.Fly, NEED.FIO.F, NEED.FIO.I, NEED.FIO.O, NEED.NUMpl, NEED.weight);
            k++;
            printf("+-----+--------------+------------+-----------------------------------------------------+------------+---------------+\n");
        }
    }
    fclose(p);
    free(INDEX);
    printf("Press E to get to menu:\n");
    do
        button = getch();
    while (button != 'e');
    menu(fname, ftname);
}

void PrintFile2(const char * fname, const char * ftname)
{
    timecheck TIMES;
    FILE * t = fopen(ftname, "a+");
     if (!t)
    {
        printf("errno: %d ---> ", errno);
        perror(fname);
    }
    rewind(t);
    system("cls");
    rewind(t);
    printf("+-----------------+----------------+-------------------+\n");
    printf("| Sort type       | Quantity       | Sort time         |\n");
    printf("+-----------------+----------------+-------------------+\n");

    while (fread(&TIMES, sizeof(timecheck), 1, t) == 1)
    {
        printf("| %-15s | %-14d | %-17.10f |\n", TIMES.typesort, TIMES.quantity, TIMES.sorttime);
    }
    printf("+-----------------+----------------+-------------------+\n");
    printf("Press E to return to menu:\n");
    fclose(t);
    char button;
    do
    button = getch();
    while (button != 'e');
    menu(fname, ftname);
}
void FreeFile(const char * fname, const char * ftname)
{
    FILE * p = fopen(fname, "wb+");
    if (!p)
    {
        printf("errno: %d ---> ", errno);
        perror(fname);
    }
    fclose(p);
    menu(fname, ftname);
}



































































