/* I am going to build a binary Tree - why? IDK who cares? I will build it
and I'll show you a way to reverse it - we can do it by printing, or by various 
stacks, and by node swapping. */

/*

  Compile: gcc -o TreeReversal -g TreeReversal.c
  Run ./TreeReversal

  going to put the github commands here since I am brain crippled.

  echo "# CSource-Binary-Tree" >> README.md
  git init
  git add README.md
  git commit -m "first commit"
  git remote add origin https://github.com/lordhershey/CSource-Binary-Tree.git
  git push -u origin master
 */

#ifdef __linux__
#  include <getopt.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>   /* umask */
#include <fcntl.h>
#include <ctype.h>      /* isalnum, isdigit */
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/*structures*/

typedef struct {
  void *left;
  void *right;
  int value;
} BINARY_NODE;

/*Will be used for various things*/
typedef struct {
  int value;
  int level;
  void *next;
} NODE;

void reverseTree(BINARY_NODE *root)
{

  BINARY_NODE *tmp = NULL;
  
  if(NULL == root)
    {
      return;
    }

  reverseTree(root->left);
  reverseTree(root->right);
  
  tmp = root->left;
  root->left = root->right;
  root->right = tmp;
}

void insertTreeNode(BINARY_NODE **root,BINARY_NODE *node)
{
  if(NULL == (*root))
    {
      *root = node;
      node->left = NULL;
      node->right = NULL;
      return;
    }

  if((*root)->value > node->value)
    {
      /*Left Insert*/
      printf("Insert %d left of %d\n",node->value,(*root)->value);
      insertTreeNode((BINARY_NODE **)&(*root)->left,node);
    }
  else
    {
      /*Right Insert*/
      printf("Insert %d right of %d\n",node->value,(*root)->value);
      insertTreeNode((BINARY_NODE **)&(*root)->right,node);
    }
}

void printTreeInOrder(BINARY_NODE *node)
{
  if(NULL == node)
    {
      return;
    }

  printTreeInOrder((BINARY_NODE *)node->left);
  printf("%d ", node->value);
  printTreeInOrder((BINARY_NODE *)node->right);
  
}

void printTreeInReverseOrder(BINARY_NODE *node)
{
  if(NULL == node)
    {
      return;
    }
  
  printTreeInReverseOrder((BINARY_NODE *)node->right);
  printf("%d ", node->value);
  printTreeInReverseOrder((BINARY_NODE *)node->left);
}

int main (int argc, char *argv[])
{
  BINARY_NODE *head = NULL;
  BINARY_NODE *tmp = NULL;

  /*These inserts should result in a tree like so:

          4
      2       6
    1   3   5   7

  */
  tmp = malloc(sizeof(BINARY_NODE));
  memset((char *)tmp,'\0',sizeof(BINARY_NODE));
  tmp->value = 4;
  insertTreeNode(&head,tmp);
  
  tmp = malloc(sizeof(BINARY_NODE));
  memset((char *)tmp,'\0',sizeof(BINARY_NODE));
  tmp->value = 2;
  insertTreeNode(&head,tmp);
  
  tmp = malloc(sizeof(BINARY_NODE));
  memset((char *)tmp,'\0',sizeof(BINARY_NODE));
  tmp->value = 6;
  insertTreeNode(&head,tmp);
  
  tmp = malloc(sizeof(BINARY_NODE));
  memset((char *)tmp,'\0',sizeof(BINARY_NODE));
  tmp->value = 1;
  insertTreeNode(&head,tmp);
  
  tmp = malloc(sizeof(BINARY_NODE));
  memset((char *)tmp,'\0',sizeof(BINARY_NODE));
  tmp->value = 3;
  insertTreeNode(&head,tmp);
  
  tmp = malloc(sizeof(BINARY_NODE));
  memset((char *)tmp,'\0',sizeof(BINARY_NODE));
  tmp->value = 5;
  insertTreeNode(&head,tmp);
  
  tmp = malloc(sizeof(BINARY_NODE));
  memset((char *)tmp,'\0',sizeof(BINARY_NODE));
  tmp->value = 7;
  insertTreeNode(&head,tmp);

  printf("Print the Tree in Order:\n");
  printTreeInOrder(head);
  printf("\n\n");

  printf("Print the Tree in Reverse Order:\n");
  printTreeInReverseOrder(head);
  printf("\n\n");

#if 0
  printf("Print the Tree in Depth First: \n");
  printTreeInDepthFirstOrder(head);
  printf("\n\n");
#endif

printf("=============== Reverse the Tree Structure ===============\n\n");
  
  reverseTree(head);

  printf("Print the Tree in Order:\n");
  printTreeInOrder(head);
  printf("\n\n");

  printf("Print the Tree in Reverse Order:\n");
  printTreeInReverseOrder(head);
  printf("\n\n");
  
}
