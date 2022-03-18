#include <dbinterface.h>

using namespace dbf;

DataSetHandle::DataSetHandle(const std::string& dataSetName, dbf::DBInterface* dbptr):
    _dbptr(dbptr), _dataSetName(dataSetName)
{ }

size_t DataSetHandle::create(const dbf::Record& record) const
{
    return _dbptr->_insert(_dataSetName, record);
}
