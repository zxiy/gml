#include "../include/ray.h"

namespace gml
{
	ray& ray::set_origin(float x, float y, float z)
	{
		m_origin.set(x, y, z);
		return *this;
	}

	ray& ray::set_origin(const vector3& origin)
	{
		m_origin = origin;
		return *this;
	}

	ray& ray::set_dir(float x, float y, float z)
	{
		m_dir.set(x, y, z);
		return *this;
	}


	ray& ray::set_dir(const vector3& dir)
	{
		m_dir = dir.normalized();
		return *this;
	}

	vector3 ray::get_pos_by_len(float length) const
	{
		return m_origin + m_dir * length;
	}
}