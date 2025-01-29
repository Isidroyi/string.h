//
// Created by Mi on 02.01.2024.
//

#include "check_s21_strstr.h"

#include <string.h>

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_strstr_substring_found) {
  const char *haystack = "Hello, World!";
  const char *needle = "World";

  char *result_s21 = s21_strstr(haystack, needle);
  char *result_strstr = strstr(haystack, needle);

  ck_assert_ptr_eq(result_s21, result_strstr);

  if (result_s21 != NULL) {
    ck_assert_str_eq(result_s21, result_strstr);
  }
}
END_TEST

START_TEST(test_strstr_substring_not_found) {
  const char *haystack = "Hello, World!";
  const char *needle = "Universe";

  char *result_s21 = s21_strstr(haystack, needle);
  char *result_strstr = strstr(haystack, needle);

  ck_assert_ptr_eq(result_s21, result_strstr);
}
END_TEST

START_TEST(test_strstr_empty_needle) {
  const char *haystack = "Hello, World!";
  const char *needle = "";

  char *result_s21 = s21_strstr(haystack, needle);
  char *result_strstr = strstr(haystack, needle);

  ck_assert_ptr_eq(result_s21, result_strstr);

  if (result_s21 != NULL) {
    ck_assert_str_eq(result_s21, haystack);
  }
}
END_TEST

START_TEST(test_strstr_empty_haystack) {
  const char *haystack = "";
  const char *needle = "World";

  char *result_s21 = s21_strstr(haystack, needle);
  char *result_strstr = strstr(haystack, needle);

  ck_assert_ptr_eq(result_s21, result_strstr);
  ck_assert_ptr_null(result_s21);
}
END_TEST

START_TEST(test_strstr_multiple_occurrences) {
  const char *haystack = "Hello, Hello, World!";
  const char *needle = "Hello";

  char *result_s21 = s21_strstr(haystack, needle);
  char *result_strstr = strstr(haystack, needle);

  ck_assert_ptr_eq(result_s21, result_strstr);

  if (result_s21 != NULL) {
    ck_assert_str_eq(result_s21, result_strstr);
  }
}
END_TEST

START_TEST(test_str_and_sbstr_eq) {
  const char *haystack = "Hello";
  const char *needle = "Hello";

  char *result_s21 = s21_strstr(haystack, needle);
  char *result_strstr = strstr(haystack, needle);

  ck_assert_ptr_eq(result_s21, result_strstr);

  if (result_s21 != NULL) {
    ck_assert_str_eq(result_s21, result_strstr);
  }
}
END_TEST

START_TEST(test_partially_eq) {
  const char *haystack = "Hello";
  const char *needle = "Hola";

  char *result_s21 = s21_strstr(haystack, needle);
  char *result_strstr = strstr(haystack, needle);

  ck_assert_ptr_eq(result_s21, result_strstr);

  if (result_s21 != NULL) {
    ck_assert_str_eq(result_s21, result_strstr);
  }
}
END_TEST

Suite *strstr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strstr");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_strstr_substring_found);
  tcase_add_test(tc_core, test_strstr_substring_not_found);
  tcase_add_test(tc_core, test_strstr_empty_needle);
  tcase_add_test(tc_core, test_strstr_empty_haystack);
  tcase_add_test(tc_core, test_strstr_multiple_occurrences);
  tcase_add_test(tc_core, test_str_and_sbstr_eq);
  tcase_add_test(tc_core, test_partially_eq);

  suite_add_tcase(s, tc_core);

  return s;
}