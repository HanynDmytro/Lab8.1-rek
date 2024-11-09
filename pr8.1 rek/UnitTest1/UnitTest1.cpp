#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// ���������� ��������� �������
extern "C" int Count(char* str, int i = 0);

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestCount)
        {
            // ������ ���
            char str[] = "abcabcabc"; // ����� � ������ ����������� "abc"

            // ������ ��������� �������
            int result = Count(str);

            // �������� ����������
            Assert::AreEqual(3, result); // ������� ������ 3 ����� "abc"
        }
    };
}