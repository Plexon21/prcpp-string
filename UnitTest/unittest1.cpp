#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Uebung3\MyString.h"
#include <cstring>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest {
	TEST_CLASS(MyString) {
public:
	TEST_METHOD(Construction) {
		String s0;
		String s1("");
		String s2("abc");
		String s00(s0);
		String s11(s1);
		String s22(s2);
	}
	TEST_METHOD(Length) {
		Assert::IsTrue(String().length() == 0);
		Assert::IsTrue(String("").length() == 0);
		Assert::IsTrue(String("abc").length() == 3);
	}
	TEST_METHOD(TSoCString) {
		Assert::AreEqual("12345", String("12345").toCString().get());
		Assert::AreEqual("", String("").toCString().get());
		Assert::AreEqual("", String().toCString().get());
	}
	TEST_METHOD(SubString) {
		String abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		Assert::AreEqual("D", abc.substring(3, 4).toCString().get());
		Assert::AreEqual("CDEFGH", abc.substring(2, 8).toCString().get());
		Assert::AreEqual("DEF", abc.substring(2, 8).substring(1, 4).toCString().get());
		Assert::AreEqual("", abc.substring(2, 8).substring(1, 4).substring(4, 5).toCString().get());
		Assert::AreEqual("", abc.substring(2, 1).toCString().get());
		Assert::AreEqual("", abc.substring(5, 3).toCString().get());
	}
	TEST_METHOD(Concat) {
		Assert::AreEqual("Gugus", String("Gugu").concat('s').toCString().get());
		Assert::AreEqual("Fit und munter?", String("Fit ").concat(String("und ").concat(String("mun")).concat(String("ter?"))).toCString().get());
	}
	TEST_METHOD(CompareTo) {
		Assert::IsTrue(String("a").compareTo("z") == -1);
		Assert::IsTrue(String("c").compareTo("a") == 1);
		Assert::IsTrue(String("aaa").compareTo("bbb") == -1);
		Assert::IsTrue(String("ccc").compareTo("aaa") == 1);
		Assert::IsTrue(String("aaa").compareTo("aac") == -1);
		Assert::IsTrue(String("aac").compareTo("aaa") == 1);
		Assert::IsTrue(String("x").compareTo("x") == 0);
		Assert::IsTrue(String("abc").compareTo("abc") == 0);
	}
	TEST_METHOD(ValueOf) {
		Assert::IsTrue(String("0") == String::valueOf(0));
		Assert::IsTrue(String("5") == String::valueOf(5));
        Assert::IsTrue(String("-2") == String::valueOf(-2));
		Assert::IsTrue(String("345") == String::valueOf(345));
		Assert::IsTrue(String("9853") == String::valueOf(9853));
		Assert::IsTrue(String("-1234") == String::valueOf(-1234));
		Assert::IsTrue(String("123456789") == String::valueOf(123456789));
		Assert::IsTrue(String("-123456789") == String::valueOf(-123456789));
	}
	TEST_METHOD(CharAt) {
		Assert::IsTrue('1' == String("12345").charAt(0));
		Assert::IsTrue('3' == String("12345").charAt(2));
		Assert::IsTrue('5' == String("12345").charAt(4));
		try
		{
			String("12345").charAt(42);
			Assert::Fail;
		}
		catch (const std::out_of_range&)
		{
		}
	}
	};
}