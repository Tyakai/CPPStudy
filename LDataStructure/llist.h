#ifndef LLIST_H
#define LLIST_H
#include "datadef.h"
#include "includedef.h"
#include "ldatastructure.h"
#include "lobject.h"
#include "macrodef.h"

typedef int (*CompareApi)(LObject* objA,LObject* objB);

class LList : public LDataStructure
{
public:
  LList();
  virtual ~LList();
  virtual int InitList() = 0;
  virtual int DestoryList() { return L_ERR_SUPPORT; }
  virtual int InsertData( LObject* const data, const bool bToEnd = true)
  {
    return L_ERR_SUPPORT;
  }
  virtual int InsertData( LObject* const data,const int position){return  L_ERR_SUPPORT;}
  virtual int DeleteData(const int position) { return L_ERR_SUPPORT; }
  virtual int ClearList() { return L_ERR_SUPPORT; }
  virtual int ListIsEmpty() { return L_ERR_SUPPORT; }
  virtual int ListLength() { return L_ERR_SUPPORT; }
  virtual int GetElem(const int position, LObject* obj)
  {
    return L_ERR_SUPPORT;
  }
  virtual int LocateElem(int& position, LObject* obj, CompareApi compareApi) {return L_ERR_SUPPORT;}
  virtual int PriorElem(LObject* curObj, LObject* preObj){return L_ERR_SUPPORT;}
  virtual int NextElem(LObject* curObj, LObject* nextObj){return L_ERR_SUPPORT;}

};

#endif // LLIST_H