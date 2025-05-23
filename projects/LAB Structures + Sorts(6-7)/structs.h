#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

typedef struct //структура дл€ координаты бегунка в меню
{
    int x;
    int y;
}point;

typedef struct //структура дл€ FIO
{
    char F[30];
    char I[20];
    char O[30];
}name;

typedef struct //структура дл€ всех записываемых данных в файл
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
//ƒЋя ѕќ»— ќ¬џ’ ƒ≈–≈¬№≈¬
typedef struct DuplicateNode
{
    flypas value;
    struct DuplicateNode * next;
}DuplicateNode;

typedef struct NodeT
{
    flypas value;
    DuplicateNode * duplicates;
    struct NodeT * LeftNode;
    struct NodeT * RightNode;
}NodeT;

typedef struct DuplicateNodeRB
{
    flypas value;
    struct DuplicateNodeRB * next;
}DuplicateNodeRB;

typedef struct NodeRB
{
    flypas value;
    char color;
    DuplicateNodeRB * duplicates;
    struct NodeRB * LeftNode;
    struct NodeRB * RightNode;
    struct NodeRB * ParentNode;
}NodeRB;
#endif // STRUCTS_H_INCLUDED
