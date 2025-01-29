#include "check_s21_to_lower.h"

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_s21_to_lower_basic) {
  const char *input = "Hello, World!";
  const char *result = s21_to_lower(input);

  const char *expected = "hello, world!";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_to_lower_empty_string) {
  const char *input = "";
  const char *result = s21_to_lower(input);

  const char *expected = "";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_to_lower_mixed_case) {
  const char *input = "MiXeD CaSe";
  const char *result = s21_to_lower(input);

  const char *expected = "mixed case";
  ck_assert_str_eq(result, expected);
}
END_TEST

Suite *to_lower_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("to_lower");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_to_lower_basic);
  tcase_add_test(tc_core, test_s21_to_lower_empty_string);
  tcase_add_test(tc_core, test_s21_to_lower_mixed_case);

  suite_add_tcase(s, tc_core);

  return s;
}