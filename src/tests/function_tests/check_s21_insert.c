#include "../../s21_string.h"
#include "../common.h"
#include "check_s21_to_upper.h"

START_TEST(test_s21_insert_basic) {
  const char *original = "Hello, World!";
  const char *insert_str = "beautiful ";
  size_t start_index = 7;
  char *result = s21_insert(original, insert_str, start_index);

  const char *expected = "Hello, beautiful World!";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_insert_at_beginning) {
  const char *original = "World!";
  const char *insert_str = "Hello, ";
  size_t start_index = 0;
  char *result = s21_insert(original, insert_str, start_index);

  const char *expected = "Hello, World!";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_insert_at_end) {
  const char *original = "Hello, ";
  const char *insert_str = "World!";
  size_t start_index = 7;
  char *result = s21_insert(original, insert_str, start_index);

  const char *expected = "Hello, World!";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_insert_empty_original) {
  const char *original = "";
  const char *insert_str = "Hello, World!";
  size_t start_index = 0;
  char *result = s21_insert(original, insert_str, start_index);

  const char *expected = "Hello, World!";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_insert_empty_insert_str) {
  const char *original = "Hello, World!";
  const char *insert_str = "";
  size_t start_index = 7;
  char *result = s21_insert(original, insert_str, start_index);

  const char *expected = "Hello, World!";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_insert_at_end_empty_insert_str) {
  const char *original = "Hello, World!";
  const char *insert_str = "";
  size_t start_index = 12;
  char *result = s21_insert(original, insert_str, start_index);

  const char *expected = "Hello, World!";
  ck_assert_str_eq(result, expected);
}
END_TEST

Suite *insert_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("insert");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_insert_basic);
  tcase_add_test(tc_core, test_s21_insert_at_beginning);
  tcase_add_test(tc_core, test_s21_insert_at_end);
  tcase_add_test(tc_core, test_s21_insert_empty_original);
  tcase_add_test(tc_core, test_s21_insert_empty_insert_str);
  tcase_add_test(tc_core, test_s21_insert_at_end_empty_insert_str);

  suite_add_tcase(s, tc_core);

  return s;
}
