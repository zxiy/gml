#pragma once

#include <gml/include/vector3.h>

namespace gml
{
	class aabb
	{
	public:
		bool operator==(const aabb& other);

		inline const vector3& center() const { return m_center; }

		inline const vector3& min_bound() const { return m_min_bound; }

		inline const vector3& max_bound() const { return m_max_bound; }

		inline const vector3& extend() const { return m_extend; }

		inline bool is_empty() const { return m_is_empty; }

		bool is_contain(const aabb& other) const;

		bool is_contain(const vector3& point) const;

		void expand(const vector3& point);

		void expand(const aabb& other);

		void clear();

	private:
		bool m_is_empty = true;
		vector3 m_min_bound = vector3::zero;
		vector3 m_max_bound = vector3::zero;
		vector3 m_center = vector3::zero;
		vector3 m_extend = vector3::zero;
	};
}