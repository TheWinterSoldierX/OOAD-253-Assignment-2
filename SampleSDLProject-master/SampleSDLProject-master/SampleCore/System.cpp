#include "stdafx.h"
#include "System.h"

namespace core
{
	System::System(SystemType type)
	{
	}


	System::~System()
	{
	}

	bool System::Init() {

		return true;
	}

	void System::Update() {

	}

	void System::Draw() const {

	}

	bool System::Shutdown() {

		return true;
	}
}