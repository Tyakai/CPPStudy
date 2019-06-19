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
  if(m_data.lCapacity <= 0)
  {
      m_data.lCapacity = L_DLINERLIST_DEFAULT_SIZE;
  }
  m_data.pData = new PLObject[m_data.lCapacity];
  m_data.lUsedNum = 0;
  return L_OK;
}

int LDynamicLinearList::DestoryList() {
  for (int i = 0; i < m_data.lUsedNum; ++i)
  {
    L_Del(m_data.pData[i]);
  }
  delete  [] m_data.pData;
  m_data.lUsedNum = 0;
  m_data.lCapacity = 0;
  return L_OK;
}

int LDynamicLinearList::ListInsert(LObject* const data,
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

int LDynamicLinearList::ListInsert(LObject * const data, const int position)
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

int LDynamicLinearList::ListDelete(const int position) {

    return L_OK;
}

int LDynamicLinearList::ClearList()
{
    for(int i=0; i<m_data.lUsedNum;++i)
    {
        L_Del(m_data.pData[i]);
    }
    m_data.lUsedNum = 0;
    return L_OK;
}

L_BOOL LDynamicLinearList::ListIsEmpty()
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
    for(int i=0;i<m_data.lUsedNum;++i)
    {
        if(compareApi(m_data.pData[i],obj))
        {
            position = i;
            return L_OK;
        }
    }
    return L_ERR_FOUND;
}

int LDynamicLinearList::PriorElem(LObject *curObj, LObject *preObj)
{
    for(int i=0;i<m_data.lUsedNum;++i)
    {
        if(m_data.pData[i] == curObj)
        {
            if(i==0)
            {
                return L_ERR_POSITION;
            }
            else
            {
                preObj = m_data.pData[i-1];
                return L_OK;
            }
        }
    }
    return L_ERR_FOUND;
}

int LDynamicLinearList::NextElem(LObject *curObj, LObject *nextObj)
{
    for(int i=0;i<m_data.lUsedNum;++i)
    {
        if(m_data.pData[i] == curObj)
        {
            if(i == m_data.lUsedNum-1)
            {
                return L_ERR_POSITION;
            }
            else
            {
                nextObj = m_data.pData[i+1];
                return L_OK;
            }
        }
    }
    return L_ERR_FOUND;
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
