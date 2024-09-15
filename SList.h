//
// Created by cp on 2024/9/15.
//

#ifndef SLIST_SLIST_H
#define SLIST_SLIST_H

#endif //SLIST_SLIST_H

#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
    SLTDataType data;
    struct SListNode* next;
}SLTNode;

void SLTPrint(SLTNode* phead);//打印链表

void SLTPushBack(SLTNode** pphead,SLTDataType x);//尾插
void SLTPushFront(SLTNode** pphead,SLTDataType x);//头插
void SLTPopBack(SLTNode** pphead);//尾删
void SLTPopFront(SLTNode** pphead);//头删

SLTNode *SLTFind(SLTNode* phead,SLTDataType x);//查找
void SLTInsert(SLTNode **pphead,SLTNode* pos,SLTDataType x);//在指定位置之前插入数据
void SLTInsertAfter(SLTNode* pos,SLTDataType x);//在指定位置之后插入数据

void SLTErase(SLTNode** pphead,SLTNode* pos);//删除pos结点
void SLTEraseAfter(SLTNode* pos);//删除pos之后的结点

void SListDesTroy(SLTNode** pphead);//销毁链表
