#pragma once
#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include <fstream>
#include <sstream>
#include <sys/unistd.h>
#include "SplashScreen.h"
#include "Game.h"

class SceneManager
{
public:

	enum SCENES { SPLASH, GAME };			// Scenes: Splashcreen, Gamescreen

	static SceneManager* instance();		// Property to get the singleton instance

	void setActualScene(SCENES _scene);		// Method to set a new scene (E.G: SplashScreen -> GameScreen)
	void Start();							// Method for initialization
	void Update();							// Method called every frame. It calls to scene Draw, Update and CheckInput functions
	bool isOut();							// Method that returns if we are exiting the game from scene (normal exiting)
	void exitGame();						// Method to exit the game (Out = true)
	void ReadData();						// Method for reading data from our save
	void SaveDataAndExit();					// Method that saves our data to the .sav and exits

private:

	SceneManager() {};  // Private so that it can  not be called
	static SceneManager* Instance;	// Singleton Instance

	int m_times_we_have_run_the_program;	// Variable saved in our .sav
	bool m_out;								// if we ended or not the program
	Scene* m_actualScene;					// Scene running
};

#endif