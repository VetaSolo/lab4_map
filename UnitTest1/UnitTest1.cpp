#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_map/My_map.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Test_Remove)
		{
			int value = 50, key[] = { 55,40,65,60,75,57 };
			Mymap map;
			for (int i = 0; i < 6; i++) {
				map.insert(key[i], value);
			}
			map.remove(40);
			try {
				map.remove(40);
				Assert::IsTrue(false);
			}
			catch (const invalid_argument expection) {
				Assert::AreEqual(expection.what(), "key not found!!!");
			}
			map.remove(55);
			try {
				map.remove(55);
				Assert::IsTrue(false);
			}
			catch (const invalid_argument expection) {
				Assert::AreEqual(expection.what(), "key not found!!!");
			}
			map.remove(65);
			try {
				map.remove(65);
				Assert::IsTrue(false);
			}
			catch (const invalid_argument expection) {
				Assert::AreEqual(expection.what(), "key not found!!!");
			}
			map.remove(60);
			try {
				map.remove(60);
				Assert::IsTrue(false);
			}
			catch (const invalid_argument expection) {
				Assert::AreEqual(expection.what(), "key not found!!!");
			}}

		TEST_METHOD(Test_insert) {
			Mymap map;
			map.insert(1, 35);
			Assert::IsTrue(map.find(1) == 35);
			map.insert(2, 41);
			Assert::IsTrue(map.find(2) == 41);
		}
		
		TEST_METHOD(Test_Get_List) {
				int value = 50, key[] = { 55,40,65,60,75,57 };
				Mymap map;
				MyList maplist, maplist1;
				try {
					maplist = map.get_keys();
					Assert::IsTrue(false);
				}
				catch (const out_of_range expection) {
					Assert::AreEqual(expection.what(), "the tree does not exist!");
				}
				for (int i = 0; i < 6; i++) {
					map.insert(key[i], key[i]);
				}
				maplist = map.get_keys();
				Assert::IsTrue(maplist.contains(55) && maplist.contains(40) && maplist.contains(65)
					&& maplist.contains(60) && maplist.contains(75) && maplist.contains(57)
					&& maplist.get_size() == 6);
				maplist1 = map.get_values();
				Assert::IsTrue(maplist1.contains(55) && maplist1.contains(40) && maplist1.contains(65)
					&& maplist1.contains(60) && maplist1.contains(75) && maplist1.contains(57)
					&& maplist1.get_size() == 6);
			}

		TEST_METHOD(Test_Find) {
			Mymap map;
			map.insert(1, 2);
			Assert::IsTrue(map.find(1) == 2);
			try {
				map.find(500);
				Assert::IsTrue(false);
			}
			catch (const invalid_argument expection) {
				Assert::AreEqual(expection.what(), "Key not found!!");
			}
		}
	};
}
