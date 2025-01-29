//
// Created by Mi on 02.01.2024.
//

#include "check_s21_strtok.h"

#include <string.h>

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_strtok_basic) {
  char str[] = "Hello, World!";
  const char delimiters[] = " ,!";

  char *result_s21 = s21_strtok(str, delimiters);
  char *result_strtok = strtok(str, delimiters);

  ck_assert_ptr_eq(result_s21, result_strtok);

  if (result_s21 != NULL) {
    ck_assert_str_eq(result_s21, result_strtok);
  }
}
END_TEST

START_TEST(test_strtok_multiple_calls) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World!";
  const char delimiters[] = " ,!";

  char *result_s21_1 = s21_strtok(str1, delimiters);
  char *result_strtok_1 = strtok(str2, delimiters);

  char *result_s21_2 = s21_strtok(NULL, delimiters);
  char *result_strtok_2 = strtok(NULL, delimiters);

  if (result_s21_1 != NULL) {
    ck_assert_str_eq(result_s21_1, result_strtok_1);
  }

  if (result_s21_2 != NULL) {
    ck_assert_str_eq(result_s21_2, result_strtok_2);
  }
}
END_TEST

START_TEST(test_strtok_empty_string) {
  char str[] = "";
  const char delimiters[] = " ,!";

  char *result_s21 = s21_strtok(str, delimiters);
  char *result_strtok = strtok(str, delimiters);

  ck_assert_ptr_eq(result_s21, result_strtok);
  ck_assert_ptr_null(result_s21);
}
END_TEST

START_TEST(test_strtok_multiple_delimiters) {
  char str1[] = "Hello,  World!";
  char str2[] = "Hello,  World!";
  const char delimiters[] = " ,!";

  char *result_s21 = s21_strtok(str1, delimiters);
  char *result_strtok = strtok(str2, delimiters);

  if (result_s21 != NULL) {
    ck_assert_str_eq(result_s21, result_strtok);
  }
}
END_TEST

START_TEST(test_strtok_no_delimiters) {
  char str[] = "Hello,World!";
  const char delimiters[] = " ,!";

  char *result_s21 = s21_strtok(str, delimiters);
  char *result_strtok = strtok(str, delimiters);

  ck_assert_ptr_eq(result_s21, result_strtok);

  if (result_s21 != NULL) {
    ck_assert_str_eq(result_s21, result_strtok);
  }
}
END_TEST

START_TEST(test_strtok_null_str) {
  const char delimiters[] = " ,!";

  char *result_s21 = s21_strtok(NULL, delimiters);

  ck_assert_ptr_null(result_s21);
}
END_TEST

Suite *strtok_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strtok");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_strtok_basic);
  tcase_add_test(tc_core, test_strtok_multiple_calls);
  tcase_add_test(tc_core, test_strtok_empty_string);
  tcase_add_test(tc_core, test_strtok_multiple_delimiters);
  tcase_add_test(tc_core, test_strtok_no_delimiters);
  tcase_add_test(tc_core, test_strtok_null_str);

  suite_add_tcase(s, tc_core);

  return s;
}