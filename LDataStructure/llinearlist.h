#ifndef LLINEARLIST_H
#define LLINEARLIST_H
#include "llist.h"

struct LLinearListItemData
{
    LLinearListItemData():
        pData(nullptr),
        lCapacity(0),
        lUsedNum(0)
    {}
    LObject* pData;
    long lCapacity;
    long lUsedNum;
};

class LStaticLinearList :public LList
{
public:
    LStaticLinearList();
    virtual ~LStaticLinearList();
    virtual int InitList();
    virtual int DestoryList();
    virtual int InsertData(const LObject* data,const bool bToEnd = true);
    virtual int DeleteData(const int position);
private:
    LLinearListItemData m_data;
};

#endif // LLINEARLIST_H