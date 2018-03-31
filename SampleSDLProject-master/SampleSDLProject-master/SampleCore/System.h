#pragma once

namespace core
{
	enum class SystemType : unsigned __int8
	{
		WINDOW,
		INPUT
	};

	class System
	{
	public:

		System(SystemType type);
		virtual ~System();

		bool Init();
		void Update();
		void Draw() const;
		bool Shutdown();
	};
}