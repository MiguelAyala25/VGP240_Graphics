#pragma once
#include "Vertex.h"

class Clipper
{
public:
	static Clipper* Get();

public:
	void OnNewFrame();

	bool ClipPoint(const Vertex& v);
	bool ClipLine(Vertex& v0, Vertex& v1);
	bool ClipTriangle(std::vector<Vertex>& verticies);

	bool IsClipping() const {
		return mClipping;
	}

	void IsClipping(bool clip) { mClipping = clip; }

private:

	Clipper() {};

	bool mClipping;
};