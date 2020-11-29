#include "pch.h"
#include "CppUnitTest.h"
#include "Actor.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;
namespace Testing
{
	TEST_CLASS(CActorTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCActorPosition)
		{
			CActor actor(L"Harold");
			actor.SetPosition(Point(50, 125));
			Assert::AreEqual(50, actor.GetPosition().X);
			Assert::AreEqual(125, actor.GetPosition().Y);
		}
		TEST_METHOD(TestCActorConstructor)
		{
			CActor actor(L"Harold");
			Assert::AreEqual(std::wstring(L"Harold"), actor.GetName());
			CActor actor(L"Harold");
			Assert::AreEqual(0, actor.GetPosition().X);
			Assert::AreEqual(0, actor.GetPosition().Y);
		}
		TEST_METHOD(TestCActorClickable)
		{
			CActor actor(L"Harold");
			Assert::IsTrue(actor.IsClickable());
		}

	};
}