#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

typedef struct //структура для координаты бегунка в меню
{
    int x;
    int y;
}point;

typedef struct //структура для FIO
{
    char F[30];
    char I[20];
    char O[30];
}name;

typedef struct //структура для всех записываемых данных в файл
{
  int ID;
  char NUMfl[5];
  char Fly[11];
  name FIO;
  char NUMpl[4];
  char weight[3];
}flypas;

typedef struct
{
    char typesort[20];
    int quantity;
    double sorttime;
}timecheck;
#endif // STRUCTS_H_INCLUDED

