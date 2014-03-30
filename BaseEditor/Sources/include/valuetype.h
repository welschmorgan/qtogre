#ifndef VALUETYPE_H
# define VALUETYPE_H

# include <string>

class ValueType
{
public:
    enum Type
    {
        STRING,
        ROOT,
        FLOAT,
        LIST,
        BOOL,
        INT
    };
    static const std::string STRING_STR;
    static const std::string FLOAT_STR;
    static const std::string LIST_STR;
    static const std::string BOOL_STR;
    static const std::string INT_STR;

    static const Type DEFAULT_TYPE = STRING;

    ValueType(const ValueType &other);
    ValueType(Type t = DEFAULT_TYPE);

    Type        type() const{ return (mType); }
    std::string str() const{ return (toString(mType)); }

    ValueType     &operator=(Type t){ mType = t; return (*this); }
    ValueType     &operator=(const ValueType &rk){ mType = rk.mType; return (*this); }

    static std::string  toString(Type t);
    static Type         toType(const std::string &t);

protected:
    Type mType;
};

#endif // VALUETYPE_H
