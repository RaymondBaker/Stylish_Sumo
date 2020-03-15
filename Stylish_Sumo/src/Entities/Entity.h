#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Network/Packet.hpp>
#include <vector>

#include "../Util/type_serialization.h"

namespace ss {
	class Entity {

	private:
		static int _id;
		int m_id;

	public:
		sf::Vector2i m_pos;
		sf::Vector2i m_vel;
		int m_rot;

	public:
		Entity(sf::Vector2i pos, sf::Vector2i vel, int rot) : m_pos(pos), m_vel(vel), m_rot(rot) {
			m_id = _id++;
		}

		inline int id() { return m_id; }

		virtual void update(float dt) = 0;
		virtual void draw() = 0;
		virtual void collis_objects() = 0;


		virtual sf::Packet& serialize(sf::Packet& packet) {
			return packet << m_id << m_pos << m_vel << m_rot;
		}
		virtual sf::Packet& deserialize(sf::Packet& packet) {
			// Don't try to read id since the manager already did
			packet >> m_pos >> m_vel >> m_rot;
		};
	};
}