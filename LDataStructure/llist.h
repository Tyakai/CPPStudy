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
};

#endif // LLIST_H