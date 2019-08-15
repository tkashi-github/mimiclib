
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
#include <string.h>
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

// strlen - start
TEST(TestFuncGroup, mimic_strlen_OK_1)
{
    CHECK_EQUAL(1, mimic_strlen("0", 2));
}
TEST(TestFuncGroup, mimic_strlen_OK_2)
{
    CHECK_EQUAL(0, mimic_strlen("", 1));
}
TEST(TestFuncGroup, mimic_strlen_OK_3)
{
    CHECK_EQUAL(9, mimic_strlen("0123456789", 9));
}
TEST(TestFuncGroup, mimic_tcslen_0)
{
    CHECK_EQUAL(0, mimic_tcslen(_T(""), 1));
}
TEST(TestFuncGroup, mimic_tcslen_1)
{
    CHECK_EQUAL(1, mimic_tcslen(_T("1"), 2));
}
TEST(TestFuncGroup, mimic_tcslen_10)
{
    CHECK_EQUAL(10, mimic_tcslen(_T("0123456789"), 11));
}
TEST(TestFuncGroup, mimic_tcslen_9)
{
    CHECK_EQUAL(9, mimic_tcslen(_T("0123456789"), 9));
}
// strlen - end
// memcmp - start
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
// memcmp - end 
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



TEST(TestFuncGroup, mimic_sprintf_HelloWorld_OK)
{
    char szStr[512];

    std::cout << "mimic_sprintf == \"Hello World\" OKTest" << std::endl;
    mimic_sprintf(szStr, sizeof(szStr), "Hello World");
    STRNCMP_EQUAL("Hello World", szStr, strlen("Hello World"));
}
TEST(TestFuncGroup, mimic_sprintf_HelloWorld_NG)
{
    char szStr[512];

    memset(szStr, 0, sizeof(szStr));
    std::cout << "mimic_sprintf != \"Hello World\" NG Test" << std::endl;
    mimic_sprintf(szStr, sizeof(szStr), "hello World");
    STRCMP_NOCASE_EQUAL("Hello World", szStr);
}
TEST(TestFuncGroup, mimic_sprintf_Float)
{
    char szStr[512];

    memset(szStr, 0, sizeof(szStr));
    std::cout << "mimic_sprintf == \"1.23456\" OKTest" << std::endl;
    mimic_sprintf(szStr, sizeof(szStr), "%d %d %u %.5f", INT32_MIN, INT32_MAX, UINT32_MAX, 1.23456);

    std::cout << szStr << std::endl;
    STRCMP_EQUAL("-2147483648 2147483647 4294967295 1.23456", szStr);
}
TEST(TestFuncGroup, mimic_sprintf_Zerofill)
{
    char szStr[512];

    memset(szStr, 0, sizeof(szStr));
    std::cout << "mimic_sprintf == \"1.23456\" OKTest" << std::endl;
    mimic_sprintf(szStr, sizeof(szStr), "%016X", 0xFFFFFFFF);

    std::cout << szStr << std::endl;
    STRCMP_EQUAL("00000000FFFFFFFF", szStr);
}

