#ifndef PROJECTITEMTYPE_H
# define PROJECTITEMTYPE_H

# include <QMap>
# include "valuetype.h"
# include "enablers.hpp"

/**
 * @brief The IProjectItemType class
 */
class IProjectItemConfig
        : public enable::tag<IProjectItemConfig, std::string>
{
public:
    enum Type
    {
        ROOT,
        MATERIAL,
        MESH,
        PARTICLE,
        LIGHT,
        BILLBOARD,
        STATIC_GEOMETRY,
        NODE
    };
    static const std::string ROOT_STR;
    static const std::string MATERIAL_STR;
    static const std::string MESH_STR;
    static const std::string PARTICLE_STR;
    static const std::string LIGHT_STR;
    static const std::string BILLBOARD_STR;
    static const std::string STATIC_GEOMETRY_STR;
    static const std::string NODE_STR;

    typedef std::map<std::string, ValueType> PropMap;

    static const Type DEFAULT_TYPE = NODE;

    IProjectItemConfig(const IProjectItemConfig &other);
    IProjectItemConfig(const std::string &name = std::string(), Type t = DEFAULT_TYPE);
    virtual ~IProjectItemConfig(){}

    Type        type() const{ return (mType); }
    std::string str() const{ return (toString(mType)); }
    Type        default_type() const{ return (DEFAULT_TYPE); }

    IProjectItemConfig     &operator=(Type t){ mType = t; return (*this); }
    IProjectItemConfig     &operator=(const IProjectItemConfig &rk){ mType = rk.mType; return (*this); }

    const std::string       &getName() const;
    void                    setName(const std::string &name);

    static std::string  toString(Type t);
    static Type         toType(const std::string &t);
protected:
    Type    mType;
    PropMap mProps;
    std::string mName;
};

namespace ProjectItemConfig
{
    class Root : public IProjectItemConfig
    {
    public:
        Root(const std::string &name = std::string()) : IProjectItemConfig(name, ROOT){}
        ~Root(){}
    };
    class Material : public IProjectItemConfig
    {
    public:
        Material() : IProjectItemConfig(MATERIAL){}
        ~Material(){}
    };
    class Mesh : public IProjectItemConfig
    {
    public:
        Mesh() : IProjectItemConfig(MESH){}
        ~Mesh(){}
    };
    class Particle : public IProjectItemConfig
    {
    public:
        Particle() : IProjectItemConfig(PARTICLE){}
        ~Particle(){}
    };
    class Light : public IProjectItemConfig
    {
    public:
        Light() : IProjectItemConfig(LIGHT){}
        ~Light(){}
    };
    class Billboard : public IProjectItemConfig
    {
    public:
        Billboard() : IProjectItemConfig(BILLBOARD){}
        ~Billboard(){}
    };
    class StaticGeometry : public IProjectItemConfig
    {
    public:
        StaticGeometry() : IProjectItemConfig(STATIC_GEOMETRY){}
        ~StaticGeometry(){}
    };
    class Node : public IProjectItemConfig
    {
    public:
        Node() : IProjectItemConfig(NODE){}
        ~Node(){}
    };
}

#endif // PROJECTITEMTYPE_H
