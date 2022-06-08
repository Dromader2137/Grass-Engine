#pragma once

#include <string>

namespace grs
{
	class GOComponent
	{
		public:
			/* Component's name */
			std::string name;

			/* Called on GameObject start */
			virtual void OnStart();
			/* Called on every frame */
			virtual void Update();

			GOComponent();
			~GOComponent();
	};
}