TEST(TestFuncGroup, mimic_sprintf_left)
{
    char szStr[512];

    memset(szStr, 0, sizeof(szStr));
    std::cout << "mimic_sprintf_left" << std::endl;
    mimic_sprintf(szStr, sizeof(szStr), "%20s", "test");

    std::cout << szStr << std::endl;
    STRCMP_EQUAL("test                ", szStr);
}
TEST(TestFuncGroup, mimic_sprintf_right)
{
    char szStr[512];

    memset(szStr, 0, sizeof(szStr));
    std::cout << "mimic_sprintf_right" << std::endl;
    mimic_sprintf(szStr, sizeof(szStr), "%-20s", "test");

    std::cout << szStr << std::endl;
    STRCMP_EQUAL("                test", szStr);
}
TEST(TestFuncGroup, mimic_ftoa_1_2)
{
    char szStr[512];

    std::cout << "mimic_ftoa == \"1.2\" OKTest" << std::endl;
    mimic_ftoa(1.2, szStr, sizeof(szStr), 1);

    STRNCMP_EQUAL("1.2", szStr, 3);
}
TEST(TestFuncGroup, mimic_atof_OK_12_3456789)
{
    std::cout << "mimic_atof(\"12.3456789\", 10) == \"12.3456789\" OKTest" << std::endl;

    DOUBLES_EQUAL(12.3456789, mimic_atof("12.3456789", 10), 0.0000001);
}
TEST(TestFuncGroup, mimic_atof_OK2)
{
    std::cout << "mimic_atof(\"100.000000\", 10) == \"100.000000\" OKTest" << std::endl;

    DOUBLES_EQUAL(100.000000, mimic_atof("100.000000", 10), 0.0000001);
}

TEST(TestFuncGroup, mimic_strtol_INT32_MAX)
{
    std::cout << "mimic_strtol_INT32_MAX" << std::endl;
    LONGS_EQUAL(INT32_MAX, mimic_strtol("2147483647", strlen("2147483647")));
}
TEST(TestFuncGroup, mimic_strtol_INT32_MIN)
{
    std::cout << "mimic_strtol_INT32_MIN" << std::endl;
    LONGS_EQUAL(INT32_MIN, mimic_strtol("-2147483648", strlen("-2147483648")));
}
TEST(TestFuncGroup, mimic_strtol_INT32_0)
{
    std::cout << "mimic_strtol_INT32_0" << std::endl;
    LONGS_EQUAL(0, mimic_strtol("0", strlen("0")));
}
TEST(TestFuncGroup, mimic_strtol_INT32_p1)
{
    std::cout << "mimic_strtol_INT32_p1" << std::endl;
    LONGS_EQUAL(1, mimic_strtol("1", strlen("1")));
}
TEST(TestFuncGroup, mimic_strtol_INT32_m1)
{
    std::cout << "mimic_strtol_INT32_m1" << std::endl;
    LONGS_EQUAL(-1, mimic_strtol("-1", strlen("-1")));
}


TEST(TestFuncGroup, mimic_strtoll_INT64_MAX)
{
    std::cout << "mimic_strtol_INT64_MAX" << std::endl;
    LONGLONGS_EQUAL(INT64_MAX, mimic_strtoll("9223372036854775807", strlen("9223372036854775807")));
}
TEST(TestFuncGroup, mimic_strtoll_INT64_MIN)
{
    std::cout << "mimic_strtol_INT64_MIN" << std::endl;
    LONGLONGS_EQUAL(INT64_MIN, mimic_strtoll("-9223372036854775808", strlen("-9223372036854775808")));
}
TEST(TestFuncGroup, mimic_strtoll_INT64_0)
{
    std::cout << "mimic_strtol_INT64_0" << std::endl;
    LONGLONGS_EQUAL(0ll, mimic_strtoll("0", strlen("0")));
}
TEST(TestFuncGroup, mimic_strtoll_INT64_p1)
{
    std::cout << "mimic_strtol_INT64_p1" << std::endl;
    LONGLONGS_EQUAL(1ll, mimic_strtoll("1", strlen("1")));
}
TEST(TestFuncGroup, mimic_strtoll_INT64_m1)
{
    std::cout << "mimic_strtol_INT64_m1" << std::endl;
    LONGLONGS_EQUAL(-1ll, mimic_strtoll("-1", strlen("-1")));
}


