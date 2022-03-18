#if !defined(HW_DT_DEFS_H)
#define HW_DT_DEFS_H

#include <climits>

namespace dbf
{
    
enum class FieldType
{
    INT,
    CHAR,
    UCHAR,
    UINT,
    FLOAT,
    DOUBLE
};

class FieldTypeInfo
{
public:
    static size_t getSize(FieldType fieldtype)
    {
        switch (fieldtype)
        {
        case FieldType::INT:
            return sizeof(int);
        case FieldType::CHAR:
            return sizeof(char);
        case FieldType::UCHAR:
            return sizeof(char);
        case FieldType::UINT:
            return sizeof(unsigned int);
        case FieldType::FLOAT:
            return sizeof(float);
        case FieldType::DOUBLE:
            return sizeof(double);
        }

        return UINT_MAX;
    }
};

} // namespace dbf


#endif