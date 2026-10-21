#pragma once
#include <string>
// this namespace is for validation and the wait for enter method
namespace Input
{
	int GetNumber(const std::string& prompt, int min, int max);
	std::string GetString(const std::string& prompt, bool allowEmpty = true);
	void WaitForEnter();
}

