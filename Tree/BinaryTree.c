#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left,*right;
};

void preOrder(struct node *currNode)
{
if (currNode == NULL)
{
return;
}
printf("%d ", currNode->data);
preOrder(currNode->left);
preOrder(currNode->right);
}

void inOrder(struct node *currNode)
{
if (currNode == NULL)
{
return;
}
inOrder(currNode->left);
printf("%d ", currNode->data);
inOrder(currNode->right);
}

void postOrder(struct node *currNode)
{
if (currNode == NULL)
{
return;
}
postOrder(currNode->left);
postOrder(currNode->right);
printf("%d ", currNode->data);
}

void printLevel(struct node *currNode, int level)
{
if (currNode == NULL)
return;
if (level == 1)
{
printf("%d ", currNode->data);
}
else if (level > 1)
{
printLevel(currNode->left, level - 1);
printLevel(currNode->right, level - 1);
 }
}

int max(int num1, int num2)
{
return (num1 > num2) ? num1 : num2;
}

int MaxDepth(struct node *currNode)
{
if (currNode == NULL)
{
return 0;
}
return 1 + max(MaxDepth(currNode->left), MaxDepth(currNode->right));
}

void levelOrder(struct node *root)
{
int treeHeight = MaxDepth(root);
for (int i = 1; i <= treeHeight; i++)
 {
printLevel(root, i);
 }
}

struct node *create(int d)
{
struct node *p;
if (d == -1)
return NULL;
  
p = (struct node *)malloc(sizeof(struct node));
p->data = d;
printf("Enter left child of %d: ", d);
int x;
scanf("%d", &x);
p->left = create(x);
printf("Enter right child of %d: ", d);
scanf("%d", &x);
p->right = create(x);
return p;
}

void MirrorImage(struct node *currNode)
{
if (currNode == NULL)
{
return;
}
  
struct node *temp = currNode->left;
currNode->left = currNode->right;
currNode->right = temp;
MirrorImage(currNode->left);
MirrorImage(currNode->right);
}

void leafNodes(struct node *currNode)
{
if (currNode == NULL)
{
return;
}
else if (currNode->left == NULL && currNode->right == NULL)
{
printf("%d ", currNode->data);
return;
}
leafNodes(currNode->left);
leafNodes(currNode->right);
}

int CountNodes(struct node *currNode)
{
if (currNode == NULL)
{
return 0;
}
  
int leftCount = CountNodes(currNode->left);
int rightCount = CountNodes(currNode->right);
return 1 + leftCount + rightCount;
}


int main()
{
int d;
printf("Enter ( -1 ) for no node ");
printf("\nEnter root node data: ");
scanf("%d", &d);
 
struct node *root = create(d);
 
printf("\nPre-order traversal: ");
preOrder(root);
printf("\n");
 
printf("In-order traversal: ");
inOrder(root);
printf("\n");
 
printf("Post-order traversal: ");
postOrder(root);
printf("\n");
 
printf("Level-order traversal: ");
levelOrder(root);
printf("\n");
printf("Height of the Binary tree: %d\n", MaxDepth(root));
printf("Level wise traversal of binary tree: ");
levelOrder(root);
printf("\n");
MirrorImage(root);
printf("Level wise traversal of mirror image: ");
levelOrder(root);
printf("\n");
printf("Total number of nodes : %d\n", CountNodes(root));
return 0;
}
