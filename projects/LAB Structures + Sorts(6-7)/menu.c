#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#include "searches.c"
#include "structs.h"
#include "functions.h"
#include "generator.h"

void menu(const char *fname, const char *ftname) //основное меню, в котором пользователь осуществляет выбор программы
{
    char mas[12][30], button;
    point a = {23, 0};
    point b = {24, 0};
    point c = {25, 0};
    do
    {
        sprintf(mas[0], " Add note to file     |    ");
        sprintf(mas[1], " Delete note from file|    ");
        sprintf(mas[2], " Find a note in file  |    ");
        sprintf(mas[3], " Edit note in file    |    ");
        sprintf(mas[4], " Print file as table  |    ");
        sprintf(mas[5], " Print time sort      |    ");
        sprintf(mas[6], " Create file          |    ");
        sprintf(mas[7], " Free file            |    ");
        sprintf(mas[8], " Generate person      |    ");
        sprintf(mas[9], " Sort file            |    ");
        sprintf(mas[10]," Show graphics        |    ");
        sprintf(mas[11]," Finish program       |    ");

        mas[a.y][a.x] = '<';
        mas[b.y][b.x] = '-';
        mas[c.y][c.x] = '|';
        system("cls");

        printf("Choose what you want to do(to choose press E):\n");

        for (int i = 0; i < 12; i++)
        {
            printf("-----------------------\n");
            printf("%s\n", mas[i]);
        }
        printf("-----------------------\n");
        button = getch();

        if ((button == 'w') && (a.y == 0))
        {
            a.y = 11;
            b.y = 11;
            c.y = 11;
        }
        else if (button == 'w')
        {
            a.y--;
            b.y--;
            c.y--;
        }

        if ((button == 's') && (a.y == 11))
        {
            a.y = 0;
            b.y = 0;
            c.y = 0;
        }
        else if (button == 's')
        {
            a.y++;
            b.y++;
            c.y++;
        }
    }
    while (button != 'e');
    switch(a.y)
        {
            case 0:
                AddANote(fname, ftname);
                break;
            case 1:
                DeleteNote(fname, ftname);
                break;
            case 2:
                menuSearch(ReadMassive, fname);
                break;
            case 3:
                UpdateFile(fname, ftname);
                break;
            case 4:
                PrintFile(fname, ftname);
                break;
            case 5:
                PrintFile2(fname, ftname);
                break;
            case 6:
                CreateBinary(fname, ftname);
                break;
            case 7:
                FreeFile(fname, ftname);
                break;
            case 8:
                GeneratePerson(fname, ftname);
                break;
            case 9:
                menuSort(ReadMassive, fname, ftname);
                break;
            case 10:
                Graphics(ftname);
                menu(fname, ftname);
                break;
            case 11:
                exit(0);
                break;
        }
}
void menuSearch(flypas *(*arrayCreator)(const char *, flypas *, int *), const char * fname, const char * ftname) //меню для выбора поискового параметра
{
    int humansize = 0;
    int * phumansize = &humansize;
    flypas * HUMAN = (flypas *)malloc(sizeof(flypas));
    HUMAN = arrayCreator(fname, HUMAN, phumansize);
    char mas[10][30], button;
    int i;
    point a = {0, 0};

    do
    {
        sprintf(mas[0], " Linear search               ");
        sprintf(mas[1], " Heap search                 ");
        sprintf(mas[2], " RB-Heap search              ");

        mas[a.y][a.x] = '>';
        system("cls");

        printf("Choose what you want to do(to choose press E):\n");

        for (i = 0; i < 3; i++)
        {
            printf("%s\n", mas[i]);
        }

        button = getch();

        if ((button == 'w') && (a.y == 0))
        {
            a.y = 2;
        }
        else if (button == 'w')
        {
                  a.y--;
        }

        if ((button == 's') && (a.y == 2))
        {
            a.y = 0;
        }
        else if (button == 's')
        {
            a.y++;
        }
    }
    while (button != 'e');
    system("cls");
    printf("Enter search string:");
    char * s = ReadList();
    switch(a.y)
    {
        case 0:
            LinearSearch(HUMAN, s, humansize);
            free(HUMAN);
            printf("Press E to get back to menu");
            do
                button = getch();
            while (button != 'e');
            menu(fname, ftname);
            break;
        case 1:
            HeapSearch(HUMAN, s, humansize);
            free(HUMAN);
            printf("Press E to get back to menu");
            do
                button = getch();
            while (button != 'e');
            menu(fname, ftname);
            break;
       /* case 2:*/
    }
}

