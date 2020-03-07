#pragma once
#include <Onyx.h>

using namespace Onyx::Engine::Components;

class MouseLayer : public Layer
{
public:
  MouseLayer();
  virtual ~MouseLayer() = default;

protected:
  void OnUpdate() override;
  void OnEvent(const Event& event);
};