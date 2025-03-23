#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "functions.h"
#include "generator.h"
flypas *(*func_ptr)(const char *, flypas *, int *) = ReadMassive;//указатель на функцию прочтения в массив из файла структур

void deepcopy(flypas *dest, const flypas *src)
{
    dest->ID = src->ID;

    strcpy(dest->NUMfl, src->NUMfl);
    strcpy(dest->Fly, src->Fly);
    strcpy(dest->NUMpl, src->NUMpl);
    strcpy(dest->weight, src->weight);

    strcpy(dest->FIO.F, src->FIO.F);
    strcpy(dest->FIO.I, src->FIO.I);
    strcpy(dest->FIO.O, src->FIO.O);
}
int CompareStructs(flypas * HUMAN, int h, int k)//функция сравнения двух ячеек массива структур, если структура с индексом h > k, то вернется 1, если h < k, то -1
{
    flypas *flypasA = HUMAN + h;
    flypas *flypasB = HUMAN + k;

    int cmp = strcmp(flypasA->FIO.F, flypasB->FIO.F);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;

    cmp = strcmp(flypasA->FIO.I, flypasB->FIO.I);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;

    cmp = strcmp(flypasA->FIO.O, flypasB->FIO.O);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;

    cmp = strcmp(flypasA->NUMfl, flypasB->NUMfl);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;

    cmp = strcmp(flypasA->Fly, flypasB->Fly);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;

    cmp = strcmp(flypasA->NUMpl, flypasB->NUMpl);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;

    cmp = strcmp(flypasA->weight, flypasB->weight);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;

    return 0;
}
int CompareQuickStructs(flypas * HUMAN, int h, flypas structure)//функция сравнения двух ячеек массива структур, если структура с индексом h > struct, то вернется 1, если h < struct, то -1
{
    flypas *flypasA = HUMAN + h;
    flypas *flypasB = &structure;

    int cmp = strcmp(flypasA->FIO.F, flypasB->FIO.F);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;

    cmp = strcmp(flypasA->FIO.I, flypasB->FIO.I);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;

    cmp = strcmp(flypasA->FIO.O, flypasB->FIO.O);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;

    cmp = strcmp(flypasA->NUMfl, flypasB->NUMfl);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;

    cmp = strcmp(flypasA->Fly, flypasB->Fly);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;

    cmp = strcmp(flypasA->NUMpl, flypasB->NUMpl);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;

    cmp = strcmp(flypasA->weight, flypasB->weight);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;

    return 0;
}
flypas * ReadMassive(const char * fname, flypas * HUMAN, int * humansize)//функция прочтения из файла, возвращает массив структур
{
    int i = 0;
    flypas NEED;
    FILE * p = fopen(fname, "rb+");
    if (!p)
        {
            printf("errno: %d ---> ", errno);
            perror(fname);
        }
    fseek(p, -1 * sizeof(flypas), SEEK_END);
    fread(&NEED, sizeof(flypas), 1, p);
    HUMAN = (flypas *)malloc(NEED.ID * sizeof(flypas));
    rewind(p);
    while (fread(&NEED, sizeof(flypas), 1, p) == 1)
        {
            deepcopy(HUMAN + i, &NEED);
            if (HUMAN == NULL)
            {
                perror("Error is");
                return 0;
            }
            i++;
        }
    * humansize = i - 1;
    fclose(p);
    return HUMAN;
}
//СОРТИРОВКА СЛИЯНИЕМ
void Merge(flypas * HUMAN, int low, int mid, int high, int flag)//функция соединяющая два отсортированных массива
{
    flypas * SECOND = (flypas*)malloc((high+1-low)*sizeof(flypas));
    int h,i,j,k;
    h=low;
    i=0;
    j=mid+1;

    while((h <= mid)&&(j <= high))
    {
        if(CompareStructs(HUMAN,h,j) == flag || CompareStructs(HUMAN,h,j) == 0)
        {
            SECOND[i] = HUMAN[h];
            h++;
        }
        else
        {
            SECOND[i] = HUMAN[j];
            j++;
        }
        i++;
    }

    if(h > mid)
    {
        for( k = j;k <= high; k++)
        {
            SECOND[i] = HUMAN[k];
            i++;
        }
    }
    else
    {
        for( k = h; k <= mid; k++)
        {
            SECOND[i] = HUMAN[k];
            i++;
        }
    }

    for( k = 0; k <= high - low; k++)
        HUMAN[k + low] = SECOND[k];
    free(SECOND);
}

