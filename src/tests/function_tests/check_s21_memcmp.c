//
// Created by Mi on 02.01.2024.
//

#include "check_s21_memcmp.h"

#include <string.h>

#include "../../s21_string.h"
#include "../common.h"

START_TEST(test_equal_strings) {
  const char *str1 = "Hello, World!";
  const char *str2 = "Hello, World!";

  ck_assert_int_eq(s21_memcmp(str1, str2, strlen(str1)),
                   memcmp(str1, str2, strlen(str1)));
}
END_TEST

START_TEST(test_unequal_strings) {
  const char *str1 = "Hello, World!";
  const char *str2 = "Goodbye, World!";

  ck_assert_int_eq(s21_memcmp(str1, str2, strlen(str1)),
                   memcmp(str1, str2, strlen(str1)));
}
END_TEST

START_TEST(test_partial_equal_strings) {
  const char *str1 = "Hello, World!";
  const char *str2 = "Hello, Universe!";

  ck_assert_int_eq(s21_memcmp(str1, str2, 7), memcmp(str1, str2, 7));
}
END_TEST

START_TEST(test_different_lengths) {
  const char *str1 = "Hello";
  const char *str2 = "Hello, World!";

  ck_assert_int_eq(s21_memcmp(str1, str2, strlen(str1)),
                   memcmp(str1, str2, strlen(str1)));
}
END_TEST

START_TEST(test_different_characters) {
  const char *str1 = "abc";
  const char *str2 = "def";

  ck_assert(s21_memcmp(str1, str2, strlen(str1)) < 0);
}
END_TEST

START_TEST(test_equal_empty_strings) {
  const char *str1 = "";
  const char *str2 = "";

  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
}
END_TEST

START_TEST(test_unequal_empty_and_nonempty_strings) {
  const char *str1 = "";
  const char *str2 = "Hello";

  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str2, str1, 0), memcmp(str2, str1, 0));
}
END_TEST

Suite *memcmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memcmp");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_equal_strings);
  tcase_add_test(tc_core, test_unequal_strings);
  tcase_add_test(tc_core, test_partial_equal_strings);
  tcase_add_test(tc_core, test_different_lengths);
  tcase_add_test(tc_core, test_different_characters);
  tcase_add_test(tc_core, test_equal_empty_strings);
  tcase_add_test(tc_core, test_unequal_empty_and_nonempty_strings);

  suite_add_tcase(s, tc_core);

  return s;
}