#ifndef DOMAIN_TYPES_H
#define DOMAIN_TYPES_H

class DurationInUnits final {
    int units;

public:
    explicit constexpr DurationInUnits(const int units) noexcept : units(units) {}
        [[nodiscard]] constexpr int count() const noexcept { return units; }
        [[nodiscard]] constexpr bool isPositive() const noexcept { return units > 0; }
};

class ResourceUnits final {
    explicit constexpr ResourceUnits(const int units) noexcept : units(units) {}
    [[nodiscard]] constexpr int count() const noexcept { return units; }
    [[nodiscard]] constexpr bool isPositive() const noexcept { return units > 0; }
    [[nodiscard]] constexpr bool isDepleted() const noexcept { return units <= 0; }
    constexpr void consumeOne() noexcept { --units; }
};
#endif // DOMAIN_TYPES_H
