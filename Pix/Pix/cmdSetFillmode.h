
#pragma once

#include "Command.h"

class CmdSetFillMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetFillMode";
	}

	const char* GetDescription() override
	{
		return
			"SetFIllMode(<fillmode>)\n"
			"\n"
			"- Sets fillmode to read vertices (wireframe, filled)";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

