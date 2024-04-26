
#pragma once

#include "Command.h"

class CmdShowtViewPort : public Command
{
public:
	const char* GetName() override
	{
		return "ShowViewPort";
	}

	const char* GetDescription() override
	{
		return
			"ShowViewPort(x, y, width, height)\n"
			"\n"
			"- Sets the show area.\n";

	}

	bool Execute(const std::vector<std::string>& params) override;
};
