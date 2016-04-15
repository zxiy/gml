#pragma once

namespace gml
{
	class coord
	{
	public:
		int x = 0;
		int y = 0;

	public:
		coord();

		coord(int x, int y);

		coord& set(int x, int y);

		coord& move(int offsetx, int offsety);
	};

	class rect
	{
	public:
		int left();

		int right();

		int top();

		int bottom();

		int width();

		int height();

		coord center();

		coord position();

		coord size();
		
		rect& set_width(int w);

		rect& set_height(int h);

		rect& set_left(int x);

		rect& set_top(int y);

		rect& set_pos(int x, int y);

		rect& set_pos(const coord& pos);

		rect& set_size(int w, int h);

		rect& set_size(const coord& size);

		bool hit_test(int x, int y);

		bool hit_test(const coord& point);

		rect& move(int offsetx, int offsety);
		
		rect& enlarge(int offsetw, int offseth);

	private:
		coord m_pos;
		coord m_size;
	};
}
