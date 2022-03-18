#include <cstring>
#include <schema.h>
#include <fieldtypes.h>

using namespace dbf;

Record::Record(const Schema& schema) : schema(schema),
        _buffer(std::make_unique<uint8_t[]>(schema.size()))
{ }

uint8_t* Record::_getBufferAtField(size_t index, FieldType& datatype) const
{ 
    auto field = schema._fields.at(index);

    auto offset = std::get<1>(field);
    datatype = std::get<2>(field);

    return _buffer.get() + offset;
}

void Record::set(const std::string& fieldname, const void* data)
{
    auto index = schema._fieldsMap.at(fieldname);
    set(index, data);
}

void Record::set(size_t index, const void* data)
{
    FieldType datatype;
    uint8_t* buff = _getBufferAtField(index, datatype);

    memcpy(buff, data, FieldTypeInfo::getSize(datatype));
}

void Record::get(const std::string& fieldname, void* data) const
{
    auto index = schema._fieldsMap.at(fieldname);
    get(index, data);
}

void Record::get(size_t index, void* data) const
{
    FieldType datatype;
    const uint8_t* buff = _getBufferAtField(index, datatype);

    memcpy(data, buff, FieldTypeInfo::getSize(datatype));
}

const uint8_t* Record::getBuffer() const
{
    return _buffer.get();
}


void Schema::insertField(const std::string& field, const FieldType& datatype)
{
    _fields.emplace_back(field, _offset, datatype);
    _fieldsMap.emplace(field, _fields.size() - 1);

    _offset += FieldTypeInfo::getSize(datatype);
}

void Schema::insertField(const FieldType& datatype)
{
    std::string fieldname = std::to_string(_fields.size());
    insertField(fieldname, datatype);
}

const std::vector<std::tuple<std::string, size_t, FieldType>>& Schema::getFields() const
{
    return _fields;
}

size_t Schema::size() const
{
    return _offset;
}

