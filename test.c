//
// Created by cp on 2024/9/15.
//
#include "SList.h"
int main()
{
    SLTNode* plist=NULL;
    SLTPushBack(&plist,1);//尾插
    SLTPushBack(&plist,2);
    SLTPushBack(&plist,3);
    SLTPushBack(&plist,4);
    SLTPushFront(&plist,6);//头插
    SLTPopBack(&plist);//尾删
    SLTPopFront(&plist);//头删
    //1->2->3->NULL
    SLTNode *find=SLTFind(plist,1);
    //SLTInsert(&plist, find,6);
    //SLTInsertAfter(find,6);
    //SLTErase(&plist,find);
    SLTEraseAfter(find);
    SLTPrint(plist);
    SListDesTroy(&plist);
    return 0;
}