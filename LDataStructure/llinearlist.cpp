#include "llinearlist.h"

LDynamicLinearList::LDynamicLinearList() {
  m_data.lCapacity = L_DLINERLIST_DEFAULT_SIZE;
  m_data.lUsedNum = 0;
}

LDynamicLinearList::~LDynamicLinearList() { DestoryList(); }

int LDynamicLinearList::InitList() {
  if (m_data.pData) {
    delete[] m_data.pData;
  }
  m_data.pData = new PLObject[m_data.lCapacity];
  m_data.lUsedNum = 0;
  return L_OK;
}

int LDynamicLinearList::DestoryList() {
  for (int i = 0; i < m_data.lUsedNum; ++i) {
    L_Del(m_data.pData[i]);
  }
  return L_OK;
}

int LDynamicLinearList::InsertData(LObject* const data,
                                   const bool bToEnd /*= true*/) {
  if (!bToEnd)
  {
      return L_ERR_PARAM;
  }
  AdjustListSize();
  m_data.pData[m_data.lUsedNum] = data;
  ++m_data.lUsedNum;

  return L_OK;
}

int LDynamicLinearList::InsertData(LObject * const data, const int position)
{
    if(position<0 || position>m_data.lUsedNum)
    {
        return L_ERR_PARAM;
    }
    AdjustListSize();
    for(int i = m_data.lUsedNum; i > position ; --i)
    {
        m_data.pData[i] = m_data.pData[i-1];
    }
    m_data.pData[position] = data;
    ++m_data.lUsedNum;

    return L_OK;

}

int LDynamicLinearList::DeleteData(const int position) {

    return L_OK;
}

int LDynamicLinearList::ClearList()
{
    for(int i=0; i<m_data.lUsedNum;++i)
    {
        L_Del(m_data.pData[i]);
    }
    return L_OK;
}

int LDynamicLinearList::ListIsEmpty()
{
    if(m_data.lUsedNum == 0)
    {
        return L_TRUE;
    }
    else
    {
        return L_FALSE;
    }
    return L_FALSE;
}

int LDynamicLinearList::ListLength()
{
    return m_data.lUsedNum;
}

int LDynamicLinearList::GetElem(const int position, LObject *obj)
{
    if(position<0 || position>=m_data.lUsedNum)
    {
        return L_ERR_PARAM;
    }
    obj = m_data.pData[position];
    return L_OK;
}

int LDynamicLinearList::LocateElem(int &position, LObject *obj, CompareApi compareApi)
{
    return L_OK;
}

int LDynamicLinearList::PriorElem(LObject *curObj, LObject *preObj)
{
    return L_OK;
}

int LDynamicLinearList::NextElem(LObject *curObj, LObject *nextObj)
{
    return L_OK;
}

int LDynamicLinearList::AdjustListSize()
{
    while (m_data.lUsedNum >= m_data.lCapacity)
    {
      int iNewCap = m_data.lCapacity + (m_data.lCapacity >> 1);
      m_data.lCapacity = iNewCap;
    }
    LObject** pNew = new LObject*[m_data.lCapacity];
    memcpy(pNew, m_data.pData, m_data.lUsedNum * sizeof(LObject*));
    delete[] m_data.pData;
    m_data.pData = pNew;
    return L_OK;
}
