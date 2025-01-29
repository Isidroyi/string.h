//
// Created by Mi on 03.01.2024.
//

#include "check_s21_strncat.h"

#include <string.h>

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_normal_string) {
  char s21_destination[100] = "Hello, World!";
  char destination[100] = "Hello, World!";

  ck_assert_str_eq(
      s21_strncat(s21_destination, normal_string, strlen(s21_destination)),
      strncat(destination, normal_string, strlen(destination)));
}

END_TEST

START_TEST(test_empty_dist) {
  ck_assert_str_eq(s21_strncat("", normal_string, strlen("")),
                   strncat("", normal_string, strlen("")));
}

END_TEST

START_TEST(test_empty_src) {
  char *str1 = "Hello, World!";
  char *str2 = "Hello, World!";

  ck_assert_str_eq(s21_strncat(str1, "", strlen("")),
                   strncat(str2, "", strlen("")));
}

END_TEST

END_TEST

START_TEST(test_large_string) {
  char s21_destination[1000] = "Hello, World!";
  char desitnation[1000] = "Hello, World!";

  ck_assert_str_eq(
      s21_strncat(s21_destination, large_string, strlen(s21_destination)),
      strncat(desitnation, large_string, strlen(desitnation)));
}
END_TEST

START_TEST(test_strncat_zero_length) {
  char str1[] = "Hello, ";
  const char str2[] = "World!";

  ck_assert_str_eq(s21_strncat(str1, str2, 0), str1);
}
END_TEST

START_TEST(test_strncat_partial_src) {
  char s21_destination[100] = "Hello, ";
  char destination[100] = "Hello, ";
  const char partial_src[] = "Beautiful Day!";

  ck_assert_str_eq(s21_strncat(s21_destination, partial_src, 5),
                   strncat(destination, partial_src, 5));
}
END_TEST

Suite *strncat_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncat");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_normal_string);
  tcase_add_test(tc_core, test_empty_dist);
  tcase_add_test(tc_core, test_empty_src);
  tcase_add_test(tc_core, test_large_string);
  tcase_add_test(tc_core, test_strncat_zero_length);
  tcase_add_test(tc_core, test_strncat_partial_src);

  suite_add_tcase(s, tc_core);

  return s;
}