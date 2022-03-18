#if !defined(DBINTERFACE_H)
#define DBINTERFACE_H

#include <string>
#include "schema.h"

namespace dbf
{

class DataSetHandle;

/**
 * @brief An interface to a DB with support for CRUD operations
 * 
 */
class DBInterface
{
private:

    /**
     * @brief Creates a record and returns the index at which it is created
     * 
     * @param datasetName 
     * @param record 
     * @return size_t index in the table
     */
    virtual size_t _insert(const std::string& datasetName, const Record& record) { return -1; }

    /**
     * @brief Reads a record at an index
     * 
     * @param datasetName 
     * @param index 
     * @param record 
     * @return bool true or false depending on success
     */
    virtual bool _read(const std::string& datasetName, size_t index, Record& record) const { return false; }

    /**
     * @brief Updates a record at certain index
     * 
     * @param datasetName 
     * @param index 
     * @param record 
     * @return bool true or false depending on success
     */
    virtual bool _update(const std::string& datasetName, size_t index, const Record& record) { return false; }

    /**
     * @brief Deletes a record at certain index
     * 
     * @param datasetName 
     * @param index 
     * @param record 
     * @return bool true or false depending on success
     */
    virtual bool _remove(const std::string& datasetName, size_t index, const Record& record) { return false; }

public:
    virtual ~DBInterface() { }
    virtual DataSetHandle createDataSet(const std::string& name, const Schema& schema) = 0;

    friend class DataSetHandle;
};

class DataSetHandle
{
private:
    dbf::DBInterface * const _dbptr;
    const std::string _dataSetName;

public:
    DataSetHandle(const std::string& dataSetName, dbf::DBInterface* dbptr);
    size_t create(const Record& record) const;
    bool read(size_t index, Record& record) const;
    bool update(size_t index, Record& record) const;
    bool remove(size_t index, Record& record) const;
};

} // namespace dbf




#endif
