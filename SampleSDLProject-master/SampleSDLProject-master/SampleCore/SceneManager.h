#pragma once
#include "Manager.h"
#include <vector>
namespace core
{
	class SceneManager : public Manager
	{
	public:
		SceneManager();
		virtual ~SceneManager();

		std::vector<class Scene*> scenes;
	};
}
