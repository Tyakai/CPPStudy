#include "llinearlist.h"


LStaticLinearList::LStaticLinearList()
{
    m_data.lCapacity = L_DLINERLIST_DEFAULT_SIZE;
    m_data.lUsedNum = 0;
}

LStaticLinearList::~LStaticLinearList()
{
    DestoryList();
}

int LStaticLinearList::InitList()
{
    if(m_data.pData)
    {
        delete [] m_data.pData;
    }
    m_data.pData = new LObject[m_data.lCapacity];
    m_data.lUsedNum = 0;
    return L_OK;
}

int LStaticLinearList::DestoryList()
{
    for(int i=0;i<m_data.lUsedNum;++i)
    {
        L_Del(m_data.pData[i]);
    }
    return L_OK;
}

int LStaticLinearList::InsertData(const LObject *data, const bool bToEnd)
{
    if(m_data.lCapacity == m_data.lUsedNum)
    {
        int iOldCap = m_data.lCapacity;
        int iNewCap = iOldCap + (iOldCap >> 1);
        if()
    }
}

int LStaticLinearList::DeleteData(const int position)
{

}


