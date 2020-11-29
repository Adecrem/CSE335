#include "pch.h"
#include "CppUnitTest.h"

#include "Item.h"
#include "Aquarium.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Testing
{
        namespace Testing
        {
            /** Mock class for testing CItem */
            class CItemMock : public CItem
            {
            public:
                /** Constructor
                 * \param aquarium The aquarium this is a member of */
                CItemMock(CAquarium* aquarium) :
                    CItem(aquarium, ItemImageName) {}

        /** Test to see if we clicked on this item
 * \param x X location
 * \param y Y location
 * \returns true if we did click on the item */
        virtual bool HitTest(int x, int y) { return false; }

    };

    TEST_CLASS(CItemTest)
    {
    public:
        TEST_METHOD_INITIALIZE(methodName)
        {
            extern wchar_t g_dir[];
            ::SetCurrentDirectory(g_dir);
        }

        TEST_METHOD(TestCItemConstruct)
        {
            CAquarium aquarium;
            CItemMock Item(&aquarium);
        }

        TEST_METHOD(TestCItemGettersSetters)
        {
            // Construct an item to test
            CAquarium aquarium;
            CItemMock Item(&aquarium);

            // Test initial values
            Assert::AreEqual(0, Item.GetX(), 0);
            Assert::AreEqual(0, Item.GetY(), 0);

            // Test SetLocation, GetX, and GetY
            Item.SetLocation(10.5, 17.2);
            Assert::AreEqual(10.5, Item.GetX(), 0.0001);
            Assert::AreEqual(17.2, Item.GetY(), 0.0001);

            // Test a second with with different values
            Item.SetLocation(-72, -107);
            Assert::AreEqual(-72, Item.GetX(), 0.0001);
            Assert::AreEqual(-107, Item.GetY(), 0.0001);
        }
        TEST_METHOD(TestItemTest)
        {
            // Create a fish to test
            CAquarium aquarium;
            CItem item(&aquarium);

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