#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "generator.h"
#include "structs.h"
#include "searches.h"

void PrintValue();
int Comparison(flypas flypasA, flypas flypasB, char * str);

void Print()
{
    printf("+---------+--------------+------------+-----------------+-----------------+-----------------+------------+--------------+\n");
}

void AddDuplicates(DuplicateNode ** head, flypas item)
{
    DuplicateNode * NewDup = (DuplicateNode *)malloc(sizeof(DuplicateNode));
    NewDup -> value = item;
    NewDup -> next = * head;
    * head = NewDup;
}

NodeT * CreateNode(flypas item)
{
    NodeT * NewNode = (NodeT *)malloc(sizeof(NodeT));
    NewNode->duplicates = NULL;
    NewNode -> value = item;
    NewNode -> LeftNode = NULL;
    NewNode -> RightNode = NULL;
    return NewNode;
}

NodeT * AddNode(NodeT * node, flypas item)
{
    if (node == NULL)
        return CreateNode(item);
    if (Comparison(node -> value, item, NULL) == 1)
        node -> LeftNode = AddNode(node -> LeftNode, item);
    else if (Comparison(node -> value, item, NULL) == -1)
        node -> RightNode = AddNode(node -> RightNode, item);
    else
        AddDuplicates(&(node -> duplicates), item);
    return node;
}

void PrintDuplicates(NodeT * node)
{
    if (node == NULL)
        return;

    DuplicateNode * current = node -> duplicates;

    if (current == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            PrintValue(current->value);
            Print();
            current = current->next;
        }
    }
}

void PrintValue(flypas NEED)
{
    Print();
    printf("| %-7d | %-12s | %-10s | %-15s | %-15s | %-15s | %-10s | %-12s |\n",
               NEED.ID, NEED.NUMfl, NEED.Fly, NEED.FIO.F, NEED.FIO.I, NEED.FIO.O, NEED.NUMpl, NEED.weight);
    Print();
}

NodeT * FindNode(NodeT * node, char * str)
{
    if (node == NULL)
        return NULL;

    int cmp = Comparison(node -> value, (flypas){0}, str);

    if (cmp < 0)
        return FindNode(node -> RightNode, str);
    else if (cmp > 0)
        return FindNode(node -> LeftNode, str);
    else
    {
        flypas NEED = node -> value;
        PrintValue(NEED);
        PrintDuplicates(node);
        return node;
    }
    return NULL;
}


void PrintTree(NodeT * node, int level)//вывод дерева
{
    if (node == NULL) return;
    PrintTree(node -> RightNode, level + 1);

    for (int i = 0; i < level; i++)
        printf("   ");

    printf("%s\n", node -> value.FIO.F);

    PrintTree(node -> LeftNode, level + 1);
}

/*
void PrintTree(NodeT* node, int level)//вывод в порядке возрастания
{
    if (node == NULL) return;
    PrintTree(node->LeftNode, level + 1);

    printf("%s\n", node->value.FIO.F);
    PrintTree(node->RightNode, level + 1);
}*/

int Comparison(flypas flypasA, flypas flypasB, char * str)
{
    if (str == NULL)
    {
        int cmp = strcmp(flypasA.FIO.F, flypasB.FIO.F);
        return cmp;
    }
    else
    {
        if (strstr(flypasA.FIO.F, str))
            return 0;
        return strcmp(flypasA.FIO.F, str);
    }
}

int Compare(flypas NEED, char * s)//вспомогательная функция сравнения для ЛИНЕЙНОГО поиска
{
    int j = 0;
    if (strstr(NEED.Fly, s))
        j = 1;
    else if (strstr(NEED.FIO.F, s))
        j = 1;
    else if (strstr(NEED.FIO.I, s))
        j = 1;
    else if (strstr(NEED.FIO.O, s))
        j = 1;
    if (j == 1)
    {
        Print();
        printf("| %-7d | %-12s | %-10s | %-15s | %-15s | %-15s | %-10s | %-11s  |\n",
           NEED.ID, NEED.NUMfl, NEED.Fly, NEED.FIO.F, NEED.FIO.I, NEED.FIO.O, NEED.NUMpl, NEED.weight);
        return 0;
    }
    return 1;
}

void LinearSearch(flypas * HUMAN, char * str, int humansize)
{
    Print();
    printf("| ID      | Flight Number| Date       | Last Name       | Name            | Second Name     | Sit Number |Weight Luggage|\n");
    for (int i = 0; i < humansize + 1; i++)
    {
        Compare(HUMAN[i], str);
    }
    Print();
}


void HeapSearch(flypas * HUMAN, char * str, int humansize)
{
    NodeT * root = CreateNode(HUMAN[0]);
    for (int i = 1; i < humansize + 1; i++)
        AddNode(root, HUMAN[i]);
    PrintTree(root, 0);
    FindNode(root, str);
}


