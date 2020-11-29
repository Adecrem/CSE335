#include "pch.h"
#include "CppUnitTest.h"

#include "Item.h"
#include "Game.h"
#include "Level.h"
#include "Vector.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

const std::wstring ImageName = L"images/wall1.png";

namespace Testing
{
	/** Mock class for testing CItem */
	class CItemMock : public CItem
	{
	public:
		CItemMock(CGame* game) : CItem(game, ImageName) {}

		virtual void Draw(Gdiplus::Graphics* graphics) {}

		///  Default constructor (disabled)
		CItemMock() = delete;

		///  Copy constructor (disabled)
		CItemMock(const CItemMock&) = delete;

		~CItemMock() {}

		/** Accept a visitor
		 * \param visitor The visitor we accept */
		virtual void Accept(CItemVisitor* visitor) override { }
	};
	TEST_CLASS(CItemTest)
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
			CGame game;
			CItemMock item(&game);
		}
		TEST_METHOD(TestCItemGettersSetters)
		{
			// Construct an item to test
			CGame game;
			CItemMock item(&game);

			// Test SetLocation, GetX, and GetY
			item.SetLocation(10.5, 17.2);
			Assert::AreEqual(10.5, item.GetX(), 0.0001);
			Assert::AreEqual(17.2, item.GetY(), 0.0001);
		}
		TEST_METHOD(TestCItemMockHitTest)
		{
			// Create a item to test
			CGame game;
			CItemMock item(&game);

			// Give it a location
			// Always make the numbers different, in case they are mixed up
			item.SetLocation(100, 200);

			// Center of the fish should be a true
			Assert::IsTrue(item.HitTest(100, 200));

			// Left of the fish
			Assert::IsFalse(item.HitTest(10, 200));

			// Right of the fish
			Assert::IsFalse(item.HitTest(200, 200));

			// Above the fish
			Assert::IsFalse(item.HitTest(100, 0));

			// Below the fish
			Assert::IsFalse(item.HitTest(100, 300));

			// Of fish transparent pixel
			Assert::IsFalse(item.HitTest(100 - 125 / 2 + 17, 200 - 117 / 2 + 16));
		}
	};
}