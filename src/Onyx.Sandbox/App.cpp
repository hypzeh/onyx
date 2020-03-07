#include "App.h"
#include "MouseLayer.h"

App::App()
{
  PushLayer(new MouseLayer());
}

void App::OnRun()
{
  ONYX_LOG_TRACE("Sandbox application running...");
}
