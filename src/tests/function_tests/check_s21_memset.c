//
// Created by Mi on 03.01.2024.
//

#include "check_s21_memset.h"

#include <string.h>

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_normal_string) {
  char str1[20] = "Hello, World!";
  char str2[20] = "Hello, World!";

  ck_assert_str_eq(s21_memset(str1, 'a', strlen(str1)),
                   memset(str2, 'a', strlen(str2)));
}
END_TEST

START_TEST(test_empty_string) {
  ck_assert_str_eq(s21_memset("", '!', strlen("")),
                   memset("", '!', strlen("")));
}
END_TEST

START_TEST(test_null_ptr) { ck_assert_ptr_null(s21_memset(NULL, '0', 0)); }
END_TEST

Suite *memset_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memset");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_normal_string);
  tcase_add_test(tc_core, test_empty_string);
  tcase_add_test(tc_core, test_null_ptr);

  suite_add_tcase(s, tc_core);

  return s;
}