void MergeSort(flypas * HUMAN, int low, int high, int flag)//функция непосредственной сортировки
{
    int mid;
    if(low < high)
    {
        mid = (low+high) / 2;
        MergeSort(HUMAN, low, mid, flag);
        MergeSort(HUMAN, mid+1,high, flag);
        Merge(HUMAN, low, mid, high,flag);
    }
}
//СОРТИРОВКА ШЕЙКЕРОМ
void ShakerSort(flypas *HUMAN, int humansize, int flag)//функция непосредственной сортировки
{
    int left = 0;
    int right = humansize;
    int swapped = 1;

    while (left < right && swapped)
    {
        swapped = 0;
        for (int i = left; i < right; i++)
        {
            if (CompareStructs(HUMAN, i, i + 1) == -flag)
            {
                flypas temp = HUMAN[i];
                HUMAN[i] = HUMAN[i + 1];
                HUMAN[i + 1] = temp;
                swapped = 1;
            }
        }
        right--;

        for (int i = right; i > left; i--)
        {
            if (CompareStructs(HUMAN, i - 1, i) == -flag)
            {
                flypas temp = HUMAN[i - 1];
                HUMAN[i - 1] = HUMAN[i];
                HUMAN[i] = temp;
                swapped = 1;
            }
        }
        left++;
}
}
//СОРТИРОВКА БЫСТРАЯ
int Quick(flypas *HUMAN, int low, int high, int flag)
{
    flypas pivot = HUMAN[high];
    int i = low - 1;
    if (flag == -1)
    {
    for (int j = low; j <= high - 1; j++)
    {
        int compareResult = CompareQuickStructs(HUMAN, j, pivot);

        if ((flag == -1 && (compareResult == -1 || compareResult == 0)))
        {
            i++;
            flypas temp = HUMAN[i];
            HUMAN[i] = HUMAN[j];
            HUMAN[j] = temp;
        }
    }
    flypas temp = HUMAN[i + 1];
    HUMAN[i + 1] = HUMAN[high];
    HUMAN[high] = temp;
    }
    else
    {
       for (int j = low; j < high; j++)
        {
            int compareResult = CompareQuickStructs(HUMAN, j, pivot);

            if ((flag == 1 && (compareResult == 1 || compareResult == 0)))
            {
                i++;
                flypas temp = HUMAN[i];
                HUMAN[i] = HUMAN[j];
                HUMAN[j] = temp;
            }
        }
        flypas temp = HUMAN[i + 1];
        HUMAN[i + 1] = HUMAN[high];
        HUMAN[high] = temp;
    }
    return i + 1;
}

void QuickSort(flypas *HUMAN, int low, int high, int flag)
{
    if (low < high)
    {
        int pivot = Quick(HUMAN, low, high, flag);
        QuickSort(HUMAN, low, pivot - 1, flag);
        QuickSort(HUMAN, pivot + 1, high, flag);
    }
}
/*
void Graphics(const char * ftname)
{
    int i = 0;
    timecheck TIMES;
    timecheck * y = malloc(50 * sizeof(timecheck));
    FILE * p = fopen(ftname, "r");
    if (!p)
    {
        printf("errno: %d ---> ", errno);
        perror(ftname);
    }
    rewind(p);
    while(fread(&TIMES, sizeof(timecheck), 1, p) == 1)
    {
        *(y + i) = TIMES;
        i++;
    }
    fclose (p);

    FILE *file = fopen("data.txt", "w");
    if (!file)
    {
        printf("Error");
    }
    printf("Choose what graphic you want to see?");
    int a = menuGraphic();
    switch(a)
    {
        case 0:
            for (int j = 0; j < i; j++)
                if (strcmp(y[j].typesort, "ShakeSort") == 0)
                fprintf(file, "%d %f\n", y[j].quantity, y[j].sorttime);
            break;
        case 1:
            for (int j = 0; j < i; j++)
                if (strcmp(y[j].typesort, "MergeSort") == 0)
                fprintf(file, "%d %f\n", y[j].quantity, y[j].sorttime);
            break;
        case 2:
            for (int j = 0; j < i; j++)
                if (strcmp(y[j].typesort, "QuickSort") == 0)
                fprintf(file, "%d %f\n", y[j].quantity, y[j].sorttime);
            break;
    }
    fclose(file);

    int result = system("gnuplot -p -e \"set title 'Sort'; set xlabel 'Size'; set ylabel 'Times (sec)'; plot 'data.txt' using 1:2 with linespoints title 'MergeSort'\"");

}*/
void AnySort(int humansize, int casechoose, flypas * HUMAN, const char * ftname, const char * fname, int flag)
{
    clock_t start, end;
    timecheck TIMES;
    switch (casechoose)
    {
        case 0:
            strcpy(TIMES.typesort,"ShakeSort");
            start = clock();
            ShakerSort(HUMAN, humansize, flag);
            end = clock();
            break;
        case 1:
            strcpy(TIMES.typesort,"MergeSort");
            start = clock();
            MergeSort(HUMAN, 0, humansize, flag);
            end = clock();
            break;
        case 2:
            strcpy(TIMES.typesort,"QuickSort");
            start = clock();
            QuickSort(HUMAN, 0, humansize, flag);
            end = clock();
            break;
    }
    TIMES.quantity = humansize + 1;
    TIMES.sorttime = (double) (end - start) / CLOCKS_PER_SEC;
    FILE * t = fopen(ftname, "a+");
    if (!t)
    {
        printf("errno: %d ---> ", errno);
        perror(fname);
    }
    fwrite(&TIMES, sizeof(timecheck), 1, t);
    fclose(t);
    FillMassive(HUMAN, fname, humansize + 1);
}
