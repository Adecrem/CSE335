#include "pch.h"
#include "CppUnitTest.h"

#include <regex>
#include <string>
#include <fstream>
#include <streambuf>

#include "Game.h"
#include "Vector.h"
#include "Gnome.h"
#include "Villain.h"
#include "Money.h"
#include "Background.h"
#include "ItemVisitor.h"
#include "AddMoneyVisitor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	class CTestVisitor : public CItemVisitor
	{
	public:
		virtual void VisitMoney(CMoney* money) { mNumMoney++; }

		int mNumMoney = 0;
	};

	TEST_CLASS(CGameTest)
	{
	public:
		/**
		* Create a path to a place to put temporary files
		*/
		wstring TempPath()
		{
			// Create a path to temporary files
			wchar_t path_nts[MAX_PATH];
			GetTempPath(MAX_PATH, path_nts);

			//  Convert null terminated string to wstring
			return wstring(path_nts);
		}

		/**
		* Read a file into a wstring and return it.
		* \param filename Name of the file to read
		* \return File contents
		*/
		wstring ReadFile(const wstring& filename)
		{
			ifstream t(filename);
			wstring str((istreambuf_iterator<char>(t)),
				istreambuf_iterator<char>());

			return str;
		}
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}

		TEST_METHOD(TestCGameConstruct)
		{
			CGame game;
		}

		TEST_METHOD(TestCCityIterator)
		{
			// Construct a city object
			CGame game;

			// Add some tiles
			auto item1 = make_shared<CMoney>(&game);
			auto item2 = make_shared<CVillain>(&game);
			auto item3 = make_shared<CGnome>(&game);

			game.Add(item1);
			game.Add(item2);
			game.Add(item3);

			// Begin points to the first item
			auto iter1 = game.begin();

			// End points after the last item
			auto iter2 = game.end();

			Assert::IsTrue(item1 == *iter1, L"First item correct");
			++iter1;
			Assert::IsTrue(item2 == *iter1, L"Second item correct");
			++iter1;
			Assert::IsTrue(item3 == *iter1, L"Third item correct");
			++iter1;
			Assert::IsFalse(iter1 != iter2);
		}

		TEST_METHOD(TestCCityVisitor)
		{
			// Construct a city object
			CGame game;

			// Add some tiles of each time
			auto item1 = make_shared<CMoney>(&game);
			auto item2 = make_shared<CGnome>(&game);
			auto item3 = make_shared<CVillain>(&game);
			auto item4 = make_shared<CBackground>(&game);

			game.Add(item1);
			game.Add(item2);
			game.Add(item3);
			game.Add(item4);

			CTestVisitor visitor;
			game.Accept(&visitor);
			Assert::AreEqual(1, visitor.mNumMoney,
				L"Visitor number of roads");
		}
	};
}