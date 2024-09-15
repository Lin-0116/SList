//
// Created by cp on 2024/9/15.
//

#include "SList.h"

void SLTPrint(SLTNode* phead)
{
    SLTNode *purc=phead;
    while (purc)
    {
        printf("%d->",purc->data);
        purc=purc->next;
    }
    printf("NULL");
}

SLTNode* SLTBuyData(SLTDataType x)
{
    SLTNode *newnode= (SLTNode *)malloc(sizeof (SLTNode));
    if(newnode==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}

void SLTPushBack(SLTNode** pphead,SLTDataType x)//尾插
{
    assert(pphead);
    SLTNode *newnode=SLTBuyData(x);
    if(*pphead==NULL)
    {
        *pphead=newnode;
    }
    else
    {
        SLTNode *purc=*pphead;
        while (purc->next)
        {
            purc=purc->next;
        }
        purc->next=newnode;
    }
}

void SLTPushFront(SLTNode** pphead,SLTDataType x)//头插
{
    assert(pphead);
    SLTNode *newnode=SLTBuyData(x);
    newnode->next=*pphead;
    *pphead=newnode;
}

void SLTPopBack(SLTNode** pphead)//尾删
{
    assert(pphead && *pphead);
    //链表只有一个结点
    if((*pphead)->next==NULL)
    {
        free(*pphead);
        *pphead=NULL;
    }
    //链表有多个结点
    else
    {
        SLTNode *last=*pphead;
        SLTNode *second=*pphead;
        while (last->next)
        {
            second=last;
            last=last->next;
            // second last
        }
        free(last);
        last=NULL;
        second->next=NULL;
    }
}

void SLTPopFront(SLTNode** pphead)//头删
{
    assert(*pphead && pphead);
    SLTNode *next=(*pphead)->next;
    free(*pphead);
    *pphead=next;
}

SLTNode *SLTFind(SLTNode* phead,SLTDataType x)//查找
{
    SLTNode *purc=phead;
    while (purc)
    {
        if(purc->data==x)
            return purc;
        purc=purc->next;
    }
    return NULL;
}

void SLTInsert(SLTNode **pphead,SLTNode* pos,SLTDataType x)//在指定位置之前插入数据
{
    assert(pphead && *pphead);
    assert(pos);
    SLTNode *newcode= SLTBuyData(x);
    if(*pphead==pos)
    {
        SLTPushFront(pphead,x);//如果指定位置恰好为首元素，头插
    }
    else//指定位置不为首元素
    {
        SLTNode *purc=*pphead;
        while(purc->next!=pos)
        {
            purc=purc->next;
        }
        //purc newcode pos
        newcode->next=pos;
        purc->next=newcode;
    }
}

void SLTInsertAfter(SLTNode* pos,SLTDataType x)//在指定位置之后插入数据
{
    assert(pos);
    SLTNode *newcode= SLTBuyData(x);
    newcode->next=pos->next;
    pos->next=newcode;
}

void SLTErase(SLTNode** pphead,SLTNode* pos)//删除pos结点
{
    assert(*pphead && pphead);
    assert(pos);
    //pos是头结点
    if(*pphead==pos)
    {
        SLTPopFront(pphead);//头删
    }
    //pos不是头结点
    else
    {
        SLTNode* purc=*pphead;
        while(purc->next!=pos)
        {
            purc=purc->next;
        }
        //purc pos
        purc->next=pos->next;
        free(pos);
        pos=NULL;
    }
}

void SLTEraseAfter(SLTNode* pos)//删除pos之后的结点
{
    assert(pos && pos->next);
    SLTNode *del=pos->next;
    //pos del del->next
    pos->next=del->next;
    free(del);
    del=NULL;
}

void SListDesTroy(SLTNode** pphead)//销毁链表
{
    assert(pphead && *pphead);
    SLTNode *purc=*pphead;
    while (purc)
    {
        SLTNode *next=purc->next;
        free(purc);
        purc=next;
    }
    *pphead=NULL;
}
