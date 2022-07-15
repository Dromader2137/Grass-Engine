#pragma once

#include <string>

#include "Types.h"

namespace grs
{
	class GameObject;

	class GOComponent
	{
		public:
			/* Parent GameObject */
			GameObject* gameObject;

			/* Called on GameObject start */
			virtual void OnStart();
			/* Called on every frame */
			virtual void Update();
			/* Called on every frame render phase */
			virtual void Render();
			/* Called on every frame end phase */
			virtual void LateUpdate();

			GOComponent();
			~GOComponent();
	};
}