//
// Created by Mi on 02.01.2024.
//

#include "check_s21_strpbrk.h"

#include <string.h>

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_strpbrk_character_found) {
  const char *str1 = "Hello, World!";
  const char *str2 = " ,!";

  char *result_s21 = s21_strpbrk(str1, str2);
  char *result_strpbrk = strpbrk(str1, str2);

  ck_assert_ptr_eq(result_s21, result_strpbrk);
}
END_TEST

START_TEST(test_strpbrk_character_not_found) {
  const char *str1 = "Hello, World!";
  const char *str2 = "123";

  char *result_s21 = s21_strpbrk(str1, str2);
  char *result_strpbrk = strpbrk(str1, str2);

  ck_assert_ptr_eq(result_s21, result_strpbrk);
}
END_TEST

START_TEST(test_strpbrk_empty_str2) {
  const char *str1 = "Hello, World!";
  const char *str2 = "";

  char *result_s21 = s21_strpbrk(str1, str2);
  char *result_strpbrk = strpbrk(str1, str2);

  ck_assert_ptr_eq(result_s21, result_strpbrk);
  ck_assert_ptr_null(result_s21);
}
END_TEST

START_TEST(test_strpbrk_empty_str1) {
  const char *str1 = "";
  const char *str2 = " ,!";

  char *result_s21 = s21_strpbrk(str1, str2);
  char *result_strpbrk = strpbrk(str1, str2);

  ck_assert_ptr_eq(result_s21, result_strpbrk);
  ck_assert_ptr_null(result_s21);
}
END_TEST

START_TEST(test_strpbrk_multiple_occurrences) {
  const char *str1 = "Hello, World!";
  const char *str2 = "l,";

  char *result_s21 = s21_strpbrk(str1, str2);
  char *result_strpbrk = strpbrk(str1, str2);

  ck_assert_ptr_eq(result_s21, result_strpbrk);
  ck_assert_ptr_ne(result_s21, NULL);
  ck_assert_int_eq(result_s21 - str1, result_strpbrk - str1);
}
END_TEST

START_TEST(test_strpbrk_both_empty) {
  const char *str1 = "";
  const char *str2 = "";

  char *result_s21 = s21_strpbrk(str1, str2);
  char *result_strpbrk = strpbrk(str1, str2);

  ck_assert_ptr_eq(result_s21, result_strpbrk);
  ck_assert_ptr_null(result_s21);
}
END_TEST

Suite *strpbrk_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strpbrk");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_strpbrk_character_found);
  tcase_add_test(tc_core, test_strpbrk_character_not_found);
  tcase_add_test(tc_core, test_strpbrk_empty_str2);
  tcase_add_test(tc_core, test_strpbrk_empty_str1);
  tcase_add_test(tc_core, test_strpbrk_multiple_occurrences);
  tcase_add_test(tc_core, test_strpbrk_both_empty);

  suite_add_tcase(s, tc_core);

  return s;
}