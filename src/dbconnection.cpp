#include <dbconnection.h>

using namespace dbf;

DBConnection::DBConnection(std::unique_ptr<dbf::DBInterface> db)
{
    _db = std::move(db);
}

DataSetHandle DBConnection::createDataSet(const std::string& name, const Schema& schema) const
{
    return _db->createDataSet(name, schema);
}
