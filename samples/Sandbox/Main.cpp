#include <Onyx.h>
#include <memory>

int main()
{
	auto application = std::make_unique<Onyx::System::Application>();
	application->Run();
}
