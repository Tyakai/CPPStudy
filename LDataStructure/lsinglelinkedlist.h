#ifndef LSINGLELINKEDLIST_H
#define LSINGLELINKEDLIST_H
#include "llist.h"


struct LSignleLinkedListItemData
{
    LSignleLinkedListItemData():pData(nullptr),pNext(nullptr)
    {
    }
    LObject* pData;
    LSignleLinkedListItemData* pNext;
};

class LSingleLinkedList : public LList
{
public:
    LSingleLinkedList();
    virtual int InitList();
    virtual int DestoryList();
    virtual int ClearList(){return L_ERR_SUPPORT;}
    virtual int ListInsert( LObject* const data, const bool bToEnd = true);

    virtual int ListInsert( LObject* const data,const int position);
    virtual int ListDelete(const int position);
    virtual L_BOOL ListIsEmpty();
    virtual int ListLength();
    virtual int GetElem(const int position, LObject* obj);
    virtual int LocateElem(int& position, LObject* obj, CompareApi compareApi);
    virtual int PriorElem(const LObject* pCurObj, LObject* &pPreObj);
    virtual int NextElem(const LObject* pCurObj, LObject* &pNextObj);
private:
    LSignleLinkedListItemData* m_data;
    long m_capacity;//总数
};

#endif // LSINGLELINKEDLIST_H
