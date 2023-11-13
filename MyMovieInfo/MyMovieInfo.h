#pragma once

#include <vector>
#include "MovieData.h"

class MyMovieInfo
{
public:
	MyMovieInfo(void) {}
	~MyMovieInfo() {}

private:
	std::vector<MovieData> m_data;
};