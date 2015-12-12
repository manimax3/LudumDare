#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "Scene.h"

class SceneManager
{
private:
	std::vector<std::unique_ptr<Scene>> scenes;
public:
	std::unique_ptr<Scene>& getCurrent();
	void add(Scene* scene);
	void flipScene();
	static SceneManager* getInstance();
	static void remove_instance();
private:
	SceneManager();
	~SceneManager();
};
static SceneManager *instance;

