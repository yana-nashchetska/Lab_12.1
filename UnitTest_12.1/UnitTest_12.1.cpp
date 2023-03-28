#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.1/Lab_12_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest121
{
	TEST_CLASS(UnitTest121)
	{
	public:
		
		TEST_METHOD(TestMethod1)
        {
            Elem* zero = new Elem;
            zero = NULL;
            Elem* p = new Elem;
            p->info = 1;
            p->link2 = NULL;
            p->link1 = new Elem;
            p->link1->info = 2;
            p->link1->link1 = p;
            p->link1->link2 = new Elem;
            p->link1->link2->link1 = p;
            p->link1->link2->info = 4;
            p->link1->link2->link2 = new Elem;
            p->link1->link2->link2->info = 3;
            p->link1->link2->link2->link2 = NULL;
            p->link1->link2->link2->link1 = p->link1;

            delete p->link1->link2->link2;
            p->link1->link2->link2 = NULL;
            delete p->link1->link2->link1->link2;
            p->link1->link2->link1->link2 = NULL;
            delete p->link1->link2->link1;
            p->link1->link2->link1 = NULL;
            delete p->link1->link2;
            p->link1->link2 = NULL;
            delete p->link1;
            p->link1 = NULL;
            delete p;
            p = NULL;

            Assert::AreEqual(p, zero);
		}
	};
}
