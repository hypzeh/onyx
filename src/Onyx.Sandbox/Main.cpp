#include <memory>
#include <Onyx.h>

int main()
{
	auto application = std::make_unique<Onyx::Engine::System::Application>();
	application->Run();
}