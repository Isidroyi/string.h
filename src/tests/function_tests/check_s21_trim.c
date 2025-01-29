#include "../../s21_string.h"
#include "../common.h"
#include "check_s21_to_upper.h"

START_TEST(test_s21_trim_basic) {
  const char *original = "   Hello, World!   ";
  const char *trim_chars = " ";

  char *result = s21_trim(original, trim_chars);

  const char *expected = "Hello, World!";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_trim_no_trim) {
  const char *original = "Hello, World!";
  const char *trim_chars = " ";

  char *result = s21_trim(original, trim_chars);

  const char *expected = "Hello, World!";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_trim_empty_original) {
  const char *original = "";
  const char *trim_chars = " ";

  char *result = s21_trim(original, trim_chars);

  const char *expected = "";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_trim_empty_trim_chars) {
  const char *original = "   Hello, World!   ";
  const char *trim_chars = "";

  char *result = s21_trim(original, trim_chars);

  const char *expected = "   Hello, World!   ";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_trim_multiple_trim_chars) {
  const char *original = "12345Hello, World!54321";
  const char *trim_chars = "12345";

  char *result = s21_trim(original, trim_chars);

  const char *expected = "Hello, World!";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_trim_no_trim_chars) {
  const char *original = "   Hello, World!   ";
  const char *trim_chars = "";

  char *result = s21_trim(original, trim_chars);

  const char *expected = "   Hello, World!   ";
  ck_assert_str_eq(result, expected);
}
END_TEST

Suite *trim_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("trim");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_trim_basic);
  tcase_add_test(tc_core, test_s21_trim_no_trim);
  tcase_add_test(tc_core, test_s21_trim_empty_original);
  tcase_add_test(tc_core, test_s21_trim_empty_trim_chars);
  tcase_add_test(tc_core, test_s21_trim_multiple_trim_chars);
  tcase_add_test(tc_core, test_s21_trim_no_trim_chars);

  suite_add_tcase(s, tc_core);

  return s;
}