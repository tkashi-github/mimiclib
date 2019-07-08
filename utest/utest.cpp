
/**
 * @file utest.c
 * @brief unit test
 * @author Takashi Kashiwagi
 * @date 2018/7/5
 * @details 
 * --
 * License Type <MIT License>
 * --
 * Copyright 2018-2019 Takashi Kashiwagi
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 * DEALINGS IN THE SOFTWARE.
 */
#include "mimiclib.h"

#include "CppUTest/CommandLineTestRunner.h"



#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus
    extern void UnitTeset(void);
#ifdef __cplusplus
}
#endif  // __cplusplus

extern




int main(int argc, char *argv[]){
	//UnitTeset();
	return CommandLineTestRunner::RunAllTests(argc, argv);
}

#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

// テストグループを定義
TEST_GROUP(TestFuncGroup)
{
    // 各テストケースの実行直前に呼ばれる仮想メソッド
    TEST_SETUP()
    {
        std::cout << " TEST_SETUP called" << std::endl;
    }

    // 各テストケースの実行直後に呼ばれる仮想メソッド
    TEST_TEARDOWN()
    {
        std::cout << " TEST_TEARDOWN called" << std::endl;
    }
};

// テストを実行するメソッド
TEST(TestFuncGroup, mimic_memcmp_false)
{
    std::cout << "mimic_memcmp : false Test" << std::endl;
    CHECK_EQUAL(false, mimic_memcmp((uintptr_t)"00", (uintptr_t)"11", 2));
}
TEST(TestFuncGroup, mimic_memcmp_true)
{
    std::cout << "mimic_memcmp : true Test" << std::endl;
    CHECK_EQUAL(true, mimic_memcmp((uintptr_t)"00", (uintptr_t)"00", 2));
}

TEST(TestFuncGroup, mimic_mimic_strcmp_enStr1ltStr2_1)
{
    std::cout << "mimic_mimic_strcmp == enStr1ltStr2_1 Test" << std::endl;
    CHECK_EQUAL(enStr1ltStr2, mimic_strcmp("023", "123", 4));
}

TEST(TestFuncGroup, mimic_mimic_strcmp_enStr1ltStr2_2)
{
    std::cout << "mimic_mimic_strcmp == enStr1ltStr2_2 Test" << std::endl;
    CHECK_EQUAL(enStr1ltStr2, mimic_strcmp("1234", "1235", 5));
}

TEST(TestFuncGroup, mimic_mimic_strcmp_enStr1eqStr2_1)
{
    std::cout << "mimic_mimic_strcmp == enStr1eqStr2_1 Test" << std::endl;
    CHECK_EQUAL(enStr1eqStr2, mimic_strcmp("1", "1", 2));
}

TEST(TestFuncGroup, mimic_mimic_strcmp_enStr1eqStr2_2)
{
    std::cout << "mimic_mimic_strcmp == enStr1eqStr2_2 Test" << std::endl;
    CHECK_EQUAL(enStr1eqStr2, mimic_strcmp("12", "12", 3));
}

TEST(TestFuncGroup, mimic_mimic_strcmp_enStr1eqStr2_3)
{
    std::cout << "mimic_mimic_strcmp == enStr1eqStr2_3 Test" << std::endl;
    CHECK_EQUAL(enStr1eqStr2, mimic_strcmp("0123456789", "0123456789", 11));
}


TEST(TestFuncGroup, mimic_mimic_strcmp_enStr1gtStr2_1)
{
    std::cout << "mimic_mimic_strcmp == enStr1gtStr2_1 Test" << std::endl;
    CHECK_EQUAL(enStr1gtStr2, mimic_strcmp("2", "1", 2));
}

TEST(TestFuncGroup, mimic_mimic_strcmp_enStr1gtStr2_2)
{
    std::cout << "mimic_mimic_strcmp == enStr1gtStr2_2 Test" << std::endl;
    CHECK_EQUAL(enStr1gtStr2, mimic_strcmp("21", "11", 3));
}

