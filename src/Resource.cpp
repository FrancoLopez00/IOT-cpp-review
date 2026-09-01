#include "Resource.h"

/**
 *
 * @brief Constructor for the Resource class.
 * @param name The name of the resource.
 * @param type The type of the resource (consumable or usable) .
 */
Resource::Resource(std::string_view name, Type type)
    : name(name), resourceType(type), isAvailable(true) {}

/**
 * @brief returns the name of the resource.
 * @return A non-owning view of the resource's name.
 */
std::string_view Resource::getName() const {
    return name;
}

/**
 * @brief Returns the type of the resource.
 * @return The type of the resource (consumable or usable).
 */
Type Resource::getResourceType() const {
    return resourceType;
}