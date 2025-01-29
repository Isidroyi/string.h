//
// Created by Tanesha Morna on 24.12.2023.
//

#include "check_s21_strchr.h"

#include <string.h>

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_normal_string) {
  ck_assert_str_eq(s21_strchr(normal_string, 'u'), strchr(normal_string, 'u'));
}
END_TEST

START_TEST(test_no_letter) {
  ck_assert_ptr_null(s21_strchr(normal_string, 'f'));
}
END_TEST

START_TEST(test_empty_string) { ck_assert_ptr_null(s21_strchr("", 'a')); }
END_TEST

START_TEST(test_first_char) {
  ck_assert_str_eq(s21_strchr(normal_string, 'L'), strchr(normal_string, 'L'));
}
END_TEST

START_TEST(test_last_char) {
  ck_assert_str_eq(s21_strchr(normal_string, '.'), strchr(normal_string, '.'));
}
END_TEST

START_TEST(test_multiple_occurrences) {
  ck_assert_str_eq(s21_strchr(normal_string, 'e'), strchr(normal_string, 'e'));
}
END_TEST

START_TEST(test_find_null_character) {
  const char *str = "Hello\0World!";
  char character = '\0';

  ck_assert_str_eq(s21_strchr(str, character), strchr(str, character));
}
END_TEST

START_TEST(test_find_after_null_character) {
  const char *str = "Hello\0World!";
  char character = 'W';

  ck_assert_ptr_null(s21_strchr(str, character));
}
END_TEST

Suite *strchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strchr");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_normal_string);
  tcase_add_test(tc_core, test_no_letter);
  tcase_add_test(tc_core, test_empty_string);
  tcase_add_test(tc_core, test_first_char);
  tcase_add_test(tc_core, test_last_char);
  tcase_add_test(tc_core, test_multiple_occurrences);
  tcase_add_test(tc_core, test_find_null_character);
  tcase_add_test(tc_core, test_find_after_null_character);

  suite_add_tcase(s, tc_core);

  return s;
}