TEST(TestFuncGroup, mimic_mimic_strcmp_enStr1gtStr2_3)
{
    std::cout << "mimic_mimic_strcmp == enStr1gtStr2_3 Test" << std::endl;
    CHECK_EQUAL(enStr1gtStr2, mimic_strcmp("012345678A", "0123456789", 10));
}

TEST(TestFuncGroup, mimic_mimic_strcmp_enRangeMax_1)
{
    std::cout << "mimic_mimic_strcmp == enRangeMax_1 Test" << std::endl;
    CHECK_EQUAL(enRangeMax, mimic_strcmp("0", "0", 1));
}
TEST(TestFuncGroup, mimic_mimic_strcmp_enRangeMax)
{
    std::cout << "mimic_mimic_strcmp == enRangeMax Test" << std::endl;
    CHECK_EQUAL(enRangeMax, mimic_strcmp("0123456789", "0123456789", 10));
}


TEST(TestFuncGroup, mimic_mimic_strcmp_enArgmentError_1)
{
    std::cout << "mimic_mimic_strcmp == enArgmentError_1 Test" << std::endl;
    CHECK_EQUAL(enArgmentError, mimic_strcmp(NULL, "0123456789", 10));
}
TEST(TestFuncGroup, mimic_mimic_strcmp_enArgmentError_2)
{
    std::cout << "mimic_mimic_strcmp == enArgmentError_2 Test" << std::endl;
    CHECK_EQUAL(enArgmentError, mimic_strcmp("0123456789", NULL, 10));
}

TEST(TestFuncGroup, mimic_tcslen_0)
{
    std::cout << "mimic_tcslen("") == 0 Test" << std::endl;
    CHECK_EQUAL(0, mimic_tcslen(""));
}
TEST(TestFuncGroup, mimic_tcslen_1)
{
    std::cout << "mimic_tcslen("") == 1 Test" << std::endl;
    CHECK_EQUAL(1, mimic_tcslen("1"));
}
TEST(TestFuncGroup, mimic_tcslen_10)
{
    std::cout << "mimic_tcslen("") == 10 Test" << std::endl;
    CHECK_EQUAL(10, mimic_tcslen("0123456789"));
}

TEST(TestFuncGroup, mimic_sprintf_HelloWorld_OK)
{
    char szStr[512];

    std::cout << "mimic_sprintf == \"Hello World\" OKTest" << std::endl;
    mimic_sprintf(szStr, sizeof(szStr), "Hello World");
    CHECK_EQUAL(enStr1eqStr2, mimic_strcmp(szStr, "Hello World", sizeof(szStr)));
}
TEST(TestFuncGroup, mimic_sprintf_HelloWorld_NG)
{
    char szStr[512];

    std::cout << "mimic_sprintf != \"Hello World\" NG Test" << std::endl;
    mimic_sprintf(szStr, sizeof(szStr), "hello World");
    CHECK_EQUAL(enStr1gtStr2, mimic_strcmp(szStr, "Hello World", sizeof(szStr)));
}
TEST(TestFuncGroup, mimic_sprintf_Float)
{
    char szStr[512];

    std::cout << "mimic_sprintf == \"1.23456\" OKTest" << std::endl;
    mimic_sprintf(szStr, sizeof(szStr), "%f", 1.23456);

    std::cout << szStr << std::endl;
    CHECK_EQUAL(enStr1eqStr2, mimic_strcmp(szStr, "1.23456", sizeof(szStr)));
}
TEST(TestFuncGroup, mimic_ftoa_1_2)
{
    char szStr[512];

    std::cout << "mimic_ftoa == \"1.2\" OKTest" << std::endl;
    mimic_ftoa(1.2, szStr, sizeof(szStr), 1);

    std::cout << szStr << std::endl;
    CHECK_EQUAL(enStr1eqStr2, mimic_strcmp(szStr, "1.2", sizeof(szStr)));
}
TEST(TestFuncGroup, mimic_atof_OK)
{
    char szStr[512];

    std::cout << "mimic_atof(\"12.34\", 5) == \"12.34\" OKTest" << std::endl;

    CHECK_EQUAL(12.34, mimic_atof("12.34", 5));
}
