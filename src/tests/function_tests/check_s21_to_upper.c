#include "check_s21_to_upper.h"

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_to_upper_null_input) {
  const char *result_s21 = s21_to_upper(NULL);
  ck_assert_ptr_null(result_s21);
}
END_TEST

START_TEST(test_to_upper_empty_string) {
  const char *input = "";
  const char *result_s21 = s21_to_upper(input);
  ck_assert_str_eq(result_s21, "");
}
END_TEST

START_TEST(test_to_upper_all_lowercase) {
  const char *input = "hello, world!";
  const char *result_s21 = s21_to_upper(input);
  ck_assert_str_eq(result_s21, "HELLO, WORLD!");
}
END_TEST

START_TEST(test_to_upper_all_uppercase) {
  const char *input = "HELLO, WORLD!";
  const char *result_s21 = s21_to_upper(input);
  ck_assert_str_eq(result_s21, "HELLO, WORLD!");
}
END_TEST

START_TEST(test_to_upper_mixed_case) {
  const char *input = "HeLLo, WoRLd!";
  const char *result_s21 = s21_to_upper(input);
  ck_assert_str_eq(result_s21, "HELLO, WORLD!");
}
END_TEST

Suite *to_upper_suite(void) {
  Suite *s;
  TCase *tc_to_upper;

  s = suite_create("to_upper");

  tc_to_upper = tcase_create("to_upper");

  tcase_add_test(tc_to_upper, test_to_upper_null_input);
  tcase_add_test(tc_to_upper, test_to_upper_empty_string);
  tcase_add_test(tc_to_upper, test_to_upper_all_lowercase);
  tcase_add_test(tc_to_upper, test_to_upper_all_uppercase);
  tcase_add_test(tc_to_upper, test_to_upper_mixed_case);

  suite_add_tcase(s, tc_to_upper);

  return s;
}
