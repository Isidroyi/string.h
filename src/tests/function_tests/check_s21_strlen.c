//
// Created by Tanesha Morna on 24.12.2023.
//

#include "check_s21_strlen.h"

#include <string.h>

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_normal_string) {
  ck_assert_int_eq(s21_strlen(normal_string), strlen(normal_string));
}

END_TEST

START_TEST(test_empty) { ck_assert_int_eq(s21_strlen(""), strlen("")); }

END_TEST

START_TEST(test_single_char) { ck_assert_int_eq(s21_strlen("A"), strlen("A")); }

END_TEST

START_TEST(test_whitespace_string) {
  ck_assert_int_eq(s21_strlen(whitespace_string), strlen(whitespace_string));
}

END_TEST

START_TEST(test_special_chars) {
  ck_assert_int_eq(s21_strlen(special_chars), strlen(special_chars));
}

END_TEST

START_TEST(test_large_string) {
  ck_assert_int_eq(s21_strlen(large_string), strlen(large_string));
}

END_TEST

START_TEST(test_strlen_embedded_null) {
  const char *str = "Hello\0World!";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_long_string) {
  ck_assert_int_eq(s21_strlen(large_string), strlen(large_string));
}
END_TEST

Suite *strlen_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strlen");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_normal_string);
  tcase_add_test(tc_core, test_empty);
  tcase_add_test(tc_core, test_single_char);
  tcase_add_test(tc_core, test_whitespace_string);
  tcase_add_test(tc_core, test_special_chars);
  tcase_add_test(tc_core, test_large_string);
  tcase_add_test(tc_core, test_strlen_embedded_null);
  tcase_add_test(tc_core, test_strlen_long_string);

  suite_add_tcase(s, tc_core);

  return s;
}