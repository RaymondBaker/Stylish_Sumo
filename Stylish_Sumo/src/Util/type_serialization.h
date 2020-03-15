#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Network/Packet.hpp>

namespace ss {


    template <typename T>
    sf::Packet& operator <<(sf::Packet& packet, const sf::Vector2<T>& vec2)
    {
        return packet << vec2.x << vec2.y;
    }

    template <typename T>
    sf::Packet& operator >>(sf::Packet& packet, sf::Vector2<T>& vec2)
    {
        return packet >> vec2.x >> vec2.y;
    }

}