#pragma once

#include <vector>
#include <string>
#include <memory>

#include "../Types/Vector2f.h"
#include "GOComponent.h"

namespace grs
{
	class GameObject
	{
		public:
			/* Object's name */
			std::string name;
			
			/* Object's position */
			Vector2f position;
			/* Object's rotation in radians */
			float rotation;

			/* Adds a component to the GameObject */
			void AddComponent(std::shared_ptr<GOComponent> component);

			void Update();

			GameObject(std::string name, Vector2f position, float rotation);
			GameObject();
			~GameObject();

		private:
			/* List of all components a GameObject has */
			std::vector<std::shared_ptr<GOComponent> > components;
	};
}