#include "lsinglelinkedlist.h"

LSingleLinkedList::LSingleLinkedList():m_data(nullptr),m_capacity(0)
{

}

int LSingleLinkedList::InitList()
{
    return L_OK;
}

int LSingleLinkedList::DestoryList()
{
    if(!m_data)
    {
        return L_ERR_EMPTY;
    }

    do
    {
        L_Del(m_data->pData);
        m_data = m_data->pNext;
    }while(m_data->pNext);
    m_capacity = 0;
    return L_OK;
}

int LSingleLinkedList::ListInsert(LObject * const data, const bool bToEnd)
{
    LSignleLinkedListItemData* pListData = new LSignleLinkedListItemData;
    pListData->pData = data;
    if(bToEnd)//插在队尾
    {
        if(m_data)
        {
            LSignleLinkedListItemData* pTemp = m_data;
            while (pTemp->pNext) {
                pTemp = pTemp->pNext;
            }
            pTemp->pNext = pListData;
        }
        else {
            m_data = pListData;
        }

    }
    else
    {
        pListData->pNext = m_data;
        m_data = pListData;
    }
    ++m_capacity;
    return L_OK;
}

int LSingleLinkedList::ListInsert(LObject * const data, const int position)
{
    if(position<0 || position>m_capacity)
    {
        return L_ERR_POSITION;
    }
    LSignleLinkedListItemData* pCurNode = nullptr;
    pCurNode = m_data;
    int i=0;
    while (pCurNode)
    {
        if(position == i)
        {
            LSignleLinkedListItemData* pNode = new LSignleLinkedListItemData;
            pNode->pData = pCurNode->pData;
            pNode->pNext=pCurNode->pNext;
            pCurNode->pData = data;
            pCurNode->pNext = pNode;
            ++m_capacity;
            break;
        }
        pCurNode = pCurNode->pNext;
        ++i;
    }
    return L_OK;
}

int LSingleLinkedList::ListDelete(const int position)
{
    if(position<0 || position>m_capacity)
    {
        return L_ERR_POSITION;
    }
    LSignleLinkedListItemData* pCurNode = nullptr;
    pCurNode = m_data;
    int i=0;
    while (pCurNode)
    {
        if(position == i)
        {
            LObject* pToDelData = pCurNode->pData;
            if(pCurNode->pNext)
            {
                LSignleLinkedListItemData* pToDelItem = pCurNode->pNext;
                pCurNode->pData = pCurNode->pData;
                pCurNode->pNext = pCurNode->pNext;
                delete  pToDelItem;
            }
            delete pToDelData;
            --m_capacity;
        }
    }
    return L_OK;
}

L_BOOL LSingleLinkedList::ListIsEmpty()
{
    if(m_data)
    {
        return L_TRUE;
    }
    else {
        return L_FALSE;
    }
}

int LSingleLinkedList::ListLength()
{
    return m_capacity;
}

int LSingleLinkedList::GetElem(const int position, LObject *obj)
{
    if(position<0 || position>m_capacity)
    {
        return L_ERR_POSITION;
    }
    int i=0;
    LSignleLinkedListItemData* pCurNode = m_data;
    while (pCurNode)
    {
        if(position == i)
        {
            obj = pCurNode->pData;
            break;
        }
        pCurNode = pCurNode->pNext;
        ++i;
    }
    return L_OK;
}

int LSingleLinkedList::LocateElem(int &position, LObject *obj, CompareApi compareApi)
{
    int i = 0;
    LSignleLinkedListItemData* pCurNode = m_data;
    while (pCurNode)
    {
        if(compareApi(pCurNode->pData,obj))
        {
            position = i;
            return L_OK;
        }
        ++i;
        pCurNode = pCurNode->pNext;
    }
    return L_ERR_FOUND;
}

int LSingleLinkedList::PriorElem(const LObject *pCurObj, LObject *&pPreObj)
{
    LSignleLinkedListItemData* pPreNode = nullptr;
    LSignleLinkedListItemData* pCurNode = m_data;
    pPreObj = nullptr;
    while (pCurNode)
    {
        if(pCurNode->pData == pCurObj )
        {
            if(pPreNode)
            {
                pPreObj = pPreNode->pData;
            }
            return L_OK;
        }
        pPreNode = pCurNode;
        pCurNode = pCurNode->pNext;
    }
    return L_ERR_FOUND;
}

int LSingleLinkedList::NextElem(const LObject *pCurObj, LObject *&pNextObj)
{
     LSignleLinkedListItemData* pCurNode = m_data;
     pNextObj = nullptr;
     while (pCurNode->pNext)
     {
         if(pCurNode->pData == pCurObj)
         {
             if(pCurNode->pNext)
             {
                 pNextObj = pCurNode->pNext->pData;
             }
             return L_OK;
         }
         pCurNode = pCurNode->pNext;
     }
     return L_ERR_FOUND;
}

