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
    virtual int ListIsEmpty() { return L_ERR_SUPPORT; }
    virtual int ListLength() { return L_ERR_SUPPORT; }
    virtual int GetElem(const int position, LObject* obj)
    {
      return L_ERR_SUPPORT;
    }
    virtual int LocateElem(int& position, LObject* obj, CompareApi compareApi) {return L_ERR_SUPPORT;}
    virtual int PriorElem(LObject* curObj, LObject* preObj){return L_ERR_SUPPORT;}
    virtual int NextElem(LObject* curObj, LObject* nextObj){return L_ERR_SUPPORT;}
private:
    LSignleLinkedListItemData* m_data;
    long m_capacity;//总数
};

#endif // LSINGLELINKEDLIST_H
