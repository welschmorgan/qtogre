#include "include/project/projectitemconfig.h"
#include <QObject>

IProjectItemConfig::IProjectItemConfig(const QString &name, Type t)
    : tag<IProjectItemConfig, QString>(name)
    , mType(t)
{
}
IProjectItemConfig::IProjectItemConfig(const IProjectItemConfig &other)
    : tag<IProjectItemConfig, QString>(other)
    , mType(other.mType)
{}

const QString IProjectItemConfig::ROOT_STR = QObject::tr("Root");
const QString IProjectItemConfig::MATERIAL_STR = QObject::tr("Material");
const QString IProjectItemConfig::MESH_STR = QObject::tr("Mesh");
const QString IProjectItemConfig::PARTICLE_STR = QObject::tr("Particle");
const QString IProjectItemConfig::LIGHT_STR = QObject::tr("Light");
const QString IProjectItemConfig::BILLBOARD_STR = QObject::tr("Billboard");
const QString IProjectItemConfig::STATIC_GEOMETRY_STR = QObject::tr("Static Geometry");
const QString IProjectItemConfig::NODE_STR = QObject::tr("Node");

QString IProjectItemConfig::toString(IProjectItemConfig::Type type)
{
    switch (type)
    {
    case ROOT:
        return (ROOT_STR);
    case MATERIAL:
        return (MATERIAL_STR);
    case MESH:
        return (MESH_STR);
    case PARTICLE:
        return (PARTICLE_STR);
    case LIGHT:
        return (LIGHT_STR);
    case BILLBOARD:
        return (BILLBOARD_STR);
    case STATIC_GEOMETRY:
        return (STATIC_GEOMETRY_STR);
    case NODE:
    default:
        return (NODE_STR);
    }
}

IProjectItemConfig::Type    IProjectItemConfig::toType(const QString &name)
{
    if (name == IProjectItemConfig::ROOT_STR)
        return (IProjectItemConfig::ROOT);
    else if (name == IProjectItemConfig::MATERIAL_STR)
        return (IProjectItemConfig::MATERIAL);
    else if (name == IProjectItemConfig::MESH_STR)
        return (IProjectItemConfig::MESH);
    else if (name == IProjectItemConfig::PARTICLE_STR)
        return (IProjectItemConfig::PARTICLE);
    else if (name == IProjectItemConfig::LIGHT_STR)
        return (IProjectItemConfig::LIGHT);
    else if (name == IProjectItemConfig::BILLBOARD_STR)
        return (IProjectItemConfig::BILLBOARD);
    else if (name == IProjectItemConfig::STATIC_GEOMETRY_STR)
        return (IProjectItemConfig::STATIC_GEOMETRY);
    else /* IProjectItemConfig::NODE is the default one */
        return (IProjectItemConfig::NODE);
}
