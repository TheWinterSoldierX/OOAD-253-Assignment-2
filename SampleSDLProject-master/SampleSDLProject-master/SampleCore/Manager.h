#pragma once

namespace core
{

	class Manager
	{
	public:
		Manager();
		virtual ~Manager();

		bool Init();
		void Update();
		void Draw() const;
		bool Shutdown();
	};
}