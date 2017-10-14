#pragma once

#include "Filepaths.h"						

// Base Class.
class Scene
{

protected:

public:
	Scene() {};								// Constructor
	~Scene() { };							// Destructor
	virtual void Start() {};				// initialize
	virtual void Draw() {};					// Draw
	virtual void CheckInputs() {};			// CheckInput
	virtual void Update() {};				// Update
};
