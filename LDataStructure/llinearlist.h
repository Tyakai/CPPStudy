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
  LObject** pData;
  long lCapacity;
  long lUsedNum;
};

class LDynamicLinearList : public LList
{
public:
  LDynamicLinearList();
  virtual ~LDynamicLinearList();
  virtual int InitList() ;
  virtual int DestoryList();
  virtual int ClearList();
  virtual L_BOOL ListIsEmpty();
  virtual int ListLength();
  virtual int ListInsert(LObject* const data, const bool bToEnd = true);
  virtual int ListInsert(LObject* const data,const int position);
  virtual int ListDelete(const int position);
  virtual int GetElem(const int position, LObject* obj);
  virtual int LocateElem(int& position, LObject* obj, CompareApi compareApi);//返回线性表中第一个与e满足compare()关系的元素的位序
  virtual int PriorElem(LObject* curObj, LObject* preObj);
  virtual int NextElem(LObject* curObj, LObject* nextObj);


private:
  int    AdjustListSize();
private:
  LLinearListItemData m_data;
};

#endif // LLINEARLIST_H
