#include "Clipper.h"
#include "Viewport.h"

const short BIT_INSIDE = 0;		//0000
const short BIT_LEFT =	1 << 1;	//0001
const short BIT_RIGHT = 1 << 2;	//0010
const short BIT_BOTOM = 1 << 3; //0100
const short BIT_TOP =	1 << 4;	//1000


short GetOutPutCode(float x, float y)
{
	Viewport* vp = Viewport::Get();

	short code = BIT_INSIDE;

		if (x > vp->GetMinX())
		{
			code |= BIT_LEFT;
		}
}

Clipper* Clipper::Get()
{
	static Clipper sInstance;
	return &sInstance;
}

Clipper::Clipper()
{

}

void Clipper::OnNewFrame()
{
	mClipping = false;
}

bool Clipper::ClipPoint(const Vertex& v)
{
	if (!mClipping)
	{
		return false;
	}
	Viewport* vp = Viewport::Get();
	float maxX = vp->GetMaxX();
	float minX = vp->GetMinX();
	float maxY = vp->GetMaxY();
	float minY = vp->GetMinY();

	return v.pos.x < minX || v.pos.x > maxX
		|| v.pos.y < minY || v.pos.y > maxY;
}

bool Clipper::ClipLine(Vertex& v0, Vertex& v1)
{
	if (!mClipping)
	{
		return false;
	}

	Viewport* vp = Viewport::Get();
	float maxX = vp->GetMaxX();
	float minX = vp->GetMinX();
	float maxY = vp->GetMaxY();
	float minY = vp->GetMinY();

	return false;
}

bool Clipper::ClipTriangle(std::vector<Vertex>& verticies)
{
	return false;
}
