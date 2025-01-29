//
// Created by Mi on 02.01.2024.
//

#include "check_s21_strerror.h"

#include <errno.h>
#include <string.h>

#include "../../s21_string.h"
#include "../common.h"

char *unknown_err_msg = "Unknown error";

START_TEST(test_strerror_known_error) {
  int errnum = EINVAL;

  const char *result_s21 = s21_strerror(errnum);
  const char *result_strerror = strerror(errnum);

  ck_assert_str_eq(result_s21, result_strerror);
}
END_TEST

START_TEST(test_strerror_unknown_error) {
  int errnum = 9999;

  const char *result_s21 = s21_strerror(errnum);

  ck_assert_msg(
      strncmp(result_s21, unknown_err_msg, strlen(unknown_err_msg)) == 0,
      "String does not start with the expected value");
}
END_TEST

START_TEST(test_strerror_zero_error) {
  int errnum = 0;

  const char *result_s21 = s21_strerror(errnum);
  const char *result_strerror = strerror(errnum);

  ck_assert_str_eq(result_s21, result_strerror);
}
END_TEST

START_TEST(test_strerror_negative_error) {
  int errnum = -EINVAL;

  const char *result_s21 = s21_strerror(errnum);

  ck_assert_msg(
      strncmp(result_s21, unknown_err_msg, strlen(unknown_err_msg)) == 0,
      "String does not start with the expected value");
}
END_TEST

START_TEST(test_strerror_positive_error) {
  int errnum = EACCES;

  const char *result_s21 = s21_strerror(errnum);
  const char *result_strerror = strerror(errnum);

  ck_assert_str_eq(result_s21, result_strerror);
}
END_TEST

Suite *strerror_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strerror");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_strerror_known_error);
  tcase_add_test(tc_core, test_strerror_unknown_error);
  tcase_add_test(tc_core, test_strerror_zero_error);
  tcase_add_test(tc_core, test_strerror_negative_error);
  tcase_add_test(tc_core, test_strerror_positive_error);

  suite_add_tcase(s, tc_core);

  return s;
}