#ifndef PROJECTITEMTYPE_H
# define PROJECTITEMTYPE_H

# include <QString>
# include <list>
# include <map>
# include "valuetype.h"
# include "enablers.hpp"

/**
 * @brief The IProjectItemType class
 */
class IProjectItemConfig
        : public enable::tag<IProjectItemConfig, QString>
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
    static const QString ROOT_STR;
    static const QString MATERIAL_STR;
    static const QString MESH_STR;
    static const QString PARTICLE_STR;
    static const QString LIGHT_STR;
    static const QString BILLBOARD_STR;
    static const QString STATIC_GEOMETRY_STR;
    static const QString NODE_STR;

    typedef std::map<std::string, ValueType> PropMap;

    static const Type DEFAULT_TYPE = NODE;

    IProjectItemConfig(const IProjectItemConfig &other);
    IProjectItemConfig(const QString &name = QString(), Type t = DEFAULT_TYPE);
    virtual ~IProjectItemConfig(){}

    Type        type() const{ return (mType); }
    QString     str() const{ return (toString(mType)); }
    Type        default_type() const{ return (DEFAULT_TYPE); }

    IProjectItemConfig     &operator=(Type t){ mType = t; return (*this); }
    IProjectItemConfig     &operator=(const IProjectItemConfig &rk){ mType = rk.mType; return (*this); }

    const QString           &getName() const;
    void                    setName(const QString &name);

    static QString          toString(Type t);
    static Type             toType(const QString &t);
protected:
    Type    mType;
    PropMap mProps;
};
typedef std::list<IProjectItemConfig *> ProjectItemConfigList;

namespace ProjectItemConfig
{
    class Root : public IProjectItemConfig
    {
    public:
        Root(const QString &name = QString()) : IProjectItemConfig(name, ROOT){}
        ~Root(){}
    };
    class Material : public IProjectItemConfig
    {
    public:
        Material(const QString &name = QString()) : IProjectItemConfig(name, MATERIAL){}
        ~Material(){}
    };
    class Mesh : public IProjectItemConfig
    {
    public:
        Mesh(const QString &name = QString()) : IProjectItemConfig(name, MESH){}
        ~Mesh(){}
    };
    class Particle : public IProjectItemConfig
    {
    public:
        Particle(const QString &name = QString()) : IProjectItemConfig(name, PARTICLE){}
        ~Particle(){}
    };
    class Light : public IProjectItemConfig
    {
    public:
        Light(const QString &name = QString()) : IProjectItemConfig(name, LIGHT){}
        ~Light(){}
    };
    class Billboard : public IProjectItemConfig
    {
    public:
        Billboard(const QString &name = QString()) : IProjectItemConfig(name, BILLBOARD){}
        ~Billboard(){}
    };
    class StaticGeometry : public IProjectItemConfig
    {
    public:
        StaticGeometry(const QString &name = QString()) : IProjectItemConfig(name, STATIC_GEOMETRY){}
        ~StaticGeometry(){}
    };
    class Node : public IProjectItemConfig
    {
    public:
        Node(const QString &name = QString()) : IProjectItemConfig(name, NODE){}
        ~Node(){}
    };
}

#endif // PROJECTITEMTYPE_H
