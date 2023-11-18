#pragma once

namespace Snek {
struct Coord {
public:
	Coord(short, short);
	~Coord() {};

	short X = 0;
	short Y = 0;

	bool operator==(const Coord& other) const {
		return X == other.X && Y == other.Y;
	}
	bool operator!=(const Coord& other) const {
		return X != other.X || Y != other.Y;
	}
};
}