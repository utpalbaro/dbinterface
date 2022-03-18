#if !defined(DBCONNECTION_H)
#define DBCONNECTION_H

#include <memory>
#include "dbinterface.h"

namespace dbf
{

class DBConnection
{
private:
    std::unique_ptr<dbf::DBInterface> _db;

public:
    DBConnection(std::unique_ptr<dbf::DBInterface> db);
    DataSetHandle createDataSet(const std::string& name, const Schema& schema) const;
};

}

#endif

