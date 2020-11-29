#include "pch.h"
#include "CppUnitTest.h"
#include "PolyDrawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;
namespace Testing
{
	TEST_CLASS(CPolyDrawableTest)
	{
	public:

		bool CompareColors(Gdiplus::Color color1, Gdiplus::Color color2)
		{
			if (color1.GetValue() == color2.GetValue())
			{
				return true;
			}
			return false;
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
		TEST_METHOD(TestCPolyDrawableConstructor)
		{
			CPolyDrawable draw(L"drawable");
			Assert::AreEqual(std::wstring(L"drawable"), draw.GetName());

		}
		TEST_METHOD(TestCPolyDrawableColor)
		{
			CPolyDrawable draw(L"drawable");
			Assert::IsTrue(CompareColors(Color::Black, draw.GetColor()));
			draw.SetColor(Color::Green);
			Assert::IsTrue(CompareColors(Color::Green, draw.GetColor()));
		}
	};
}