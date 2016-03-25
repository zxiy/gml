#pragma once
#include <gml/include/vector3.h>

namespace gml
{
	class ray
	{
	public:
		inline const vector3& origin() const { return m_origin; }

		inline const vector3& direction() const { return m_dir; }

		ray& set_origin(float x, float y, float z);

		ray& set_origin(const vector3& origin);

		ray& set_dir(float x, float y, float z);

		ray& set_dir(const vector3& dir);

		vector3 get_pos_by_len(float length) const;

	private:
		vector3 m_origin;
		vector3 m_dir;
	};
}
