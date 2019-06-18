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
{/*
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
            LSignleLinkedListItemData* pToDel = pCurNode;
            pCurNode->pNext
        }
    }*/
}
