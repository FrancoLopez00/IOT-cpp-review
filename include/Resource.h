//
// Created by alumnos on 1/9/26.
//

#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <string_view>

/**
 * @brief Abstract base class representing a resource in executable tasks or processes.
 *
 * This class difines the interface for resources that can be allocated, released, and used.
 * The resourced can be consumable (e.g., memory) or usable (e.g., a tool or device).
 */
class Resource {
public:
    enum class Type {
        Consumable,
        Usable
    };

protected:
    std::string name;
    Type resourceType;
    bool isAvailable;

public:
    Resource(std::string_view name, Type type);
    virtual ~Resource() = default;

    [[nodiscard]] std::string_view getName() const ;
    [[nodiscard]] virtual bool isAvailableForUse() const = 0;
    virtual void allocate() = 0;
    virtual void release() = 0;
    virtual void use() const = 0;
    [[nodiscard]] virtual std::string describeUsage() const = 0;
    [[nodiscard]] Type getResourceType() const ;
};

#endif //RESOURCE_H
