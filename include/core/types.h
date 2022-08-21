#ifndef TYPES_H_
#define TYPES_H_

#include <bitset>
#include <cstdint>

using Entity = std::uint32_t;
const Entity max_entities = 100;
using ComponentType = std::uint8_t;
const ComponentType max_components = 32;
using Signature = std::bitset<max_components>;

#endif // TYPES_H_
