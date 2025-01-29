//
// Created by Mi on 02.01.2024.
//

#include "check_s21_strcspn.h"

#include <string.h>

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_strcspn_matching_characters) {
  const char *str1 = "Hello, World!";
  const char *str2 = " ,!";

  size_t result_s21 = s21_strcspn(str1, str2);
  size_t result_strcspn = strcspn(str1, str2);

  ck_assert_int_eq(result_s21, result_strcspn);
}
END_TEST

START_TEST(test_strcspn_no_matching_characters) {
  const char *str1 = "Hello, World!";
  const char *str2 = "123";

  size_t result_s21 = s21_strcspn(str1, str2);
  size_t result_strcspn = strcspn(str1, str2);

  ck_assert_int_eq(result_s21, result_strcspn);
}
END_TEST

START_TEST(test_strcspn_empty_str2) {
  const char *str1 = "Hello, World!";
  const char *str2 = "";

  size_t result_s21 = s21_strcspn(str1, str2);
  size_t result_strcspn = strcspn(str1, str2);

  ck_assert_int_eq(result_s21, result_strcspn);
}
END_TEST

START_TEST(test_strcspn_empty_str1) {
  const char *str1 = "";
  const char *str2 = " ,!";

  size_t result_s21 = s21_strcspn(str1, str2);
  size_t result_strcspn = strcspn(str1, str2);

  ck_assert_int_eq(result_s21, result_strcspn);
}
END_TEST

Suite *strcspn_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strcspn");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_strcspn_matching_characters);
  tcase_add_test(tc_core, test_strcspn_no_matching_characters);
  tcase_add_test(tc_core, test_strcspn_empty_str2);
  tcase_add_test(tc_core, test_strcspn_empty_str1);

  suite_add_tcase(s, tc_core);

  return s;
}