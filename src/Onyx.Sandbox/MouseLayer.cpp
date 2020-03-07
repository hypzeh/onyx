#include "MouseLayer.h"

MouseLayer::MouseLayer()
  : Layer("MOUSE_LAYER")
{}

void MouseLayer::OnUpdate()
{
  
}

void MouseLayer::OnEvent(const Event& event)
{
  std::cout << "MouseLayer >> " << event.GetName() << std::endl;
}
