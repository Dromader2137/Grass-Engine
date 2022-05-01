#pragma once

#include <string>

namespace grs
{
	class GOComponent
	{
		public:
			std::string name;

			virtual void OnStart();
			virtual void OnEveryFrame();
	};
}