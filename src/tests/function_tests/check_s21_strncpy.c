//
// Created by Mi on 02.01.2024.
//

#include "check_s21_strncpy.h"

#include <string.h>

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_strncpy_copy_full_string) {
  char s21_destination[20] = "";
  char destination[20] = "";
  const char *source = "Hello, strncpy!";
  size_t n = strlen(source);

  ck_assert_str_eq(s21_strncpy(s21_destination, source, n),
                   strncpy(destination, source, n));
}
END_TEST

START_TEST(test_strncpy_copy_partial_string) {
  char s21_destination[20] = "";
  char destination[20] = "";
  const char *source = "Hello, strncpy!";
  size_t n = 5;

  ck_assert_mem_eq(s21_strncpy(s21_destination, source, n),
                   strncpy(destination, source, n), strlen(destination));
}
END_TEST

START_TEST(test_strncpy_copy_empty_string) {
  char s21_destination[20] = "";
  char destination[20] = "";
  const char *source = "";
  size_t n = strlen(source);

  ck_assert_mem_eq(s21_strncpy(s21_destination, source, n),
                   strncpy(destination, source, n), strlen(destination));
}
END_TEST

START_TEST(test_strncpy_copy_zero_length) {
  char s21_destination[20] = "";
  char destination[20] = "";
  const char *source = "Hello, strncpy!";

  ck_assert_mem_eq(s21_strncpy(s21_destination, source, 0), "",
                   strlen(destination));
}
END_TEST

START_TEST(test_strncpy_copy_null_terminated_source) {
  char s21_destination[20];
  char destination[20];
  const char *source = "Hello, strncpy!";
  size_t n = strlen(source) + 1;

  ck_assert_str_eq(s21_strncpy(s21_destination, source, n),
                   strncpy(destination, source, n));
}
END_TEST

Suite *strncpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncpy");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_strncpy_copy_full_string);
  tcase_add_test(tc_core, test_strncpy_copy_partial_string);
  tcase_add_test(tc_core, test_strncpy_copy_empty_string);
  tcase_add_test(tc_core, test_strncpy_copy_zero_length);
  tcase_add_test(tc_core, test_strncpy_copy_null_terminated_source);

  suite_add_tcase(s, tc_core);

  return s;
}