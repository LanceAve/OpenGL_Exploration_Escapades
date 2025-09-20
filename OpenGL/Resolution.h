#ifndef RESOLUTION_H
#define RESOLUTION_H

// Recall: Struct defaults to public when made
// if not specified
struct Resolution
{
	int m_width;
	int m_height;

	Resolution(int _width, int _height)
	{
		m_width = _width;
		m_height = _height;
	}
};

#endif RESOLUTION_H	//RESOLUTION.H