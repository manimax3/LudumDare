#include "SceneManager.h"


//Get the current active running scene
std::unique_ptr<Scene>& SceneManager::getCurrent()
{
	return scenes.front();
}

//Add a new Scene (not executed yet)
void SceneManager::add(Scene* scene)
{
	scenes.push_back(std::unique_ptr<Scene>(scene));
}

//Unload the current scene and load the new Scene (now is the new one executed)
void SceneManager::flipScene()
{
	//Adding the new scene created by the old scene
	this->add(scenes.front()->unload());

	//Loading the new one
	scenes.at(1)->load();

	//Removing the old one
	scenes.erase(scenes.begin());
}

//Get the Singleton of the Manager (NOTE: Has to be called at least once)
SceneManager* SceneManager::getInstance()
{
	if (!instance) {
		instance = new SceneManager();
	}
	return instance;
}

//Removes the Singleton (Has to be called at the end of the Game)
void SceneManager::remove_instance()
{
	if (instance) {
		delete instance;
		//instance = nullptr;
	}
}



SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}
