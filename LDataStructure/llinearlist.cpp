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
  m_data.pData = new LObject[m_data.lCapacity];
  m_data.lUsedNum = 0;
  return L_OK;
}

int LDynamicLinearList::DestoryList() {
  for (int i = 0; i < m_data.lUsedNum; ++i) {
    L_Del(m_data.pData[i]);
  }
  return L_OK;
}

int LDynamicLinearList::InsertData(const LObject* data,
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

int LDynamicLinearList::InsertData(const LList::LObject *datda, const int position)
{
    if(position<0 || position>m_data.lUsedNum)
    {
        return L_ERR_PARAM;
    }
    AdjustListSize();
    for(int i = m_data.lUsedNum; i > position ; --io)

}

int LDynamicLinearList::DeleteData(const int position) {

    return L_OK;
}

int LDynamicLinearList::AdjustListSize()
{
    while (m_data.lUsedNum >= m_data.lCapacity)
    {
      int iNewCap = m_data.lCapacity + (m_data.lCapacity >> 1);
      m_data.lCapacity = iNewCap;
    }
    LObject* pNew = new LObject[m_data.lCapacity];
    memcpy(pNew, m_data.pData, m_data.lUsedNum * sizeof(LObject*));
    delete[] m_data.pData;
    m_data.pData = pNew;
    return L_OK;
}
