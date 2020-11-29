#include "pch.h"
#include "CppUnitTest.h"

#include "Item.h"
#include "Game.h"
#include "Gnome.h"
#include "Vector.h"
#include "CItemTest.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CGnomeTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}

		TEST_METHOD(TestCItemConstruct)
		{
			// Construct an item to test
			CGame game;
			CItemMock item(&game);
		}

	};
}