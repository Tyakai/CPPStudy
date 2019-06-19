#ifndef LLIST_H
#define LLIST_H
#include "datadef.h"
#include "includedef.h"
#include "ldatastructure.h"
#include "lobject.h"
#include "macrodef.h"
//objTar:传入参数
//objCon:符合的参数
typedef bool (*CompareApi)(LObject* objTar,LObject* objCon);

class LList : public LDataStructure
{
public:
  LList();
  virtual ~LList();
  virtual int InitList() = 0;
  virtual int DestoryList() { return L_ERR_SUPPORT; }
  virtual int ClearList(){return L_ERR_SUPPORT;}
  virtual int ListInsert( LObject* const data, const bool bToEnd = true)
  {
    return L_ERR_SUPPORT;
  }
  virtual int ListInsert( LObject* const data,const int position){return  L_ERR_SUPPORT;}
  virtual int ListDelete(const int position) { return L_ERR_SUPPORT; }
  virtual L_BOOL ListIsEmpty() { return L_ERR_SUPPORT; }
  virtual int ListLength() { return L_ERR_SUPPORT; }
  virtual int GetElem(const int position, LObject* obj)
  {
    return L_ERR_SUPPORT;
  }
  virtual int LocateElem(int& position, LObject* obj, CompareApi compareApi) {return L_ERR_SUPPORT;}
  virtual int PriorElem(const LObject* pCurObj, LObject* &pPreObj){return L_ERR_SUPPORT;}
  virtual int NextElem(const LObject* pCurObj, LObject* &pNextObj){return L_ERR_SUPPORT;}

};

#endif // LLIST_H
