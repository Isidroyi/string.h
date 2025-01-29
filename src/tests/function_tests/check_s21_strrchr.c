//
// Created by Mi on 02.01.2024.
//

#include "check_s21_strrchr.h"

#include <string.h>

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_strrchr_character_found) {
  const char *str = "Hello, World!";
  int ch = 'o';

  char *result_s21 = s21_strrchr(str, ch);
  char *result_strrchr = strrchr(str, ch);

  ck_assert_ptr_eq(result_s21, result_strrchr);

  if (result_s21 != NULL) {
    ck_assert_int_eq(*result_s21, *result_strrchr);
  }
}
END_TEST

START_TEST(test_strrchr_character_not_found) {
  const char *str = "Hello, World!";
  int ch = 'z';

  char *result_s21 = s21_strrchr(str, ch);
  char *result_strrchr = strrchr(str, ch);

  ck_assert_ptr_eq(result_s21, result_strrchr);
}
END_TEST

START_TEST(test_strrchr_null_character) {
  const char *str = "Hello, World!";
  int ch = '\0';

  char *result_s21 = s21_strrchr(str, ch);
  char *result_strrchr = strrchr(str, ch);

  ck_assert_ptr_eq(result_s21, result_strrchr);

  if (result_s21 != NULL) {
    ck_assert_int_eq(*result_s21, *result_strrchr);
  }
}
END_TEST

START_TEST(test_strrchr_empty_str) {
  const char *str = "";
  int ch = 'o';

  char *result_s21 = s21_strrchr(str, ch);
  char *result_strrchr = strrchr(str, ch);

  ck_assert_ptr_eq(result_s21, result_strrchr);
  ck_assert_ptr_null(result_s21);
}
END_TEST

START_TEST(test_strrchr_multiple_occurrences_null_character) {
  const char *str = "Hello, World!";
  int ch = '\0';

  char *result_s21 = s21_strrchr(str, ch);
  char *result_strrchr = strrchr(str, ch);

  ck_assert_ptr_eq(result_s21, result_strrchr);

  if (result_s21 != NULL) {
    ck_assert_int_eq(*result_s21, *result_strrchr);
  }
}
END_TEST

Suite *strrchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strrchr");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_strrchr_character_found);
  tcase_add_test(tc_core, test_strrchr_character_not_found);
  tcase_add_test(tc_core, test_strrchr_null_character);
  tcase_add_test(tc_core, test_strrchr_empty_str);
  tcase_add_test(tc_core, test_strrchr_multiple_occurrences_null_character);

  suite_add_tcase(s, tc_core);

  return s;
}