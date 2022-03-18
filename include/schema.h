#if !defined(SCHEMA_H)
#define SCHEMA_H

#include <vector>
#include <string>
#include <unordered_map>
#include <memory>

#include "fieldtypes.h"

namespace dbf
{

class Schema;

class Record
{
public:
    Record(const Schema& schema);

    /**
     * @brief Set the value of a field at a given fieldname
     * 
     * @param fieldname name of the field in schema
     * @param data pointer to the data
     */
    void set(const std::string& fieldname, const void* data);
    
    /**
     * @brief Set a value of a field at a given index 
     * 
     * @param index index in the schema
     * @param data pointer to the data
     */
    void set(size_t index, const void* data);

    /**
     * @brief Get the value of a field with given fieldname
     * 
     * @param fieldname 
     * @param data 
     */
    void get(const std::string& fieldname, void* data) const;

    /**
     * @brief Get the value of a field with given index
     * 
     * @param index 
     * @param data 
     */
    void get(size_t index, void* data) const;
    
    /**
     * @brief Get the raw byte buffer of the data
     * 
     * @return const uint8_t* 
     */
    const uint8_t* getBuffer() const;

private:
    uint8_t* _getBufferAtField(size_t index, FieldType& datatype) const;

public:
    const Schema& schema;   //< A const reference to the underlying schema

private:
    std::unique_ptr<uint8_t[]> _buffer;
};


class Schema
{
public:
    Schema() : _offset(0) { }
    /**
     * @brief Insert a field into the schema
     * 
     * @param field Field name
     * @param datatype Type of field
     */
    void insertField(const std::string& field, const FieldType& datatype);

    /**
     * @brief Insert a field into the schema
     * 
     * @param datatype Type of field
     */
    void insertField(const FieldType& fieldtype);

    /**
     * @brief Returns the fields as a vector of tuples. Members of the tuple being
     * fieldname, offset in bytes, FieldType
     * 
     * @return const decltype(_fields)& 
     */
    const std::vector<std::tuple<std::string, size_t, FieldType>>& getFields() const;
    
    /**
     * @brief Returns the sum of sizes of all fields in schema in bytes
     * 
     * @return size_t 
     */
    size_t size() const;

    friend class Record;

private:

    std::vector<std::tuple<std::string, size_t, FieldType>> _fields;
    std::unordered_map<std::string, size_t> _fieldsMap;
    size_t _offset;
};

} // namespace dbf


#endif

