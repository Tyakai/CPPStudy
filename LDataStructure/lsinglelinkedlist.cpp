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
    return L_OK;
}

int LSingleLinkedList::ListInsert(LObject * const data, const int position)
{

}
