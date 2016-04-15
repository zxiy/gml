#include "../include/rect.h"

namespace gml
{
	int rect::left()
	{
		return m_pos.x;
	}

	int rect::right()
	{
		return left() + width();
	}

	int rect::top()
	{
		return m_pos.y;
	}

	int rect::bottom()
	{
		return top() + height();
	}

	int rect::width()
	{
		return m_size.x;
	}

	int rect::height()
	{
		return m_size.y;
	}

	coord rect::center()
	{
		return coord((left() + right()) / 2, (top() + bottom()) / 2);
	}

	coord rect::position()
	{
		return m_pos;
	}

	coord rect::size()
	{
		return m_size;
	}

	rect& rect::set_width(int w)
	{
		m_size.x = w > 0 ? w : 0;
		return *this;
	}

	rect& rect::set_height(int h)
	{
		m_size.y = h > 0 ? h : 0;
		return *this;
	}

	rect& rect::set_left(int x)
	{
		m_pos.x = x;
		return *this;
	}

	rect& rect::set_top(int y)
	{
		m_pos.y = y;
		return *this;
	}

	rect& rect::set_pos(int x, int y)
	{
		set_left(x);
		set_top(y);
		return *this;
	}

	rect& rect::set_pos(const coord& pos)
	{
		return set_pos(pos.x, pos.y);
	}

	rect& rect::set_size(int w, int h)
	{
		set_width(w);
		set_height(h);
		return *this;
	}

	rect& rect::set_size(const coord& size)
	{
		return set_size(size.x, size.y);
	}

	bool rect::hit_test(int x, int y)
	{
		return !(x < left() || x > right() || y < top() || y > bottom());
	}

	bool rect::hit_test(const coord& point)
	{
		return hit_test(point.x, point.y);
	}

	rect& rect::move(int offsetx, int offsety)
	{
		m_pos.move(offsetx, offsety);
		return *this;
	}

	rect& rect::enlarge(int offsetw, int offseth)
	{
		m_size.move(offsetw, offseth);
		if (m_size.x < 0) m_size.x = 0;
		if (m_size.y < 0) m_size.y = 0;
		return *this;
	}
}