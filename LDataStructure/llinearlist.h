#ifndef LLINEARLIST_H
#define LLINEARLIST_H
#include "llist.h"

struct LLinearListItemData
{
  LLinearListItemData()
    : pData(nullptr)
    , lCapacity(0)
    , lUsedNum(0)
  {}
  LObject* pData;
  long lCapacity;
  long lUsedNum;
};

class LDynamicLinearList : public LList
{
public:
  LDynamicLinearList();
  virtual ~LDynamicLinearList();
  virtual int InitList();
  virtual int DestoryList();
  virtual int InsertData(const LObject* data, const bool bToEnd = true);
  virtual int InsertData(const LObject* datda,const int position);
  virtual int DeleteData(const int position);

private:
  int    AdjustListSize();
private:
  LLinearListItemData m_data;
};

#endif // LLINEARLIST_H