#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "generator.h"
#include "structs.h"
#include "searches.h"

NodeRB * CreateNodeRB(flypas item)
{
    NodeRB * node = (NodeRB *) malloc(sizeof(NodeRB));
    node -> duplicates = NULL;
    node -> value = item;
    node -> color = 'R';
    node -> LeftNode = NULL;
    node -> RightNode = NULL;
    node -> ParentNode = NULL;
}
/*
NodeRB * AddNodeRB(NodeRB * node, flypas item)
{

}*/
