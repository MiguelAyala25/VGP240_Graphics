#include "CmdShowViewPort.h"
#include "Viewport.h"
#include "VariableCache.h"

bool CmdShowtViewPort::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	bool show = params[0] == "true";
	Viewport::Get()->ShowViewport(show);

	return true;
}
