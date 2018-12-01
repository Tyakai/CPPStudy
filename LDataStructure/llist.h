#ifndef LLIST_H
#define LLIST_H
#include "ldatastructure.h"
#include "datadef.h"
#include "macrodef.h"
#include "lobject.h"


class LList : public LDataStructure
{
public:
    LList();
    virtual ~LList();
    virtual int InitList(){ return L_ERR_SUPPORT;}
    virtual int DestoryList(){ return L_ERR_SUPPORT;}
    virtual int InsertData(const LObject* data,const bool bToEnd = true){return L_ERR_SUPPORT;}
    virtual int DeleteData(const int position){return L_ERR_SUPPORT;}
    virtual int ClearList(){return L_ERR_SUPPORT;}
    virtual int ListIsEmpty(){return L_ERR_SUPPORT;}
    virtual int ListLength(){return L_ERR_SUPPORT;}
    virtual int GetElem(const int position,LObject* obj){return L_ERR_SUPPORT;}
    virtual int LocateElem(int &position,LObject* obj,)
};

#endif // LLIST_H