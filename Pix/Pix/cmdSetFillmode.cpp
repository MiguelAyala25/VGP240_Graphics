#include "cmdSetFillmode.h"
#include "Rasterizer.h"

bool CmdSetFillMode::Execute(const std::vector<std::string>& params)
{

	if (params.size() < 1)
	{
		return false;
	}

	FillMode fillmnode = FillMode::WireFrame;

	if (params[0] == "wireframe")
	{
		fillmnode = FillMode::WireFrame;
	}

	else if (params[0] == "solid")
	{
		fillmnode = FillMode::Solid;
	}
	else
	{
		return false;
	}

	Rasterizer::Get()->SetFillMode(fillmnode);
	return true;
}