TEST(TestFuncGroup, mimic_strtoul_UINT32_MAX)
{
    std::cout << "mimic_strtoul_UINT32_MAX" << std::endl;
    UNSIGNED_LONGS_EQUAL(UINT32_MAX, mimic_strtoul("4294967295", strlen("4294967295"), 10));
}
TEST(TestFuncGroup, mimic_strtoul_UINT32_MAX_Hex)
{
    std::cout << "mimic_strtoul_UINT32_MAX_Hex" << std::endl;
    UNSIGNED_LONGS_EQUAL(UINT32_MAX, mimic_strtoul("FFFFFFFF", strlen("FFFFFFFF"), 16));
}
TEST(TestFuncGroup, mimic_strtoul_UINT32_0)
{
    std::cout << "mimic_strtoul_UINT32_0" << std::endl;
    UNSIGNED_LONGS_EQUAL(0u, mimic_strtoul("0", strlen("0"), 10));
}
TEST(TestFuncGroup, mimic_strtoul_UINT32_p1)
{
    std::cout << "mimic_strtoul_UINT32_p1" << std::endl;
    UNSIGNED_LONGS_EQUAL(1u, mimic_strtoul("1", strlen("1"), 10));
}

TEST(TestFuncGroup, mimic_strtoull_UINT64_MAX)
{
    std::cout << "mimic_strtoull_UINT64_MAX" << std::endl;
    UNSIGNED_LONGLONGS_EQUAL(UINT64_MAX, mimic_strtoull("18446744073709551615", strlen("18446744073709551615"), 10));
}
TEST(TestFuncGroup, mimic_strtoull_UINT64_MAX_Hex)
{
    std::cout << "mimic_strtoull_UINT64_MAX_Hex" << std::endl;
    UNSIGNED_LONGLONGS_EQUAL(UINT64_MAX, mimic_strtoull("FFFFFFFFFFFFFFFF", strlen("FFFFFFFFFFFFFFFF"), 16));
}
TEST(TestFuncGroup, mimic_strtoull_UINT64_0)
{
    std::cout << "mimic_strtoull_UINT64_0" << std::endl;
    UNSIGNED_LONGLONGS_EQUAL(0ull, mimic_strtoull("0", strlen("0"), 10));
}
TEST(TestFuncGroup, mimic_strtoull_UINT64_p1)
{
    std::cout << "mimic_strtoull_UINT64_p1" << std::endl;
    UNSIGNED_LONGLONGS_EQUAL(1ull, mimic_strtoull("1", strlen("1"), 10));
}

TEST(TestFuncGroup, mimic_strupper_OK)
{
    char szStr[] = {'a', 'b', 'c', 'd', 'e','\0'};
    std::cout << "mimic_strupper_OK" << std::endl;
    STRCMP_EQUAL("ABCDE", mimic_strupper(szStr));
}
TEST(TestFuncGroup, mimic_strupper_NG)
{
    std::cout << "mimic_strupper_NG" << std::endl;
    CHECK_EQUAL(NULL, mimic_strupper(NULL));
}
TEST(TestFuncGroup, mimic_tcslowwer_OK)
{
    char szStr[] = {'A', 'B', 'C', 'D', 'E','\0'};
    std::cout << "mimic_tcslowwer_OK" << std::endl;
    STRCMP_EQUAL("abcde", mimic_tcslowwer(szStr));
}
TEST(TestFuncGroup, mimic_tcslowwer_NG)
{
    std::cout << "mimic_tcslowwer_NG" << std::endl;
    CHECK_EQUAL(NULL, mimic_tcslowwer(NULL));
}


TEST(TestFuncGroup, mimic_strtok)
{
    std::cout << "mimic_strtok" << std::endl;

    char szStr[256];
    char *ctx;
    mimic_strcpy(szStr, "ABC 123456\r\n", sizeof(szStr));

    STRCMP_EQUAL("ABC", mimic_strtok(szStr, sizeof(szStr), " " , sizeof(" "), &ctx));
    STRCMP_EQUAL("123456\r\n", mimic_strtok(NULL, sizeof(szStr), " " , sizeof(" "), &ctx));
    CHECK_EQUAL(NULL, mimic_strtok(NULL, sizeof(szStr), " " , sizeof(" "), &ctx));
    
}
