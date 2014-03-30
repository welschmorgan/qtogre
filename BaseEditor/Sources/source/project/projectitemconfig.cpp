#include "include/projectitemconfig.h"

IProjectItemConfig::IProjectItemConfig(Type t)
    : mType(t)
{
}
IProjectItemConfig::IProjectItemConfig(const IProjectItemConfig &other)
    : tag<IProjectItemConfig, std::string>(other)
    , mType(other.mType)
{}

const std::string IProjectItemConfig::ROOT_STR = "root";
const std::string IProjectItemConfig::MATERIAL_STR = "material";
const std::string IProjectItemConfig::MESH_STR = "mesh";
const std::string IProjectItemConfig::PARTICLE_STR = "particle";
const std::string IProjectItemConfig::LIGHT_STR = "light";
const std::string IProjectItemConfig::BILLBOARD_STR = "billboard";
const std::string IProjectItemConfig::STATIC_GEOMETRY_STR = "static geometry";
const std::string IProjectItemConfig::NODE_STR = "node";

std::string              IProjectItemConfig::toString(IProjectItemConfig::Type type)
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

IProjectItemConfig::Type    IProjectItemConfig::toType(const std::string &name)
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
