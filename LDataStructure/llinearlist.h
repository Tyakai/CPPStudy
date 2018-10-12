#ifndef LLINEARLIST_H
#define LLINEARLIST_H
#include "llist.h"
#include "lobject.h"

struct LLinearListItemData
{
    LLinearListItemData():
        pData(nullptr),
        pFirst(nullptr)
    {}
    LObject** pData;
    LLinearListItemData* pFirst;

};

class LLinearList :public LList
{
public:
    LLinearList();
    virtual ~LLinearList();
private:
    LLinearListItemData m_data;
};

#endif // LLINEARLIST_H