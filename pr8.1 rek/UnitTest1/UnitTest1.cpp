#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Оголошення тестованої функції
extern "C" int Count(char* str, int i = 0);

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestCount)
        {
            // Тестові дані
            char str[] = "abcabcabc"; // рядок з трьома входженнями "abc"

            // Виклик тестованої функції
            int result = Count(str);

            // Перевірка результату
            Assert::AreEqual(3, result); // очікуємо знайти 3 групи "abc"
        }
    };
}