int menuUpdate() //меню для выбора изменяемого поля
{
    char mas[10][30], button;
    int i;
    point a = {0, 0};

    do
    {
        sprintf(mas[0], " Edit  FLIGHT NUMBER        ");
        sprintf(mas[1], " Edit  DATA                 ");
        sprintf(mas[2], " Edit  FIO                  ");
        sprintf(mas[3], " Edit  SIT NUMBER           ");
        sprintf(mas[4], " Edit  LUGGAGE WEIGHT       ");

        mas[a.y][a.x] = '>';
        system("cls");

        printf("Choose what you want to do(to choose press E):\n");

        for (i = 0; i < 5; i++)
        {
            printf("%s\n", mas[i]);
        }

        button = getch();

        if ((button == 'w') && (a.y == 0))
        {
            a.y = 4;
        }
        else if (button == 'w')
        {
                  a.y--;
        }

        if ((button == 's') && (a.y == 4))
        {
            a.y = 0;
        }
        else if (button == 's')
        {
            a.y++;
        }
    }
    while (button != 'e');
    return a.y;
}
int menuUpdateFIO() //меню для выбора изменяемого поля ФИО
{
    char mas[3][30], button;
    int i;
    point a = {0, 0};

    do
    {
        sprintf(mas[0], " Edit  LAST NAME            ");
        sprintf(mas[1], " Edit  NAME                 ");
        sprintf(mas[2], " Edit  SECOND NAME          ");

        mas[a.y][a.x] = '>';
        system("cls");

        printf("Choose what you want to do(to choose press E):\n");

        for (i = 0; i < 3; i++)
        {
            printf("%s\n", mas[i]);
        }

        button = getch();

        if ((button == 'w') && (a.y == 0))
        {
            a.y = 2;
        }
        else if (button == 'w')
        {
                  a.y--;
        }

        if ((button == 's') && (a.y == 2))
        {
            a.y = 0;
        }
        else if (button == 's')
        {
            a.y++;
        }
    }
    while (button != 'e');
    return a.y;
}

int menuSortWay() //меню для выбора изменяемого поля ФИО
{
    char mas[2][30], button;
    int i;
    point a = {0, 0};

    do
    {
        sprintf(mas[0], " Sort ascending order       ");
        sprintf(mas[1], " Sort descending order      ");

        mas[a.y][a.x] = '>';
        system("cls");

        printf("Choose what you want to do(to choose press E):\n");

        for (i = 0; i < 2; i++)
        {
            printf("%s\n", mas[i]);
        }

        button = getch();

        if ((button == 'w') && (a.y == 0))
        {
            a.y = 1;
        }
        else if (button == 'w')
        {
                  a.y--;
        }

        if ((button == 's') && (a.y == 1))
        {
            a.y = 0;
        }
        else if (button == 's')
        {
            a.y++;
        }
    }
    while (button != 'e');
    return a.y;
}
void menuSort(flypas *(*arrayCreator)(const char *, flypas *, int *),const char * fname, const char * ftname)//меню для сортировки файла
{
    int humansize = 0;
    int * phumansize = &humansize;
    flypas * HUMAN = (flypas *)malloc(sizeof(flypas));
    HUMAN = arrayCreator(fname, HUMAN, phumansize);
    char mas[4][30], button;
    point a = {0, 0};

    do
    {
        sprintf(mas[0], " Shaker sort                ");
        sprintf(mas[1], " Merge sort                 ");
        sprintf(mas[2], " Quick sort                 ");

        mas[a.y][a.x] = '>';
        system("cls");
        printf("Choose what you want to do(to choose press E):\n");

        for (int i = 0; i < 3; i++)
        {
            printf("%s\n", mas[i]);
        }

        button = getch();

        if ((button == 'w') && (a.y == 0))
        {
            a.y = 2;
        }
        else if (button == 'w')
        {
            a.y--;
        }

        if ((button == 's') && (a.y == 2))
        {
            a.y = 0;
        }
        else if (button == 's')
        {
            a.y++;
        }
    }
    while (button != 'e');
    int flag = menuSortWay();
    switch(a.y)
    {
        case 0:
            AnySort(humansize, a.y, HUMAN, ftname, fname, flag);
            free(HUMAN);
            menu(fname, ftname);
            break;
        case 1:
            AnySort(humansize, a.y, HUMAN, ftname, fname, flag);
            free(HUMAN);
            menu(fname, ftname);
            break;
        case 2:
            AnySort(humansize, a.y, HUMAN, ftname, fname, flag);
            free(HUMAN);
            menu(fname, ftname);
            break;
    }
}
int menuGraphic() //меню для выбора изменяемого поля ФИО
{
    char mas[3][30], button;
    int i;
    point a = {0, 0};

    do
    {
        sprintf(mas[0], " ShakeSort graphic          ");
        sprintf(mas[1], " MergeSort graphic          ");
        sprintf(mas[2], " QuickSort graphic          ");

        mas[a.y][a.x] = '>';
        system("cls");

        printf("Choose what you want to do(to choose press E):\n");

        for (i = 0; i < 3; i++)
        {
            printf("%s\n", mas[i]);
        }

        button = getch();

        if ((button == 'w') && (a.y == 0))
        {
            a.y = 2;
        }
        else if (button == 'w')
        {
                  a.y--;
        }

        if ((button == 's') && (a.y == 2))
        {
            a.y = 0;
        }
        else if (button == 's')
        {
            a.y++;
        }
    }
    while (button != 'e');
    return a.y;
}
