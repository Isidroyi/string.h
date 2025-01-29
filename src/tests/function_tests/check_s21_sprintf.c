#include "check_s21_sprintf.h"

#include <limits.h>
#include <stdio.h>

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_sprintf_integer) {
  char s21_buffer[20];
  char buffer[20];
  int num = 42;

  int result_s21 = s21_sprintf(s21_buffer, "%d", num);
  int result_sprintf = sprintf(buffer, "%d", num);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_float) {
  char s21_buffer[20];
  char buffer[20];
  float num = 3.14;

  int result_s21 = s21_sprintf(s21_buffer, "%.2f", num);
  int result_sprintf = sprintf(buffer, "%.2f", num);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_string) {
  char s21_buffer[20];
  char buffer[20];
  const char *str = "Hello, World!";

  int result_s21 = s21_sprintf(s21_buffer, "%s", str);
  int result_sprintf = sprintf(buffer, "%s", str);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_multiple_values) {
  char s21_buffer[50];
  char buffer[50];
  int num = 42;
  const char *str = "ABC";

  int result_s21 = s21_sprintf(s21_buffer, "Number: %d, String: %s", num, str);
  int result_sprintf = sprintf(buffer, "Number: %d, String: %s", num, str);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_c_specifier) {
  char s21_buffer[20];
  char buffer[20];
  char character = '!';

  int result_s21 = s21_sprintf(s21_buffer, "%c", character);
  int result_sprintf = sprintf(buffer, "%c", character);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_u_specifier) {
  char s21_buffer[20];
  char buffer[20];
  unsigned int num = UINT_MAX;

  int result_s21 = s21_sprintf(s21_buffer, "%u", num);
  int result_sprintf = sprintf(buffer, "%u", num);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_positive_integer_with_plus_flag) {
  char s21_buffer[20];
  char buffer[20];
  int num = 42;

  int result_s21 = s21_sprintf(s21_buffer, "%+d", num);
  int result_sprintf = sprintf(buffer, "%+d", num);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_negative_integer_with_plus_flag) {
  char s21_buffer[20];
  char buffer[20];
  int num = -42;

  int result_s21 = s21_sprintf(s21_buffer, "%+d", num);
  int result_sprintf = sprintf(buffer, "%+d", num);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_negative_integer_with_space_flag) {
  char s21_buffer[20];
  char buffer[20];
  int num = -42;

  int result_s21 = s21_sprintf(s21_buffer, "% d", num);
  int result_sprintf = sprintf(buffer, "% d", num);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_positive_float_with_plus_flag) {
  char s21_buffer[20];
  char buffer[20];
  float num = 3.14;

  int result_s21 = s21_sprintf(s21_buffer, "%+.2f", num);
  int result_sprintf = sprintf(buffer, "%+.2f", num);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_negative_float_with_plus_flag) {
  char s21_buffer[20];
  char buffer[20];
  float num = -3.14;

  int result_s21 = s21_sprintf(s21_buffer, "%+.2f", num);
  int result_sprintf = sprintf(buffer, "%+.2f", num);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_align_left_with_minus_flag) {
  char s21_buffer[20];
  char buffer[20];
  const char *str = "ABC";

  int result_s21 = s21_sprintf(s21_buffer, "%-15s", str);
  int result_sprintf = sprintf(buffer, "%-15s", str);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_width_description) {
  char s21_buffer[20];
  char buffer[20];
  int num = 42;

  int result_s21 = s21_sprintf(s21_buffer, "%5d", num);
  int result_sprintf = sprintf(buffer, "%5d", num);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_precision_description) {
  char s21_buffer[20];
  char buffer[20];
  float num = 3.14159;

  int result_s21 = s21_sprintf(s21_buffer, "%.2f", num);
  int result_sprintf = sprintf(buffer, "%.2f", num);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_width_and_precision_description) {
  char s21_buffer[20];
  char buffer[20];
  float num = 123.456;

  int result_s21 = s21_sprintf(s21_buffer, "%8.2f", num);
  int result_sprintf = sprintf(buffer, "%8.2f", num);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_length_description) {
  char s21_buffer[20];
  char buffer[20];
  long long_num = LONG_MAX;

  int result_s21 = s21_sprintf(s21_buffer, "%ld", long_num);
  int result_sprintf = sprintf(buffer, "%ld", long_num);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_h_length_integer) {
  char s21_buffer[20];
  char buffer[20];
  short num = 32767;

  int result_s21 = s21_sprintf(s21_buffer, "%hd", num);
  int result_sprintf = sprintf(buffer, "%hd", num);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_h_length_unsigned_integer) {
  char s21_buffer[20];
  char buffer[20];
  unsigned short num = 65535;

  int result_s21 = s21_sprintf(s21_buffer, "%hu", num);
  int result_sprintf = sprintf(buffer, "%hu", num);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_print_percent) {
  char s21_buffer[20];
  char buffer[20];
  float num1 = 3.1415;
  int num2 = 123;
  const char *str = "ABC";

  int result_s21 = s21_sprintf(s21_buffer, "%.2f : %d : %s", num1, num2, str);
  int result_sprintf = sprintf(buffer, "%.2f : %d : %s", num1, num2, str);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_sprintf_zero_precision_description) {
  char s21_buffer[20];
  char buffer[20];
  float num = 3.14159;

  int result_s21 = s21_sprintf(s21_buffer, "%0.f", num);
  int result_sprintf = sprintf(buffer, "%0.f", num);

  ck_assert_int_eq(result_s21, result_sprintf);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

Suite *sprintf_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sprintf");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_sprintf_integer);
  tcase_add_test(tc_core, test_sprintf_float);
  tcase_add_test(tc_core, test_sprintf_string);
  tcase_add_test(tc_core, test_sprintf_multiple_values);
  tcase_add_test(tc_core, test_sprintf_c_specifier);
  tcase_add_test(tc_core, test_sprintf_positive_integer_with_plus_flag);
  tcase_add_test(tc_core, test_sprintf_negative_integer_with_plus_flag);
  tcase_add_test(tc_core, test_sprintf_negative_integer_with_space_flag);
  tcase_add_test(tc_core, test_sprintf_positive_float_with_plus_flag);
  tcase_add_test(tc_core, test_sprintf_negative_float_with_plus_flag);
  tcase_add_test(tc_core, test_sprintf_align_left_with_minus_flag);
  tcase_add_test(tc_core, test_sprintf_width_description);
  tcase_add_test(tc_core, test_sprintf_precision_description);
  tcase_add_test(tc_core, test_sprintf_width_and_precision_description);
  tcase_add_test(tc_core, test_sprintf_length_description);
  tcase_add_test(tc_core, test_sprintf_h_length_integer);
  tcase_add_test(tc_core, test_sprintf_h_length_unsigned_integer);
  tcase_add_test(tc_core, test_sprintf_print_percent);
  tcase_add_test(tc_core, test_sprintf_zero_precision_description);
  tcase_add_test(tc_core, test_sprintf_u_specifier);

  suite_add_tcase(s, tc_core);

  return s;
}