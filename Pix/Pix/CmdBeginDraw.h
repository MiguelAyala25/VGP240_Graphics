#pragma once

#include "Command.h"

class CmdBeginDraw : public Command
{
public:
	const char* GetName() override
	{
		return "BeginDraw";
	}

	const char* GetDescription() override
	{
		return
			"Begin draw(topology)\n"
			"\n"
			"Begin draw"
			"Stores topology";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
#pragma once
