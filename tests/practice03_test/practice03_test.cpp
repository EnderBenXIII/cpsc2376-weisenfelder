#include "pch.h"
#include "CppUnitTest.h"  
#include <stdexcept>
#include <vector>
#include <climits> 


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathUtilsTests
{
    TEST_CLASS(MathUtilsTests)
    {
    public:

        TEST_METHOD(TestSumRange)
        {
            // Test 1: Sum of 1 to 5
            Assert::AreEqual(MathUtils::sumRange(1, 5), 15); // Expected result: 15

            // Test 2: Sum when start equals end
            Assert::AreEqual(MathUtils::sumRange(5, 5), 5);  // Expected result: 5 

            // Test 3: Negative sum
            Assert::AreEqual(MathUtils::sumRange(-5, 0), -15); // Expected result: -15
        }

        TEST_METHOD(TestContainsNegative)
        {
            // Test 1: Empty vector
            Assert::IsFalse(MathUtils::containsNegative({}));

            // Test 2: Vector with no negative numbers
            Assert::IsFalse(MathUtils::containsNegative({ 1, 2, 3, 4 }));

            // Test 3: Vector with a negative number
            Assert::IsTrue(MathUtils::containsNegative({ 1, -2, 3, 4 }));

            // Test 4: Vector with negative number at the start
            Assert::IsTrue(MathUtils::containsNegative({ -1, 2, 3 }));

            // Test 5: Vector with all positive numbers
            Assert::IsFalse(MathUtils::containsNegative({ 1, 2, 3 }));
        }

        TEST_METHOD(TestFindMax)
        {
            // Test 1: Empty vector (should throw exception or handle error)
            try
            {
                MathUtils::findMax({});
                Assert::Fail(L"Expected exception for empty vector.");
            }
            catch (const std::invalid_argument&)
            {
                // Expected exception
            }

            // Test 2: Single element vector
            Assert::AreEqual(MathUtils::findMax({ 5 }), 5);

            // Test 3: Multiple elements in sorted order
            Assert::AreEqual(MathUtils::findMax({ 1, 2, 3, 4, 5 }), 5);

            // Test 4: Multiple elements in shuffled order
            Assert::AreEqual(MathUtils::findMax({ 1, 3, 2, 5, 4 }), 5);
        }
    };
}
