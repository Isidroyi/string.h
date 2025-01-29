//
// Created by Mi on 02.01.2024.
//

#include "check_s21_strncmp.h"

#include <string.h>

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_strncmp_equal_strings) {
  const char *str1 = "Hello, world!";
  const char *str2 = "Hello, world!";
  size_t n = strlen(str1);

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_different_strings) {
  const char *str1 = "Hello, world!";
  const char *str2 = "Hola, mundo!";
  size_t n = strlen(str1);

  ck_assert(s21_strncmp(str1, str2, n) < 0);
}
END_TEST

START_TEST(test_strncmp_partial_strings_equal) {
  const char *str1 = "Hello, world!";
  const char *str2 = "Hello, wonderful world!";
  size_t n = 7;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_partial_strings_different) {
  const char *str1 = "Hello, world!";
  const char *str2 = "Hola, wonderful world!";
  size_t n = 7;

  ck_assert(s21_strncmp(str1, str2, n) < 0);
}
END_TEST

START_TEST(test_strncmp_zero_length) {
  const char *str1 = "Hello, world!";
  const char *str2 = "Hola, mundo!";

  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
}
END_TEST

START_TEST(test_strncmp_equal_strings_large_n) {
  const char *str1 = "Hello, world!";
  const char *str2 = "Hello, world!";
  size_t n = strlen(str1) + 10;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_equal_strings_small_n) {
  const char *str1 = "Hello, world!";
  const char *str2 = "Hello, world!";
  size_t n = 5;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_empty_strings) {
  const char *str1 = "";
  const char *str2 = "";
  size_t n = 5;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite *strncmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncmp");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_strncmp_equal_strings);
  tcase_add_test(tc_core, test_strncmp_different_strings);
  tcase_add_test(tc_core, test_strncmp_partial_strings_equal);
  tcase_add_test(tc_core, test_strncmp_partial_strings_different);
  tcase_add_test(tc_core, test_strncmp_zero_length);
  tcase_add_test(tc_core, test_strncmp_equal_strings_large_n);
  tcase_add_test(tc_core, test_strncmp_equal_strings_small_n);
  tcase_add_test(tc_core, test_strncmp_empty_strings);

  suite_add_tcase(s, tc_core);

  return s;
}
