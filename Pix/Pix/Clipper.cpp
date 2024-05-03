#include "Clipper.h"
#include "Viewport.h"


const int BIT_INSIDE = 0;
const int BIT_LEFT = 1 << 1; // 0001
const int BIT_RIGHT = 1 << 2; // 0010
const int BIT_BOTTOM = 1 << 3; // 0100
const int BIT_TOP = 1 << 4; // 1000

enum class ClipEdge : int
{
	Left,
	Bottom,
	Right,
	Top,
	Count
};

bool IsInFront(ClipEdge edge, const Vector3& pos)
{
	float minX = Viewport::Get()->GetMinX();
	float maxX = Viewport::Get()->GetMaxX();
	float minY = Viewport::Get()->GetMinY();
	float maxY = Viewport::Get()->GetMaxY();

	switch (edge)
	{
	case ClipEdge::Left: return pos.x > minX;
	case ClipEdge::Bottom: return pos.y < maxY;
	case ClipEdge::Right: return pos.x < maxX;
	case ClipEdge::Top: return pos.y > minY;
	default:
		break;
	}

	return false;
}

Vertex ComputeIntersection(ClipEdge edge, const Vertex& v0, const Vertex& v1)
{
	float minX = Viewport::Get()->GetMinX();
	float maxX = Viewport::Get()->GetMaxX();
	float minY = Viewport::Get()->GetMinY();
	float maxY = Viewport::Get()->GetMaxY();

	float t = 0.0f;
	switch (edge)
	{
	case ClipEdge::Left:   t = (minX - v0.pos.x) / (v1.pos.x - v0.pos.x); break;
	case ClipEdge::Bottom: t = (maxY - v0.pos.y) / (v1.pos.y - v0.pos.y); break;
	case ClipEdge::Right:  t = (maxX - v0.pos.x) / (v1.pos.x - v0.pos.x); break;
	case ClipEdge::Top:    t = (minY - v0.pos.y) / (v1.pos.y - v0.pos.y); break;
	default:
		break;
	}

	return LerpVertex(v0, v1, t);
}

int GetOutputCode(float x, float y)
{
	int code = BIT_INSIDE;
	if (x < Viewport::Get()->GetMinX())
	{
		code |= BIT_LEFT; // 0000 | 0001 = 0001
	}
	else if (x > Viewport::Get()->GetMaxX())
	{
		code |= BIT_RIGHT; // 0000 | 0010 = 0010
	}
	if (y < Viewport::Get()->GetMinY())
	{
		code |= BIT_TOP; //0000 | 1000 = 1000
	}
	else if (y > Viewport::Get()->GetMaxY())
	{
		code |= BIT_BOTTOM; // 0000 | 0100 = 0100
	}

	return code;
}

Clipper* Clipper::Get()
{
	static Clipper sInstance;
	return &sInstance;
}

Clipper::Clipper()
{
}

Clipper::~Clipper()
{
}

void Clipper::OnNewFrame()
{
	mIsClipping = false;
}

bool Clipper::ClipPoint(const Vertex& v)
{
	if (!mIsClipping)
	{
		return true;
	}

	float minX = Viewport::Get()->GetMinX();
	float maxX = Viewport::Get()->GetMaxX();
	float minY = Viewport::Get()->GetMinY();
	float maxY = Viewport::Get()->GetMaxY();

	return v.pos.x >= minX && v.pos.x <= maxX
		&& v.pos.y >= minY && v.pos.y <= maxY;
}

bool Clipper::ClipLine(Vertex& v0, Vertex& v1)
{
	if (!mIsClipping)
	{
		return true;
	}
	float minX = Viewport::Get()->GetMinX();
	float maxX = Viewport::Get()->GetMaxX();
	float minY = Viewport::Get()->GetMinY();
	float maxY = Viewport::Get()->GetMaxY();

	int codeV0 = GetOutputCode(v0.pos.x, v0.pos.y);
	int codeV1 = GetOutputCode(v1.pos.x, v1.pos.y);
	bool cullLine = false;

	while (!cullLine)
	{
		if ((codeV0 | codeV1) == BIT_INSIDE)
		{
			cullLine = true;
			break;
		}
		else if ((codeV0 & codeV1) > 0)
		{
			cullLine = false;
			break;
		}
		else
		{
			float t = 0.0f;
			int outCodeOut = (codeV1 > codeV0) ? codeV1 : codeV0;
			if ((outCodeOut & BIT_TOP) > 0)
			{
				t = (minY - v0.pos.y) / (v1.pos.y - v0.pos.y);
			}
			else if ((outCodeOut & BIT_BOTTOM) > 0)
			{
				t = (maxY - v0.pos.y) / (v1.pos.y - v0.pos.y);
			}
			else if ((outCodeOut & BIT_RIGHT) > 0)
			{
				t = (maxX - v0.pos.x) / (v1.pos.x - v0.pos.x);
			}
			else if ((outCodeOut & BIT_LEFT) > 0)
			{
				t = (minX - v0.pos.x) / (v1.pos.x - v0.pos.x);
			}

			if (outCodeOut == codeV0)
			{
				v0 = LerpVertex(v0, v1, t);
				codeV0 = GetOutputCode(v0.pos.x, v0.pos.y);
			}
			else
			{
				v1 = LerpVertex(v0, v1, t);
				codeV1 = GetOutputCode(v1.pos.x, v1.pos.y);
			}
		}
	}

	return cullLine;

}

bool Clipper::ClipTriangle(std::vector<Vertex>& vertices)
{
	if (!mIsClipping)
	{
		return true;
	}

	return false;
}