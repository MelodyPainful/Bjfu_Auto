//190603113 自动化191 董萱 二叉树的基本操作
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define elemType int                
typedef struct BiTNode{             //定义树
    elemType data;
    struct BiTNode *lchild, *rchild; //左右孩子指针
    }BiTNode, *BiTree;
void CreateBiTree(BiTree *T){
     *T=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data=1;
    (*T)->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild=(BiTNode*)malloc(sizeof(BiTNode));
  
    (*T)->lchild->data=2;
    (*T)->lchild->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data=5;
    (*T)->lchild->rchild->lchild=NULL;
    (*T)->lchild->rchild->rchild=NULL;
    (*T)->rchild->data=3;
    (*T)->rchild->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data=6;
    (*T)->rchild->lchild->lchild=NULL;
    (*T)->rchild->lchild->rchild=NULL;
    (*T)->rchild->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data=7;
    (*T)->rchild->rchild->lchild=NULL;
    (*T)->rchild->rchild->rchild=NULL;
    (*T)->lchild->lchild->data=4;
    (*T)->lchild->lchild->lchild=NULL;
    (*T)->lchild->lchild->rchild=NULL;
}; //创建了一个二叉树
void displayElem(BiTNode* elem)
{
    printf("%d",elem->data);
};

void PreOrderTraverse(BiTree T){
    if(T){
        displayElem(T);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
    //如果节点为空，返回上一层
    return;
};
void InOrderTraverse(BiTree T)     //中序遍历
{
    if(T){
        InOrderTraverse(T->lchild);
        displayElem(T);
        InOrderTraverse(T->rchild);
    }
    return;
};

void PostOrderTraverse(BiTree T){ //后序遍历
    if (T) {
        PostOrderTraverse(T->lchild);//遍历左孩子
        PostOrderTraverse(T->rchild);//遍历右孩子
        displayElem(T);//调用操作结点数据的函数方法
    }
    //如果结点为空，返回上一层
    return;
};
int NodeCount(BiTree T )       //统计二叉树中节点的个数
{
    if(T==NULL) return 0;
    else 
        return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
};

int LeafNodeCount(BiTree T)
{
    static int leafNum=0;
    if(T)
    {
        if(T->lchild==NULL&&T->rchild==NULL)
            leafNum++;
         LeafNodeCount(T->lchild);
         LeafNodeCount(T->rchild);
    }
    return leafNum;
}
int Depth(BiTree T)
{
    int m, n;
    if (T == NULL)
        return 0; //如果是空树，深度为0，递归结束
    else
    {
        m = Depth(T->lchild); //递归计算左子树的深度记为m
        n = Depth(T->rchild); //递归计算右子树的深度记为n
        if (m > n)
            return (m + 1); //二叉树的深度为m 与n的较大者加1
        else
            return (n + 1);
    }};
int main(void)
{   printf("Write By 董萱，自动化191\n");
    printf("\n创建二叉树.......");
    BiTree tree;
    CreateBiTree(&tree);
    printf("\n前序遍历.......\n");
    PreOrderTraverse(tree);
    printf("\n中序遍历.......\n");
    InOrderTraverse(tree);
    printf("\n后序遍历.......\n");
    PostOrderTraverse(tree);
    printf("\n统计叶节点个数.......");
    printf("\nLeafNodeCount = %d",LeafNodeCount(tree));
    printf("\n计算二叉树的深度\n");
    printf("Depth = %d \n" ,Depth(tree));
    getchar();
}