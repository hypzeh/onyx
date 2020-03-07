#pragma once
#include <Onyx.h>

using namespace Onyx::Engine::System;

class App : public Application
{
public:
  App();

protected:
  void OnRun() override;
};
