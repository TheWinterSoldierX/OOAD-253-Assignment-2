#pragma once
#include <stdio.h>
#include <vector>


namespace scene 
{
	class Scene;
}

namespace core
{

	class Engine
	{
	private:
		bool isRunning;
		std::vector<class Manager*> managers;

		scene::Scene* Scene1;

		void Update();
		void Draw() const;
		int Shutdown();

	public:
		Engine(scene::Scene *s);
		~Engine();

		int Init();
		int Run();
		void print();
	};
}
