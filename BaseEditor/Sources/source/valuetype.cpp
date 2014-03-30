#include "include/valuetype.h"

ValueType::ValueType(Type t)
    : mType(t)
{
}
ValueType::ValueType(const ValueType &other)
    : mType(other.mType)
{}



const std::string ValueType::STRING_STR = "string";
const std::string ValueType::FLOAT_STR = "float";
const std::string ValueType::LIST_STR = "list";
const std::string ValueType::BOOL_STR = "bool";
const std::string ValueType::INT_STR = "int";

std::string              ValueType::toString(ValueType::Type type)
{
    switch (type)
    {
    case ValueType::FLOAT:
        return (ValueType::FLOAT_STR);
    case ValueType::LIST:
        return (ValueType::LIST_STR);
    case ValueType::BOOL:
        return (ValueType::BOOL_STR);
    case ValueType::INT:
        return (ValueType::INT_STR);
    case ValueType::STRING:
    default:
        return (ValueType::STRING_STR);
    }
}

ValueType::Type    ValueType::toType(const std::string &name)
{
    if (name == ValueType::FLOAT_STR)
        return (ValueType::FLOAT);
    else if (name == ValueType::LIST_STR)
        return (ValueType::LIST);
    else if (name == ValueType::BOOL_STR)
        return (ValueType::BOOL);
    else if (name == ValueType::INT_STR)
        return (ValueType::INT);
    else /* ValueType::STRING is the default one */
        return (ValueType::STRING);
}
