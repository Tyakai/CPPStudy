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
  virtual int InsertData(LObject* const data, const bool bToEnd = true);
  virtual int InsertData(LObject* const data,const int position);
  virtual int DeleteData(const int position);
  virtual int ClearList();
  virtual int ListIsEmpty();
  virtual int ListLength();
  virtual int GetElem(const int position, LObject* obj);
  virtual int LocateElem(int& position, LObject* obj, CompareApi compareApi);
  virtual int PriorElem(LObject* curObj, LObject* preObj);
  virtual int NextElem(LObject* curObj, LObject* nextObj);


private:
  int    AdjustListSize();
private:
  LLinearListItemData m_data;
};

#endif // LLINEARLIST_H